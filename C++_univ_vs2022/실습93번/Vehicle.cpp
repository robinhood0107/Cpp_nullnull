#include "Vehicle.hpp"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

void GV70::accelerate() {
        cout << "The speed of the gv70 has increased by 30 km/h." << endl;
}

void Grandeur::accelerate() {
        cout << "The speed of the grandeur has increased by 20 km/h." << endl;
}

void Carnibal::accelerate() {
        cout << "The speed of the carnibal has increased by 10 km/h." << endl;
}

unique_ptr<Vehicle> make_vehicle() {

        string choice;

        cin >> choice;

        if (choice == "gv70") return make_unique<GV70>();

        else if (choice == "grandeur") return make_unique<Grandeur>();

        else if (choice == "carnibal") return make_unique<Carnibal>();

        else return make_unique<GV70>();

}


//동적 다형성 설명

// 1. 다형성(Polymorphism)이란?
// 다형성은 "여러 가지 형태를 가질 수 있다"는 뜻입니다.
// C++에서 다형성은 같은 인터페이스(함수 이름)로 여러 객체가 각자 다르게 동작할 수 있게 해줍니다.

// 2. 정적 vs 동적 다형성
// 정적 다형성: 컴파일 타임에 결정(함수 오버로딩, 템플릿 등)
// 동적 다형성: 실행 시간에 결정(상속 + 가상 함수(virtual function) 사용)

// 동적 다형성의 핵심: 가상 함수(virtual function)
// 부모 클래스(기반 클래스)에 virtual로 선언된 함수가 있으면,
// 자식 클래스(파생 클래스)에서 같은 함수 이름으로 재정의(override)할 수 있습니다.
// 부모 클래스의 포인터(혹은 참조)로 자식 객체를 가리킬 때,
// 실제 객체 타입에 따라 재정의된 함수가 실행됩니다.

// 예제 코드

/*
(1) 추상 클래스와 가상 함수 (부모)
class Vehicle {
    virtual void accelerate() = 0; // 순수 가상 함수(= 추상 메서드)
    virtual ~Vehicle() = default;  // 가상 소멸자(중요!)
};

//설명

virtual void accelerate() = 0;
→ 이 함수는 "반드시 자식 클래스에서 구현해야 한다"는 뜻입니다.






(2) 자식 클래스에서 override
class GV70 : public Vehicle {
        void accelerate() override {
        std::cout << "The speed of the gv70 has increased by 30 km/h." << std::endl;
        }
};
//이렇게 자식클래스 생성자 만들 때 hpp 헤더파일에서 선언해 줄 수도 있음

//설명

override는 "부모의 virtual 함수를 재정의한다"는 의미입니다.
실수로 함수 이름이나 시그니처가 다르면 컴파일 에러가 나서, 실수를 방지해줍니다.
};






(3) 부모 클래스의 포인터로 자식 객체 가리키기 (=(3) 동적 다형성의 동작)
int main() {
        Vehicle* car = new GV70();
        car->accelerate(); // GV70의 accelerate()가 호출됨!
}

//설명

car는 Vehicle* 타입이지만, 실제로는 GV70 객체를 가리킵니다.
이때 car->accelerate()를 호출하면, GV70의 accelerate()가 실행됩니다.
이것이 동적 다형성입니다.
*/




// 3. 왜 동적 다형성이 필요한가?

// 여러 종류의 자동차(GV70, Grandeur, Carnibal 등)를 하나의 타입(Vehicle)로 관리할 수 있습니다.

/*
예를 들어, 자동차 목록을 만들 때:
std::vector<std::unique_ptr<Vehicle>> cars;
        cars.push_back(std::make_unique<GV70>());
        cars.push_back(std::make_unique<Grandeur>());
        cars.push_back(std::make_unique<Carnibal>());

그리고 반복문으로 모든 자동차의 accelerate를 호출할 수 있습니다:

for (auto& car : cars) {
      car->accelerate(); // 각 자동차에 맞는 accelerate()가 실행됨!
}
*/


// 4. override란?

// override는 부모 클래스의 virtual 함수를 "재정의"한다는 것을 명확히 표시하는 키워드입니다.

// 실수로 함수 이름이나 매개변수가 다르면 컴파일러가 에러를 내줍니다.

// 가독성, 안전성 모두 좋아집니다.


// 5. 정리

// 동적 다형성: 부모 포인터로 자식 객체를 다루면서, 자식의 동작(함수)이 실행되는 것.
// virtual: 부모 클래스에서 "이 함수는 자식에서 다르게 동작할 수 있다"고 표시.
// override: 자식 클래스에서 "이 함수는 부모의 virtual 함수를 재정의한다"고 표시.