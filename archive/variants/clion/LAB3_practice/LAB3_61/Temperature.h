#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <string>

enum class SCALE {
    CELSIUS,
    FAHRENHEIT
};

class Temperature {
public:
    Temperature(double temp, SCALE scale = SCALE::CELSIUS);
    Temperature add(const Temperature& other) const;
    std::string print() const;

private:
    double temperature;
    SCALE scale;

    double toCelsius() const;
    double toFahrenheit() const;
};

#endif // TEMPERATURE_H
