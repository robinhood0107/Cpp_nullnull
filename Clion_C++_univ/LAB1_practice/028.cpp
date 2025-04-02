//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int countCharacter(const std::string& str, char ch) {

    // implement your code
    int count=0;
    for(const auto& lt: str){
      if(lt == ch){
        count++;
        }
      }
    return count;
}




void toUpperCase(std::string& str) {
    //이거 그냥 암기
    transform(str.begin(),str.end(),str.begin,toupper);
    //시작,끝,저장장소(보통 begin) toupper 함수
    // implement your code

}



bool startsWith(const std::string_view str, const std::string_view prefix) {
    auto find_it = str.find(prefix);
    if (find_it == 0)
        return 1;
    else return 0;
}



int main() {

    std::vector<std::string> words = {"hello", "world", "example"};



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
