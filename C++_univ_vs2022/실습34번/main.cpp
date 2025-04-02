#include "game.h"
#include <iostream>

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
