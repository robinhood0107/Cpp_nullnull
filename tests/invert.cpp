#include "../algorithms/dogorithm/18/invert.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

// 접미사 배열과 독립적으로 모든 길이와 시작점을 직접 비교한다.
InvertedRepeat reference(const std::string& s, int low, int high) {
    InvertedRepeat best;
    for (int size = 1; size * 2 + low <= static_cast<int>(s.size()); ++size) {
        std::unordered_map<std::string, std::vector<int>> positions;
        for (int j = 0; j + size <= static_cast<int>(s.size()); ++j)
            positions[s.substr(j, size)].push_back(j);
        InvertedRepeat current;
        for (int i = 0; i + size * 2 + low <= static_cast<int>(s.size()); ++i) {
            auto word = s.substr(i, size);
            std::reverse(word.begin(), word.end());
            auto found = positions.find(word);
            if (found == positions.end()) continue;
            const auto& starts = found->second;
            auto j = std::lower_bound(starts.begin(), starts.end(), i + size + low);
            if (j != starts.end() && *j <= i + size + high) {
                current = {i+1, i+size, *j+1, *j+size};
                break;
            }
        }
        if (!current.left_begin) break;
        best = current;
    }
    return best;
}

bool check(const std::string& s, int low, int high) {
    if (find_inverted_repeat(s, low, high) == reference(s, low, high)) return true;
    std::cerr << "완전 탐색과 불일치: " << s << ' ' << low << ' ' << high << '\n';
    return false;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    int count = 0;
    for (int size = 0; size <= 8; ++size) {
        for (int mask = 0; mask < (1 << size); ++mask) {
            std::string s(size, 'a');
            for (int i = 0; i < size; ++i) if (mask & (1 << i)) s[i] = 'c';
            for (int low = 0; low <= 4; ++low) {
                for (int high = low; high <= 5; ++high) {
                    if (!check(s, low, high)) return 1;
                    ++count;
                }
            }
        }
    }
    std::mt19937 random(18);
    for (int n = 0; n < 300; ++n) {
        std::string s(9 + random() % 55, 'a');
        for (char& c : s) c = "acgt"[random() % 4];
        const int low = random() % 10, high = low + random() % 15;
        if (!check(s, low, high)) return 1;
        ++count;
    }
    std::ifstream input(std::string(argv[1]) + "/S.txt");
    std::string s;
    if (!(input >> s)) return 1;
    for (auto sample : {"01", "02"}) {
        const std::string prefix = std::string(argv[1]) + "/" + sample;
        std::ifstream bounds(prefix + ".inp"), expected(prefix + ".verified.out");
        int low, high;
        InvertedRepeat result;
        if (!(bounds >> low >> high) || !(expected >> result.left_begin >> result.left_end
            >> result.right_begin >> result.right_end)) return 1;
        if (!check(s, low, high) || !(result == reference(s, low, high))) return 1;
    }
    std::cout << count << "개의 작은 입력과 원본 문자열 2개 범위의 독립 비교 통과\n";
}
