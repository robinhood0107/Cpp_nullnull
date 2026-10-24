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
		//player 승리
		return 1;
	else
		//computer 승리
		return -1;
}

void displayChoice(const std::string& who, Choice choice) {

	switch (choice)
	{
	case Choice::ROCK:
		cout << who << " chose ROCK (묵)." << "\n";
		break;
	case Choice::SCISSORS:
		cout << who << " chose SCISSORS (찌)." << "\n";
		break;
	case Choice::PAPER:
		cout << who << " chose PAPER (빠)." << "\n";
		break;
	}

}