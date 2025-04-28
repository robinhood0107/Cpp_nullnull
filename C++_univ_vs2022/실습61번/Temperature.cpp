#include "Temperature.h"
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

// Implement your code
Temperature::Temperature(double temp, SCALE scale) : temperature(0), scale(SCALE::CELSIUS) {
    if (scale == SCALE::CELSIUS) {
        temperature = temp;
        scale = SCALE::CELSIUS;
    }
    else {
        temperature = temp;
        toFahrenheit();
        scale = SCALE::FAHRENHEIT;
        //함수뒤에 const는 멤버변수를 변경하지 않겠다는 것이다 즉 void set(int x) const;에서 x만 쓰겠다는 소리
    }
}
//생성자는 타입이 없다!!!!!





Temperature Temperature::add(const Temperature& other) const{ 
    //내가 틀린 부분!!! -> Temperature add(const Temperature& other) const{} 에서 맨 뒤 const 빼먹고 Temperature add(const Temperature& other)라고만 적었다 이러면 안됨
    //무조건 객체에서 선언한것과 똑같이 적어줘야 한다.
    //이건 Temperaturetest.cpp에서 t1객체와 t2객체를 받아서 t3에 반환하겠다는 함수로 반환형식은 당연히 Temperature
    //함수 내부에서 Temperature 객체 만들어서 반환시켜버리면 된다.
    // Implement your code
    Temperature test;
    test.temperature = 0;
    if (scale == other.scale) {
        test.temperature = temperature + other.temperature;
        return test;
    }
    else {
        if (scale == SCALE::CELSIUS) {
            test.temperature = temperature + other.toCelsius();
            test.scale = scale;
            return test; //새 객체에 기존이 섭씨면 다른건 화씨니까 섭씨로 바꾸고 더해주기
        }
        else {
            test.temperature = temperature + other.toFahrenheit();
            test.scale = scale;
            return test; //새 객체에 기존이 화씨면 다른건 섭씨니까 화씨로 바꾸고 더해주기
        }
    }
}

double Temperature::toCelsius() const{ //private이라서 반드시 클래스안의 함수에서만 호출!!!!!!!
    return (temperature - 32) / 1.8;
}

double Temperature::toFahrenheit() const {//private이라서 반드시 클래스안의 함수에서만 호출!!!!!!
    return (temperature * (1.8)) + 32;
}

std::string Temperature::print() const {
    stringstream ss;
    ss << fixed << setprecision(1) << temperature << " ";
    if (scale == SCALE::CELSIUS) {
        ss << "C" << std::endl;
    }
    else {
        ss << "F" << std::endl;
    }
    ss.str();
    //이런식으로 
    /*
    stringstream ss;
    ss << ...

    ss.str();
    이런식으로 출력하는게 기본이다 이건 기억하자.
    */
}