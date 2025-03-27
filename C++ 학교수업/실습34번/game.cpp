// Implement your code

#include "game.h"
#include <iostream>
#include <random>
#include <string>
#include <map>
using namespace std;

Choice getPlayerChoice() {
	string N;
	while (true) {
		cin >> N;

		if (N == "¹¬") {
			return Choice::ROCK;
		}
		else if (N == "Âî") {
			return Choice::SCISSORS;
		}
		else if (N == "ºü") {
			return Choice::PAPER;
		}
		else {
			cout << "Àß¸øµÈ ÀÔ·Â" << endl;
		}
	}
}


Choice getComputerChoice() {
	std::mt19937 gen(777);
	std::uniform_int_distribution<int> dist(0, 2);
	Choice N = {};
	switch (dist(gen))
	{
	case 0:
		N = Choice::ROCK;
		break;
	case 1:
		N = Choice::SCISSORS;
		break;
	case 2:
		N = Choice::PAPER;
		break;
	}
	return N;
}

int determineWinner(Choice player, Choice computer) {
	if (player == computer) {
		return 0;
	}
	else if (((player == Choice::ROCK) && (computer == Choice::SCISSORS)) ||
		((player == Choice::SCISSORS) && (computer == Choice::PAPER)) ||
		((player == Choice::PAPER) && (computer == Choice::ROCK)))
		//player ½Â¸®
		return 1;
	else
		//computer ½Â¸®
		return -1;
}

void displayChoice(const std::string& who, Choice choice) {

	switch (choice)
	{
	case Choice::ROCK:
		cout << who << " chose ROCK (¹¬)." << "\n";
		break;
	case Choice::SCISSORS:
		cout << who << " chose SCISSORS (Âî)." << "\n";
		break;
	case Choice::PAPER:
		cout << who << " chose PAPER (ºü)." << "\n";
		break;
	}

}