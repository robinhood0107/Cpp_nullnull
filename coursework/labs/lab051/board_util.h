#ifndef BOARD_UTIL_H
#define BOARD_UTIL_H

#include <vector>
#include <utility>

void init_board();
const std::vector<std::vector<int>>& get_board();

int count_full_lines();
void remove_full_lines();
std::vector<int> get_heights();
int find_spawn_x(const std::vector<std::pair<int, int>> &block);
int count_empty();

#endif // BOARD_UTIL_H