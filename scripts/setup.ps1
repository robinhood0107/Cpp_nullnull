param(
    [ValidateSet('Debug', 'Release', 'Both')]
    [string]$Configuration = 'Both'
)
$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$root = Split-Path -Parent $PSScriptRoot
$OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new($false)
# 필수 실행 확장자는 현재 프로세스에만 보충한다.
$env:PATHEXT = '.COM;.EXE;.BAT;.CMD;' + $env:PATHEXT

function Invoke-Checked {
    param([string]$Program, [string[]]$Arguments)
    & $Program @Arguments
    if ($LASTEXITCODE -ne 0) { throw "$Program 실행 실패: 종료 코드 $LASTEXITCODE" }
}

# 일반 PowerShell에서도 MSVC를 찾도록 현재 프로세스의 환경만 설정한다.
$vswhere = Join-Path ${env:ProgramFiles(x86)} 'Microsoft Visual Studio\Installer\vswhere.exe'
if (-not (Test-Path $vswhere)) { throw 'VS2022 C++ 개발 도구를 설치하세요. docs/setup-windows.md 참고.' }
$installation = & $vswhere -latest -version '[17.0,18.0)' -products '*' -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $installation) { throw 'VS2022의 C++를 사용한 데스크톱 개발을 설치하세요. docs/setup-windows.md 참고.' }
$devcmd = Join-Path $installation 'Common7\Tools\VsDevCmd.bat'
$command = 'call "{0}" -no_logo -arch=x64 -host_arch=x64 >nul && set' -f $devcmd
$environmentLines = & $env:ComSpec /d /s /c $command
if ($LASTEXITCODE -ne 0) { throw 'MSVC 환경 초기화 실패. Windows SDK와 MSVC v143 설치를 확인하세요.' }
foreach ($line in $environmentLines) {
    $separator = $line.IndexOf('=')
    if ($separator -gt 0) {
        [Environment]::SetEnvironmentVariable($line.Substring(0, $separator), $line.Substring($separator + 1), 'Process')
    }
}
if ($env:VSCMD_ARG_TGT_ARCH -ne 'x64') { throw 'VS2022 x64 도구 환경을 준비하지 못했습니다.' }
Write-Host "도구: VS2022 $env:VSCMD_VER / 대상: $env:VSCMD_ARG_TGT_ARCH"
foreach ($tool in @('cl.exe', 'rc.exe', 'mt.exe', 'cmake.exe', 'ninja.exe', 'ctest.exe')) {
    if (-not (Get-Command $tool -ErrorAction SilentlyContinue)) {
        throw "$tool 없음. docs/setup-windows.md의 필수 구성 요소를 설치한 뒤 다시 실행하세요."
    }
}
Push-Location $root
try {
    Invoke-Checked 'cmake.exe' @('--version')
    Invoke-Checked 'ninja.exe' @('--version')
    $configurations = if ($Configuration -eq 'Both') { @('Debug', 'Release') } else { @($Configuration) }
    foreach ($item in $configurations) {
        $preset = 'windows-' + $item.ToLowerInvariant()
        Invoke-Checked 'cmake.exe' @('--preset', $preset)
        Invoke-Checked 'cmake.exe' @('--build', '--preset', $preset, '--parallel', '2')
        Invoke-Checked 'ctest.exe' @('--preset', $preset)
    }
    Write-Host "설정·빌드·테스트 완료: $root\out\build"
} finally { Pop-Location }
