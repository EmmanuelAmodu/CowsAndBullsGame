#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all integer initializwd to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Word_Length,
	Not_LowerCase
};

class FBullCowGame {
public: 
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;


	void reset(); //TODO make a rich return value.
	FBullCowCount SubmitValidGuess(FString);

private: 
	// see constructor for definitions
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};
