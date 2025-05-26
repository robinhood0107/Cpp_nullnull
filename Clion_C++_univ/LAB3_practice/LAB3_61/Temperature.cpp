#include "Temperature.h"
#include <sstream>
#include <iomanip>

// Implement your code

Temperature::Temperature(double temp, SCALE scale): temperature{temp}{
    //항상 주의해야 하는 것이 이렇게 초기화 리스트 방식의 초기화는 디폴트 생성자만 가능함.
    //초기화 리스트로 인해서 temperature{temp}은 항상 제일 먼저 무조건 이루어짐(그니까 if 문에서 다시 한번 안해도 됨)
    if (scale == SCALE::FAHRENHEIT) {
        this->scale = SCALE::FAHRENHEIT;
    }
    else {
        this->scale = SCALE::CELSIUS;
    }
    //여기서 열거형 무조건 지정해야 함.
}
Temperature Temperature::add(const Temperature& other) const {
    if (scale == other.scale) {
        //반환 값이 객체니까 인스턴스 새로 하나 생성해주면 됨
        Temperature temp{temperature + other.temperature, other.scale};
        return temp;
    }
    else{
        if (scale == SCALE::CELSIUS) {
            //이런식으로 빠르게 temp라는 객체 선언해서 디폴트 생성자 만들어주기 및 초기화
            Temperature temp{temperature + other.toCelsius(), SCALE::CELSIUS};
            return temp;
        }
        else if (scale == SCALE::FAHRENHEIT) {
            Temperature temp{temperature + other.toFahrenheit(), SCALE::FAHRENHEIT};
            return temp;
        }
    }
}
std::string Temperature::print() const {
    //stringstream 이렇게 하면 되니까 이대로 알고 가기
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << this->temperature;
    if (this->scale == SCALE::CELSIUS) {
        ss << " C\n";
    }
    else if (this->scale == SCALE::FAHRENHEIT) {
        ss << " F\n";
    }
    return ss.str();
}


double Temperature::toCelsius() const {
    return (temperature - 32)*5/9;
}
double Temperature::toFahrenheit() const {
    return (temperature*9/5) + 32;
}
