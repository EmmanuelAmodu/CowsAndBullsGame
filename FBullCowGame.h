#pragma once
#include <string>

class FBullCowGame {
public: 
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	std::string getStartingWord(int WORD_LENGTH) const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void reset(); //TODO make a rich return value.
	bool CheckGuessValidity(std::string);

private: 
	// see constructor for definitions
	int MyCurrentTry;
	int MyMaxTries;
};
