#include <iostream>
#include <vector>
#include <utility>

void init_board();
const std::vector<std::vector<int>>& get_board();

int count_full_lines();
void remove_full_lines();
std::vector<int> get_heights();
int find_spawn_x(const std::vector<std::pair<int, int>> &block);
int count_empty();

void print_board() {
    const auto& board = get_board();
    //std::cout << "Board:\n";
    for (const auto& row : board) {
        for (int cell : row) std::cout << (cell ? "■" : "□") << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int main() {
    init_board();

    // std::cout << "Tetris Board System (Board stored internally)\n";
    // std::cout << "1. Show board\n";
    // std::cout << "2. Count full lines\n";
    // std::cout << "3. Remove full lines\n";
    // std::cout << "4. Get column heights\n";
    // std::cout << "5. Count empty cells\n";
    // std::cout << "0. Exit\n";

    int cmd;
    while (true) {
        //std::cout << "\nEnter command: ";
        std::cin >> cmd;

        if (cmd == 0) break;

        switch (cmd) {
            case 1:
                print_board();
                break;
            case 2:
                std::cout << "Full lines: " << count_full_lines() << "\n";
                break;
            case 3:
                remove_full_lines();
                //std::cout << "After removing lines:\n";
                print_board();
                break;
            case 4: {
                auto h = get_heights();
                std::cout << "Heights: ";
                for (int val : h) std::cout << val << " ";
                std::cout << "\n";
                break;
            }
            case 5:
                std::cout << "Empty cells: " << count_empty() << "\n";
                break;
            default:
                std::cout << "Invalid command\n";
        }
    }

    return 0;
}
