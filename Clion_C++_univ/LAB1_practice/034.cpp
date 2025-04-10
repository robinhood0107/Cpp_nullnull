//
// Created by pjjpj on 25. 4. 1.
//



//洹몃━怨?string 留뚮뱾??臾댁“嫄?""?곕뵲?댄몴濡??대씪
//enum class ?뱀쭠? 臾댁“嫄?namespace濡쒕쭔 ?붿냼 ?묎렐??媛?ν븿
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
        cin >> N; //怨쇱젣?먯꽌 ?닿굅瑜?while臾몄?濡??대깽??猷⑦봽 ?덈룎由щ㈃ 紐⑤뜕C++?섏? ?딅떎怨??먯닔 源롫뒗??

        if (N == "臾?) {
            return Choice::ROCK;
        }
        else if (N == "李?) {
            return Choice::SCISSORS;
        }
        else if (N == "鍮?) {
            return Choice::PAPER;
        }
        else {
            cout << "?섎せ???낅젰" << endl;
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
            cout << "ROCK (臾?\n";
          break;
        case (Choice::SCISSORS):
            cout << "SCISSORS (李?\n";
          break;
        case (Choice::PAPER):
            cout << "PAPER (鍮?\n";
          break;
      }
    }
    else{
      cout << "Computer chose ";
      switch(choice){
      case (Choice::ROCK):
          cout << "ROCK (臾?\n";
            break;
      case (Choice::SCISSORS):
          cout << "SCISSORS (李?\n";
            break;
      case (Choice::PAPER):
          cout << "PAPER (鍮?\n";
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
        //player ?밸━
            return 1;
    else
        //computer ?밸━
            return -1;
}











