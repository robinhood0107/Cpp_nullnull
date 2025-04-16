#ifndef BMI_H
#define BMI_H

#include <vector>

bool addBMI(std::vector<int>& bmis, int weight, int height);
bool displayBMIs(const std::vector<int>& bmis);
bool deleteByValue(std::vector<int>& bmis, int value);

#endif // BMI_H