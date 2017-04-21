#include "FBullCowGame.h"

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::reset() {
	return;
}

std::string FBullCowGame::getStartingWord(int WORD_LENGTH) const {
	return std::string();
}

bool FBullCowGame::IsGameWon() const  {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) {
	return false;
}

bool FBullCowGame::IsIsogram(std::string Word) {
	return false;
}
