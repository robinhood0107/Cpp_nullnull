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
            return current_;
        }

        Iterator& operator++() {
            //Implement your code
            current_+=step_;
		    return *this;
        }

        Iterator operator++(int) {
            //Implement your code
            Iterator temp(*this); //temp라는 복사생성자 인스턴스 temp 생성
    		current_+=step_;
    		return temp;
        }

        bool operator!=(const Iterator& other) const {
            //Implement your code
            if (step_ > 0)
                return current_ < stop_;
            else if (step_ < 0)
                return current_ > stop_;

            return false; // step_ == 0 등 모든 나머지 경우

            // 내가 틀린 부분:  여기서 return이 없는 경우가 있음!
            // 가장 대표적이고 너가 반드시 고려해야 하는게 만약 step_ == 0인 경우, 위의 if, else if 모두 해당하지 않음 
        }

        bool operator==(const Iterator& other) const {
            //Implement your code
            if (step_ == 0)
                return current_ == stop_;
            else
                return false;
            //내가 틀린 부분: 모던 C++ 규칙) 어떤 경우에도 항상 값을 반환해야 하는 규칙
            //모든 경로에서 return이 보장되어야 하므로, 마지막에 return false;를 추가하는 것이 가장 안전하고 명확한 C++ 스타일 (그니까 걍 if문에 return 하고 끝나면 안됨 else도 반드시 생각해야지;
        }
    };

    explicit Range(long long stop);
    Range(long long start, long long stop);
    Range(long long start, long long stop, long long step);

    [[nodiscard]] Iterator begin() const;
    [[nodiscard]] Iterator end() const;

};

#endif // RANGE_H