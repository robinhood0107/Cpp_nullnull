#include <algorithm>
#include <iostream>
#include <vector>

struct Job {
    long long begin, end, profit;
};

struct Result {
    long long profit = 0, days = 0;
};

Result better(Result a, Result b) {
    if (a.profit != b.profit) return a.profit > b.profit ? a : b;
    return a.days < b.days ? a : b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<Job> jobs(n);
    for (auto& job : jobs) std::cin >> job.begin >> job.end >> job.profit;
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.end < b.end;
    });
    std::vector<long long> ends;
    for (const auto& job : jobs) ends.push_back(job.end);
    std::vector<Result> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        const auto& job = jobs[i];
        // 종료일과 시작일이 같으면 두 일정은 겹친다.
        const auto previous = std::lower_bound(ends.begin(), ends.begin() + i, job.begin) - ends.begin();
        Result chosen{job.profit, job.end - job.begin + 1};
        if (previous > 0) {
            chosen = better(chosen, {dp[previous].profit + job.profit - 10,
                                    dp[previous].days + job.end - job.begin + 1});
        }
        dp[i + 1] = better(dp[i], chosen);
    }
    std::cout << dp[n].profit << ' ' << dp[n].days << '\n';
}
