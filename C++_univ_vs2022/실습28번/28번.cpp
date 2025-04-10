#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


int countCharacter(const std::string& str, char ch) {
    int count(0);
    for (auto it : str) {
        if (ch == it) count++;
    }
    return count;
    // implement your code
}



void toUpperCase(std::string& str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    // implement your code

    /*Output transform(
    //1 입력한 변수의 first 위치,
    //2 입력한 변수의 last 위치까지,
    //3 저장할 변수의 first 위치,
    //4 변환할 방법이 있는 함수);
    */
}



bool startsWith(const std::string_view str, const std::string_view prefix) {
    auto find_it = str.find(prefix);
    if (find_it == 0)
        return 1;
    else return 0;
    // implement your code

}


/*
int main() {

    std::vector<std::string> words = { "hello", "world", "example" };



    char characterToCount = 'l';

    for (const auto& word : words) {

        std::cout << "Count of '" << characterToCount << "' in \"" << word << "\": "

            << countCharacter(word, characterToCount) << std::endl;

    }

    std::cout << std::endl;



    for (auto& word : words) {

        toUpperCase(word);

        std::cout << "Modified string: " << word << std::endl;

    }

    std::cout << std::endl;



    std::string_view prefix = "EX";

    for (const auto& word : words) {

        std::cout << "Does \"" << word << "\" start with '" << prefix << "'? "

            << (startsWith(word, prefix) ? "Yes" : "No") << std::endl;

    }



    return 0;

}
*/
