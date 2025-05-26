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
            //current에 step_을 더해줌
            //그리고 자기 자신 출력
            current_+=step_;
            return *this;
        }

        Iterator operator++(int) {
            //Implement your code
            //int앞에 붙는 전치 ++의 경우 이렇게 작성한다 이거 꼭 외우고 있으셈
            // 이거는 자료형식이 그냥 객체라 임시 객체 temp 선언해서 출력하자
            Iterator temp(*this); //this라는 내 객체를 복사한 this(나)의 복사 생성자 호출하는 인스턴스(객체) temp
            current_+=step_;
            return *this;
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