#include <iostream>
#include <fstream>
#include <stdexcept>

// Implement your code

int main() {
    //try catch는 어디에다가 박는다고? 제일 마지막 main 전체에 박으면 됨
    try{
    std::ifstream fin;
    fin.open("input.txt");// This will not throw an exception even if file is missing
    //이건그냥 외운다고 생각하면 됨 ifstream에 포함되어 있는 exceptions 메소드 기능을 사용해서 std::ios_base::failbit랑 std::ios_base::badbit 상태를 넘겨줘 버릴 것
    fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    // 매우주의 (내가 틀린 부분) 철자 조심해라 exceptions다 복수 형태야!!!!!
    // 매우주의 ios_base 다 기억해 (반드시!!!) //그리고 catch로 받을때는 std::ios_base::failure
    // 매우주의 failbit fail비트, bad비트다 반드시 기억하셈 std::ios_base::badbit std::ios_base::failbit

    if (!fin.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
    }

    std::ofstream fout;
    fout.open("config/config.ini"); // Will fail silently
    fin.exceptions(std::ios_base::failbit | std::ios_base::badbit); //그리고 이거 | 이거인거 기억해

    if (!fout.is_open()) {
        std::cerr << "Error opening config/config.ini" << std::endl;
    } else {
        fout << "This is an example for the exception in C++!" << std::endl;
    }
    } catch (std::ios_base::failure& e) {
        std::cout << e.what() << std::endl;
        std::cout << e.what() << std::endl;
    }




    return 0;
}