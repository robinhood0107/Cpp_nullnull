#include <windows.h>

namespace {
struct ConsoleEncoding {
    ConsoleEncoding() {
        DWORD mode;
        // 파일·파이프 입출력은 그대로 두고 실제 콘솔에만 적용한다.
        if (GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode)) SetConsoleCP(CP_UTF8);
        if (GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode) ||
            GetConsoleMode(GetStdHandle(STD_ERROR_HANDLE), &mode)) SetConsoleOutputCP(CP_UTF8);
    }
};
const ConsoleEncoding encoding;
}
