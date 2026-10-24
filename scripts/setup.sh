#!/usr/bin/env bash
set -euo pipefail
ROOT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

if [[ ! -r /etc/os-release ]]; then
    echo "Ubuntu 24.04에서 실행하세요." >&2
    exit 1
fi
source /etc/os-release
if [[ "$ID" != ubuntu || "$VERSION_ID" != 24.04 ]]; then
    echo "검증 대상은 Ubuntu 24.04입니다: $PRETTY_NAME" >&2
    exit 1
fi

packages=(build-essential g++-13 cmake ninja-build gdb git pkg-config libncurses-dev)
missing=()
for package in "${packages[@]}"; do
    if ! dpkg-query -W -f='${Status}' "$package" 2>/dev/null | grep -q 'install ok installed'; then
        missing+=("$package")
    fi
done
if (( ${#missing[@]} )); then
    if (( EUID == 0 )); then
        apt-get update
        DEBIAN_FRONTEND=noninteractive apt-get install -y "${missing[@]}"
    else
        sudo apt-get update
        sudo env DEBIAN_FRONTEND=noninteractive apt-get install -y "${missing[@]}"
    fi
fi

for tool in cmake ninja g++-13; do
    "$tool" --version
done
for preset in linux-debug linux-release; do
    cmake --preset "$preset"
    cmake --build --preset "$preset" --parallel 2
    ctest --preset "$preset"
done
printf '\n설정·빌드·테스트 완료. 실행 파일: %s/out/build/linux-debug/bin\n' "$ROOT_DIR"
