#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int width, height;
    if (!(std::cin >> width >> height)) return 0;
    std::vector<std::vector<int>> box(height, std::vector<int>(width));
    std::queue<std::pair<int, int>> ripe;
    int remaining = 0;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cin >> box[y][x];
            if (box[y][x] == 1) ripe.emplace(y, x);
            else if (box[y][x] == 0) ++remaining;
        }
    }
    constexpr int dy[] = {1, -1, 0, 0};
    constexpr int dx[] = {0, 0, 1, -1};
    int days = 0;
    while (!ripe.empty()) {
        const auto [y, x] = ripe.front();
        ripe.pop();
        for (int direction = 0; direction < 4; ++direction) {
            const int ny = y + dy[direction], nx = x + dx[direction];
            if (ny < 0 || ny >= height || nx < 0 || nx >= width || box[ny][nx] != 0) continue;
            box[ny][nx] = box[y][x] + 1;
            days = std::max(days, box[ny][nx] - 1);
            --remaining;
            ripe.emplace(ny, nx);
        }
    }
    std::cout << (remaining == 0 ? days : -1) << '\n';
}
