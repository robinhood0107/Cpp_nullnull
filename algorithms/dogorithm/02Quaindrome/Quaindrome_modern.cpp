// POSIX에서는 mmap을 사용하고 Windows에서는 표준 입출력으로 읽는다.

#ifndef _WIN32
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#include <cstdio>

#include <cerrno>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>
#include <string_view>
#include <vector>

class FastInput {
public:
    FastInput() { init(); }

    ~FastInput() {
        #ifndef _WIN32
        if (mapped_ && mapped_ptr_ != nullptr && mapped_size_ > 0) {
            munmap(mapped_ptr_, mapped_size_);
        }
        #endif
    }

    bool read_int(int& out) {
        skip_non_digit();
        if (cur_ >= end_) return false;

        int value = 0;
        while (cur_ < end_ && *cur_ >= '0' && *cur_ <= '9') {
            value = value * 10 + (*cur_ - '0');
            ++cur_;
        }
        out = value;
        return true;
    }

    bool read_line(std::string_view& line) {
        if (cur_ >= end_) return false;

        const char* start = cur_;
        while (cur_ < end_ && *cur_ != '\n') ++cur_;
        const char* finish = cur_;

        if (cur_ < end_ && *cur_ == '\n') ++cur_;
        if (finish > start && *(finish - 1) == '\r') --finish;

        line = std::string_view(start, static_cast<std::size_t>(finish - start));
        return true;
    }

    void consume_line_end() {
        while (cur_ < end_ && (*cur_ == ' ' || *cur_ == '\t' || *cur_ == '\r')) ++cur_;
        if (cur_ < end_ && *cur_ == '\n') ++cur_;
    }

private:
    void init() {
        #ifndef _WIN32
        struct stat st {};
        if (fstat(STDIN_FILENO, &st) == 0 && S_ISREG(st.st_mode) && st.st_size > 0) {
            void* mapped = mmap(nullptr, static_cast<std::size_t>(st.st_size), PROT_READ, MAP_PRIVATE, STDIN_FILENO, 0);
            if (mapped != MAP_FAILED) {
                mapped_ = true;
                mapped_ptr_ = static_cast<char*>(mapped);
                mapped_size_ = static_cast<std::size_t>(st.st_size);
                cur_ = mapped_ptr_;
                end_ = mapped_ptr_ + mapped_size_;
                return;
            }
        }

        #endif
        // 파이프와 Windows 입력은 연속 버퍼에 저장한다.
        char chunk[1 << 16];
        while (true) {
            const std::size_t n = std::fread(chunk, 1, sizeof(chunk), stdin);
            if (n <= 0) break;
            storage_.insert(storage_.end(), chunk, chunk + n);
        }

        if (storage_.empty()) {
            cur_ = end_ = nullptr;
            return;
        }

        cur_ = storage_.data();
        end_ = storage_.data() + storage_.size();
    }

    void skip_non_digit() {
        while (cur_ < end_ && (*cur_ < '0' || *cur_ > '9')) ++cur_;
    }

private:
    bool mapped_ = false;
    char* mapped_ptr_ = nullptr;
    std::size_t mapped_size_ = 0;

    std::vector<char> storage_;
    const char* cur_ = nullptr;
    const char* end_ = nullptr;
};

class FastOutput {
public:
    explicit FastOutput(std::size_t reserve_size = 0) { buffer_.reserve(reserve_size); }

    void push_result(char c) {
        buffer_.push_back(c);
        buffer_.push_back('\n');
    }

    void flush() const {
        if (buffer_.empty()) return;
        (void)std::fwrite(buffer_.data(), 1, buffer_.size(), stdout);
    }

private:
    std::string buffer_;
};

static bool is_pal_range(std::string_view s, std::size_t l, std::size_t r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

// 1: palindrome, 2: quasi palindrome, 3: normal string
static char classify_line(std::string_view s) {
    if (s.size() < 2) return '1';

    const std::size_t hidx = 0;
    const std::size_t tidx = s.size() - 1;

    for (std::size_t i = 0; i < s.size() / 2; ++i) {
        if (s[hidx + i] == s[tidx - i]) continue;

        const bool remove_left = is_pal_range(s, hidx + i + 1, tidx - i);
        const bool remove_right = is_pal_range(s, hidx + i, tidx - i - 1);
        return (remove_left || remove_right) ? '2' : '3';
    }

    return '1';
}

int main() {
    FastInput in;

    int n = 0;
    if (!in.read_int(n)) return 0;
    in.consume_line_end();

    FastOutput out(static_cast<std::size_t>(n) * 2);
    for (int i = 0; i < n; ++i) {
        std::string_view line;
        if (!in.read_line(line)) break;
        out.push_result(classify_line(line));
    }

    out.flush();
    return 0;
}

