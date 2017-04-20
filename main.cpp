#include <iostream>
#include <string>

using namespace std;

void PrintIntro(int WORD_LENGTH);
string PrintGuessAndPrintBack(string Guess);

int main() {
	PrintIntro(5);
	string Guess;
	//get a guess from the user
	PrintGuessAndPrintBack(Guess);
	return 0;
}

void PrintIntro(int WORD_LENGTH) {
	//introduce the game
	cout << "welcome to bulls and cows a fun word game\n";
	cout << "Can You guess the " << WORD_LENGTH;
	cout << " letter I am think of?\n";
	cout << endl;
	return;
}

string PrintGuessAndPrintBack(string Guess){
	cout << "Enter your guess: ";
	getline(cin, Guess);

	//repeat the guess to them
	cout << "Your Guess was - " << Guess << endl;
	cout << endl;
	return Guess;
}