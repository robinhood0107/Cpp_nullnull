//
// Created by pjjpj on 25. 4. 1.
//



//그리고 string 만들때 무조건 ""큰따옴표로 해라
//enum class 특징은 무조건 namespace로만 요소 접근이 가능함
#include <iostream>
#include <string>
#include <iostream>
#include <random>
#include <string>
#include <map>
using namespace std;

enum class Choice { ROCK, SCISSORS, PAPER };

Choice getPlayerChoice();
Choice getComputerChoice();
void displayChoice(const std::string& who, Choice choice);
int determineWinner(Choice player, Choice computer);

int main() {
    Choice player = getPlayerChoice();
    Choice computer = getComputerChoice();

    displayChoice("You", player);
    displayChoice("Computer", computer);

    int result = determineWinner(player, computer);
    if (result == 1) {
        std::cout << "You win!\n";
    } else if (result == -1) {
        std::cout << "Computer wins!\n";
    } else {
        std::cout << "It's a tie!\n";
    }
    return 0;
}

Choice getPlayerChoice() {
    string N;
    while (true) {
        cin >> N; //과제에서 이거를 while문은로 이벤트 루프 안돌리면 모던C++하지 않다고 점수 깎는다

        if (N == "묵") {
            return Choice::ROCK;
        }
        else if (N == "찌") {
            return Choice::SCISSORS;
        }
        else if (N == "빠") {
            return Choice::PAPER;
        }
        else {
            cout << "잘못된 입력" << endl;
        }
    }
}


Choice getComputerChoice(){
    Choice p;
    std::mt19937 rng(777);
    std::uniform_int_distribution<int> dist(0, 2);
    switch(dist(rng)){
      case 0:
        p = Choice::ROCK;
        break;
      case 1:
        p = Choice::SCISSORS;
        break;
      case 2:
        p = Choice::PAPER;
        break;
    }
  return p;
}

void displayChoice(const std::string& who, Choice choice){
    if(who == "You"){
      cout << "You chose ";
      switch(choice){
        case (Choice::ROCK):
            cout << "ROCK (묵)\n";
          break;
        case (Choice::SCISSORS):
            cout << "SCISSORS (찌)\n";
          break;
        case (Choice::PAPER):
            cout << "PAPER (빠)\n";
          break;
      }
    }
    else{
      cout << "Computer chose ";
      switch(choice){
      case (Choice::ROCK):
          cout << "ROCK (묵)\n";
            break;
      case (Choice::SCISSORS):
          cout << "SCISSORS (찌)\n";
            break;
      case (Choice::PAPER):
          cout << "PAPER (빠)\n";
            break;
      }
    }
}
int determineWinner(Choice player, Choice computer){
    if (player == computer) {
        return 0;
    }
    else if (((player == Choice::ROCK) && (computer == Choice::SCISSORS)) ||
        ((player == Choice::SCISSORS) && (computer == Choice::PAPER)) ||
        ((player == Choice::PAPER) && (computer == Choice::ROCK)))
        //player 승리
            return 1;
    else
        //computer 승리
            return -1;
}











