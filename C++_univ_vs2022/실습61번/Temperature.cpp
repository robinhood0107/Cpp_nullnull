#include "Temperature.h"
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// Implement your code
Temperature::Temperature(double temp, SCALE scale) : temperature{ 0 }, scale{ SCALE::CELSIUS } {
    if (scale == SCALE::CELSIUS) {
        temperature = temp;
        //scale = SCALE::CELSIUS; 위에서 멤버변수의 초깃값을 지정했으니까 필요없다
    }
    else {
        temperature = temp;
        toFahrenheit();
        this->scale = SCALE::FAHRENHEIT; // 명시적으로 멤버 변수를 가리키는 것이 더 명확할 수 있습니다.
        //함수뒤에 const는 멤버변수를 변경하지 않겠다는 것이다 즉 void set(int x) const;에서 x만 쓰겠다는 소리
    }
}
//생성자는 타입이 없다!!!!!


Temperature Temperature::add(const Temperature& other) const {
    //내가 틀린 부분!!! -> Temperature add(const Temperature& other) const{} 에서 맨 뒤 const 빼먹고 Temperature add(const Temperature& other)라고만 적었다 이러면 안됨
    //무조건 객체에서 선언한것과 똑같이 적어줘야 한다.
    //이건 Temperaturetest.cpp에서 t1객체와 t2객체를 받아서 t3에 반환하겠다는 함수로 반환형식은 당연히 Temperature
    //위에서 생성자를 생성했기 때문에 함수 내부에서 Temperature 객체 만들어서 반환시켜버리면 된다.
    // Implement your code
    if (scale == other.scale) {
        Temperature test = temperature + other.temperature;
        test.scale = scale;
        return test;
    }
    else {
        if (scale == SCALE::CELSIUS) {
            Temperature test = temperature + other.toCelsius();
            test.scale = SCALE::CELSIUS;
            return test; //새 객체에 기존이 섭씨면 다른건 화씨니까 섭씨로 바꾸고 더해주기
        }
        else {
            Temperature test = temperature + other.toFahrenheit();
            test.scale = SCALE::FAHRENHEIT;
            return test; //새 객체에 기존이 화씨면 다른건 섭씨니까 화씨로 바꾸고 더해주기
        }
    }
}

double Temperature::toCelsius() const { //private이라서 반드시 클래스안의 함수에서만 호출!!!!!!!
    return (temperature - 32) / 1.8;
}

double Temperature::toFahrenheit() const {//private이라서 반드시 클래스안의 함수에서만 호출!!!!!!
    return (temperature * (1.8)) + 32;
}

std::string Temperature::print() const {
    stringstream ss;
    ss << fixed << setprecision(1) << temperature << " ";
    if (scale != SCALE::CELSIUS) {
        ss << "F" << std::endl;
    }
    else {
        ss << "C" << std::endl;
    }
    return ss.str();
    //이런식으로 
    /*
    stringstream ss;
    ss << ...

    ss.str();
    이런식으로 출력하는게 기본이다 이건 기억하자.
    */
}


/*
## 코딩 오답노트

**1. `Temperature::add` 함수 정의 시 `const` 키워드 누락**

* **발생 위치:** `Temperature.cpp` 파일 내 `Temperature Temperature::add(const Temperature& other)` 함수 정의 부분
* **실수 내용:** 클래스 선언 (`Temperature.h`)에서 `Temperature add(const Temperature& other) const;`와 같이 `const` 키워드를 사용하여 멤버 함수가 객체의 상태를 변경하지 않음을 명시했으나, 실제 함수를 정의하는 `Temperature.cpp` 파일에서 `const` 키워드를 누락함.
* **오답노트:** 클래스 선언 시 `const`로 선언된 멤버 함수는 정의 시에도 **반드시** `const` 키워드를 포함해야 합니다. 이는 함수가 객체의 멤버 변수를 수정하지 않겠다는 약속이며, 컴파일러가 이를 확인합니다.

    **수정 전:**
    ```cpp
    // Temperature Temperature::add(const Temperature& other) { ... }
    ```

    **수정 후:**
    ```cpp
    // Temperature Temperature::add(const Temperature& other) const { ... }
    ```
*/





/*
**2. `Temperature::print` 함수에서 반환 값 누락**

* **발생 위치:** `Temperature.cpp` 파일 내 `std::string Temperature::print() const` 함수 정의 부분
* **실수 내용:** 함수가 `std::string` 타입의 값을 반환하도록 선언되었으나, `stringstream` 객체에 결과를 저장한 후 `ss.str();`을 호출만 하고 실제 값을 `return` 하지 않음.
* **오답노트:** 값을 반환하도록 정의된 함수는 **반드시** `return` 문을 사용하여 해당 타입의 값을 반환해야 합니다. `stringstream::str()`은 `stringstream` 객체에 담긴 문자열을 복사하여 반환하므로, 이 값을 `return` 해야 합니다.

    **수정 전:**
    ```cpp
    // std::string Temperature::print() const {
    //     std::stringstream ss;
    //     ss << ~~~~~
    //     ss.str(); // 반환하지 않고 버려짐
    // }
```

** 수정 후 : **
```cpp
// std::string Temperature::print() const {
//     std::stringstream ss;
//     ss << ~~~~~;
//     return ss.str(); // 생성된 문자열을 반환
// }
```
*/





/*
** 3. 생성자 내 불필요한 `scale` 멤버 변수 재할당 * *

***발생 위치 : **`Temperature.cpp` 파일 내 `Temperature::Temperature(double temp, SCALE scale)` 생성자 정의 부분
* **실수 내용 : **생성자의 초기화 리스트에서 이미 `scale` 멤버 변수를 초기화했음에도 불구하고, `if` 조건문 내부에서 다시 `scale`에 값을 할당함.이는 불필요한 동작이며, 컴파일러 경고를 발생시킴.
*** 오답노트:**생성자의 초기화 리스트에서 멤버 변수를 초기화하면, 생성자 본체에서는 필요한 경우에만 값을 변경해야 합니다.초기화 리스트에서 이미 값을 설정했다면, 조건에 따라 다른 값을 할당할 때만 명시적으로 멤버 변수에 접근하여 값을 변경해야 합니다.

** 수정 전 : **
```cpp
// Temperature::Temperature(double temp, SCALE scale) : temperature(0), scale(SCALE::CELSIUS) {
//     if (scale == SCALE::CELSIUS) {
//         temperature = temp;
//         scale = SCALE::CELSIUS; // 불필요한 재할당
//     } else {
//         temperature = temp;
//         toFahrenheit();
//         scale = SCALE::FAHRENHEIT; // 불필요한 재할당
//     }
// }
```

** 수정 후 : **
```cpp
// Temperature::Temperature(double temp, SCALE scale) : temperature(temp) {
//     if (scale == SCALE::CELSIUS) {
//         this->scale = SCALE::CELSIUS; // 초기화 리스트에서 기본값이 설정되었으므로 필요 없을 수도 있음
//     } else {
//         toFahrenheit();
//         this->scale = SCALE::FAHRENHEIT;
//     }
// }
```
*/