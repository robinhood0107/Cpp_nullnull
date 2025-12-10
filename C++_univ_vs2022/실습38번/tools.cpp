//Implement your code

#include "tools.h"
#include <sstream>
using namespace std;

void std_newline(string& text) {
    string newline;
    for (int i = 0; i < text.size(); ++i) {
        if (text[i] == '\r') {
            if (i + 1 < text.size() && text[i + 1] == '\n') {
                continue;
            }
            else {
                newline += '\n';
            }
        }
        else {
            newline += text[i];
        }
    }
    text = newline;
}

string show_chars(const string& str) {
    string s = "[";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '\r' || str[i] == '\n') {
            s += to_string(static_cast<int>(str[i]));
        }
        else {
            s += str[i];
        }
        if (i < str.size() - 1) {
            s += ",";
        }
    }
    s += "]";
    return s;
}
// s += to_string(static_cast<int>(str[i])) 이렇게 to_string함수를 이용해서 string으로 변환 가능.
/*
string show_chars(const string& str) {
    string s = "[";
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '\r') {
            s += "13";
        }
        else if (str[i] == '\n') {
            s += "10";
        }
        else {
            s += str[i];
        }
        if (i < str.size() - 1) {
            s += ",";
        }
    }
    s += "]";
    return s;
}
*/

string diff_output(const string& expected, const string& actual) {
    string result;
    if (expected != actual) {
        result = "P Output: " + show_chars(actual) + "\n";
        result += "E Output: " + show_chars(expected) + "\n";
    }
    return result;
}