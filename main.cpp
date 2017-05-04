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
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main() {
	constexpr int32 WORD_LENGTH = 5;
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
		FText Guess = GetGuess();

		//submit valid guess to game and recieve count;
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows;
		std::cout << std::endl;
		std::cout << std::endl;

		//std::cout << "Your Guess was - " << Guess << std::endl;
		//print number of bulls and cows
	}
	// TODO sumarise game here
	return;
}

FText GetGuess() {
	//get a guess from the user
	FText Guess;
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess: ";
	getline(std::cin, Guess);
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