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
FText GetValidGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main() {
	const int32 WORD_LENGTH = BCGame.GetHiddenWordLength();
	PrintIntro(WORD_LENGTH);
	do {
		PlayGame();
		//TODO add game summary 
	} while (AskToPlayAgain() == 1);
	return 0;
}

void PrintIntro(int32 WORD_LENGTH) {
	//introduce the game
	std::cout << "welcome to bulls and cows a fun word game\n";
	std::cout << "Can You guess the " << WORD_LENGTH << " letter I am think of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame() {
	
	BCGame.reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Number of Tries Allowed " << MaxTries << std::endl;

	//loop for the number of turns asking for guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	for (int32 count = 1; count <= MaxTries; count++) {
		// TODO check for valid guess
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << "\n\n";

		//std::cout << "Your Guess was - " << Guess << std::endl;
	}
	// TODO sumarise game here
	return;
}

FText GetValidGuess() {
	//get a guess from the user
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Word_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_LowerCase:
			std::cout << "Please enter only lowercase letter.\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;

	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {
	FText Response = "";
	std::cout << std::endl;
	std::cout << "Do you want to play Again (y/n)?: ";
	getline(std::cin, Response);
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}