#ifndef GAME_H
#define GAME_H

#include <string>

enum class Choice { ROCK, SCISSORS, PAPER };

Choice getPlayerChoice();
Choice getComputerChoice();
void displayChoice(const std::string& who, Choice choice);
int determineWinner(Choice player, Choice computer);
void play();

#endif
