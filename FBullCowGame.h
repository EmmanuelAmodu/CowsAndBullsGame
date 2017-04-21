#pragma once
#include <string>

class FBullCowGame {
public: 
	int GetMaxTries() const;
	std::string getStartingWord(int WORD_LENGTH) const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void reset(); //TODO make a rich return value.
	bool CheckGuessValidity(std::string);

private: 
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
	bool IsIsogram(std::string Word);
};
