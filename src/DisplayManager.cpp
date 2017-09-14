#include <iostream>
#include "display.cpp"

using namespace std;

// variables
int userChoice;

//functions
void enterFirstMenu();

void startingMenu() {
	MainMenu();
	cin >> userChoice;
	if (userChoice == 0) {
		exit(-1);
	}
	if (userChoice == 1) {
		enterFirstMenu();
	}
}
void enterFirstMenu() {
	firstMenu();
	cin >> userChoice;
	if (userChoice == 0) {
		startingMenu();
	}
	if (userChoice == 1) {
		firstMenuOOne();
	}
}