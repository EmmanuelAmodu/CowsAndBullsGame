#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro(int WORD_LENGTH);
void PlayGame(std::string &Guess);
std::string GetGuess(std::string Guess);
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main() {
	constexpr int WORD_LENGTH = 5;
	PrintIntro(WORD_LENGTH);
	std::string Guess = "";
	PlayGame(Guess);
	return 0;
}

void PrintIntro(int WORD_LENGTH) {
	//introduce the game
	std::cout << "welcome to bulls and cows a fun word game\n";
	std::cout << "Can You guess the " << WORD_LENGTH << " letter I am think of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame(std::string &Guess) {
	//loop for the number of turns asking for guesses
	int MaxTries = BCGame.GetMaxTries();
	std::cout << "Number of Tries Allowed " << MaxTries << std::endl;

	for (int count = 1; count <= MaxTries; count++) {
		std::cout << "Your Guess was - " << GetGuess(Guess) << std::endl;
	}
	if (AskToPlayAgain() == 1) {
		PlayGame(Guess);
	}
	return;
}

std::string GetGuess(std::string Guess) {
	//get a guess from the user
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess: ";
	getline(std::cin, Guess);
	std::cout << std::endl;
	return Guess;
}

bool AskToPlayAgain() {
	std::string Response = "";
	std::cout << std::endl;
	std::cout << "Do you want to play Again (y/n)?: ";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}