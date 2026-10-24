#pragma once
#include <string>

struct InvertedRepeat {
    int left_begin = 0;
    int left_end = 0;
    int right_begin = 0;
    int right_end = 0;
    bool operator==(const InvertedRepeat&) const = default;
};

InvertedRepeat find_inverted_repeat(const std::string& sequence, int minimum_gap, int maximum_gap);
