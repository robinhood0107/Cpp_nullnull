실습 093 - override (virtual function)
Requested files: main.cpp, Vehicle.hpp, Vehicle.cpp (다운로드)
제출 방식: 개인


목적

이 실습은 클래스의 상속과 virtual function 를 사용하는 연습을 합니다.



설명

여러분은 자동차 판매점 관리 프로그램을 만드는 H사의 프로젝트에 투입됐습니다.

업무 분장을 통해 여러분들은 H사의 자동차 객체를 디자인 하는 업무를 맡게됐습니다.



W&B를 위해 바로 업무 시작합시다. 스케치 수준에서 다음과 같은 클래스를 머리속으로 그려봅니다.

struct GV70 {

        void accelerate();

        void brake();

} ;

struct Grandeur {

        void accelerate();

        void brake();

} ;

struct Carnibal {

         void accelerate();

         void brake();

} ;



다음으로 화면에서 자동차 그림을 선택하면 자동차 객체를 반환하는 시나리오를 위해 make_vehicle() 함수를 디자인 합니다.

그런데 자동차 종류가 많다보니 함수의 반환값 결정이 어렵습니다.

' 음 ... 잘못된 선택은 optional<???> 하면 되는데... 자동차를 대표하는 뭔가가 필요한데... '




unique_ptr<???> make_vehicle() {

        std::string choice;

        cin >> choice;

        if (choice == "gv70") return make_unique<GV70>();

        else if (choice == "grandeur") return make_unique<Grandeur>();

         else if (choice == "carnibal") return make_unique<Carnibal>();

         else make_unique<GV70>();

}




판매점에서 시승차를 제공할 때 자동차 객체의 쓰임을 상상해 봅니다.

' 음... 시승차 목록을 만들고 관리하면 편한데... 어떻게 할까? 템플릿 쓰면 차량 종류별로 목록을 만들어야 할텐데... '

' 음 ... 시승차 속도 올리는 과정을 통일 시킬 수 없을까? 무슨 차든 자동차 속도 올리는 방법은 같도록... '



문제

자동차 객체를 디자인하는 여러분의 고민을 모두 해결할 수 있는 멋진 클래스들을 디자인 하시오.

고민1: make_vehicle() 함수의 리턴값을 결정하여 클래스 디자인에 반영해야 함.

고민2: 시승차 목록을 관리하기 위해 std::vector를 사용하기로 했다. 다양한 종류의 자동차를 담을 수 있도록 vector의 템플릿 타입을 결정해야 함.

고민3: 모든 자동차 클래스에 accelerate() 멤버 함수를 강제로 통일되게 사용하도록 하고, 자동차 객체 사용 시 자동차 종류에 따라 accelerate() 동작을 다르게 할 수 있도록 클래스를 디자인 해야 함.



입력

gv70

grandeur

carnibal





출력

The speed of the gv70 has increased by 30 km/h.

The speed of the grandeur has increased by 20 km/h.

The speed of the carnibal has increased by 10 km/h.



제출파일

Vehicle.hpp

Vehicle.cpp