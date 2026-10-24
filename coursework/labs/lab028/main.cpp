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
    //1 적용할 컨테이너의 begin(시작iterator),
    //2 적용할 컨테이너의 end(끝iterator),
    //3 결과를 저장할 컨테이너의 시작iterator,
    //4 적용할 함수(::toupper(대문자로 변경),::tolower(소문자로 변경),아니면 람다함수[](){return x;} 이거 써라 ));
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