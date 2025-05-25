#ifndef RANGE_H
#define RANGE_H

class Range {
private:
    long long start_; // 시작 값
    long long stop_;  // 종료 값 (포함되지 않음)
    long long step_;  // 증가/감소 값

public:
    class Iterator {
    private:
        long long current_; // 현재 값
        long long step_;    // 증가/감소 값
        long long stop_;    // 종료 값 (비교용)

    public:
        Iterator(long long current, long long step, long long stop)
            : current_(current), step_(step), stop_(stop) {}

        long long operator*() const {
            //Implement your code
        }

        Iterator& operator++() {
            //Implement your code
        }

        Iterator operator++(int) {
            //Implement your code
        }

        bool operator!=(const Iterator& other) const {
            //Implement your code
        }

        bool operator==(const Iterator& other) const {
            //Implement your code
        }
    };

    explicit Range(long long stop);
    Range(long long start, long long stop);
    Range(long long start, long long stop, long long step);

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator end() const;

};

#endif // RANGE_H