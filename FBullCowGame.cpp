#include "FBullCowGame.h"

FBullCowGame::FBullCowGame(){
	MyCurrentTry = 1;
    MyMaxTries = 5;
}

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