#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame(){ reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::reset() {
	constexpr int32 Max_Tries = 8;
	MyMaxTries = Max_Tries;
	MyHiddenWord = "morphy";
	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const  {
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	// if is not an isogram, 
	if (false) {
		// return error
		return EGuessStatus::Not_Isogram;
	}
	// if the guess isn't all lowercase,
	else if (false) {
		// return error
		return EGuessStatus::Not_LowerCase;
	}
	// if guess length is wrong
	else if (GetHiddenWordLength() != Guess.length()) {
		// return error
		return EGuessStatus::Wrong_Word_Length;
	}
	// otherwise 
	else {
		// return ok
		return EGuessStatus::OK;
	}
}
// recieves a valid guess increments turn, and return count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {
	MyCurrentTry++;

	//set up return structure
	FBullCowCount BullCowCount;

	int32 GuessLength = Guess.length();
	for (int32 j = 0; j < GuessLength; j++) { // compare letters against the hidden word
		int32 PositionOfChar = MyHiddenWord.find(Guess[j]);
		if (PositionOfChar != -1) { // if chars match then
			if (PositionOfChar == j) {  // if they are in the same place
				BullCowCount.Bulls++; // increment bulls 
			}
			else { // else they are not
				BullCowCount.Cows++; // increment cows
			}
		}
	}
	return BullCowCount;
}
