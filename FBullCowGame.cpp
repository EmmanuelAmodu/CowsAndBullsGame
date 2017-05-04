#include "FBullCowGame.h"
#include <stdlib.h>
#include <time.h>

using int32 = int;

FBullCowGame::FBullCowGame(){ reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::reset() {
	constexpr int32 Max_Tries = 8;
	MyMaxTries = Max_Tries;
	MyHiddenWord = getStartingWord();
	MyCurrentTry = 1;
	return;
}

FString FBullCowGame::getStartingWord() const {
	srand((unsigned int)time(NULL));
	int32 output = rand() % 3;
	return WORD_LIST[output];
}

bool FBullCowGame::IsGameWon() const  {
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString guess) {
	return false;
}
// recieves a valid guess increments turn, and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {
	//increment return number
	MyCurrentTry++;

	//set up return structure
	FBullCowCount BullCowCount;

	//compare letters against the hidden word
	int32 GuessLength = Guess.length();
	for (int32 j = 0; j < GuessLength; j++) {
		//if chars match then
		int32 PositionOfChar = MyHiddenWord.find(Guess[j]);
		if (PositionOfChar || Guess[j] == MyHiddenWord[0]) {
			// if they are in the same place
			if (PositionOfChar == j) {
				//increment bulls 
				BullCowCount.Bulls++;
			}
			// else they are not
			else {
				//increment cows
				BullCowCount.Cows++;
			}
		}
	}
	return BullCowCount;
}
