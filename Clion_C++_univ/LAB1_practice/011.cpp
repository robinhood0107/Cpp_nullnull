//
// Created by pjjpj on 25. 4. 1.
//
/*
*Goal
Write a program that calculates the total gold a player has in a game by adding the base gold (fixed at 1000) and the
additional gold earned from defeating minions (minion gold). Then, compute the average gold and display the appropriate message based on the value.

The average gold is calculated by dividing the total gold by 2. - If the average gold is 2000 or higher, print "Item purchase available".
- Otherwise, print "More gold needed".

Concept Explanation
This problem helps you practice fundamental C++ data types and control structures, including:

Integer (int): Gold values are handled as integers.
Floating-point number (float): Used for calculating the average gold.
Boolean condition (bool): Determines whether the player has enough average gold to purchase an item.
Additionally, since division is involved, type conversion should be considered to ensure accurate floating-point calculations.

?ㅼ뼇???낆텧??manipulators
std::fixed
std::setprecision
Constraints
The base gold (baseGold) must be defined as a constant (const int) with a value of 1000.
The minion gold (minionGold) can be negative (in case of debuffs).
When calculating the average gold, type conversion should be applied to ensure accurate floating-point division.
Hint: To ensure the average gold is displayed with exactly two decimal places, you can use std::fixed and std::setprecision(2) from the <iomanip> library.

Submission Files
main.cpp
Input/Output Example
Input	Output
2500	Total Gold: 3500
        Average Gold: 1750.00
        More gold needed
3000	Total Gold: 4000
        Average Gold: 2000.00
        Item purchase available

 */

//諛섎뱶??紐낆떖??寃?= static_cast?좊븣 愿꾪샇 瑗??⑤씪
//iomanip ?먭씀 泥좎옄 源뚮㉨?붾떎 ?ㅼ떆?쒕쾲 瑗??몄슦湲?
//洹몃━怨?precision 泥좎옄 議곗떖
#include <iostream>
#include <iomanip>
using namespace std;

int p011() {
    int gold;
    float avg;
    const int basegold = 1000;

    cin >> gold;
    avg = static_cast<float> ((basegold+gold)/2);
    cout << "Total Gold: " << basegold+gold << endl;
    cout << "Average Gold: " << fixed << setprecision(2) << avg <<endl;
    if (avg >= 2000)
        cout << "Item purchase available";
    else
        cout << "More gold needed";

}
