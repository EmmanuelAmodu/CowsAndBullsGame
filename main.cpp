/*
This is the console executable that makes use of the BullCow class
this acts as the view in mvc pattern and is responsible for all user interaction
for logic see the FBullCowGame class
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro(int32 WORD_LENGTH);
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main () {
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	PrintIntro(WORD_LENGTH);
	do {
		PlayGame();
	} while (AskToPlayAgain() == 1);
	return 0;
}

void PrintIntro(int32 WORD_LENGTH) {
	//introduce the game
	std::cout << "welcome to bulls and cows a fun word game\n";
	std::cout << "          }   {        ___        " << std::endl;
	std::cout << "          (0 0)       (0 0)       " << std::endl;
	std::cout << "  /--------\\ /         \\ /-------\\ " << std::endl;
	std::cout << " / | Bulls |o    And    o|  cows |\\" << std::endl;
	std::cout << "*  |--?----|             |-------| *" << std::endl;
	std::cout << "   ^       ^             ^       ^    " << std::endl;
	std::cout << "Can You guess the " << WORD_LENGTH << " letter I am think of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	
	BCGame.reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Number of Tries Allowed " << MaxTries << std::endl;

	// loop asking for guesses while game 
	// is not won and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}

FText GetValidGuess() {
	//get a guess from the user
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries(); 
		std::cout << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Word_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter only lowercase letter.\n\n";
			break;
		default:
			break;
		}

	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {
	FText Response = "";
	std::cout << std::endl;
	std::cout << "Do you want to play Again with the same hidden word (y/n)?: ";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations You won";
	}
	else {
		std::cout << "You loss better luck next time";
	}
	return;
}