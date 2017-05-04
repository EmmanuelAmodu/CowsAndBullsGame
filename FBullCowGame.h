#pragma once
#include <string>
using FString = std::string;
using int32 = int;

// all integer initializwd to zero
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public: 
	FBullCowGame(); //constructor

	int32 GetMaxTries() const;
	FString getStartingWord() const;
	//TODO randomly select word from the word list variable
	//and return it
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void reset(); //TODO make a rich return value.
	bool CheckGuessValidity(FString);//TODO make a more rich return value
	FBullCowCount SubmitGuess(FString);

private: 
	// see constructor for definitions
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	const FString WORD_LIST[4] = {"char", "unreal", "could", "mundane"};
};
