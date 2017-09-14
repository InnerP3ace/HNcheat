////////////////////////////////////////
// display.cpp
// created by: Inner Peace
// on: 2017, 9, 13
////////////////////////////////////////

#include <iostream>
#include <Windows.h>

using namespace std;

// variables
int currentTotalRam;
int newTotalRam;

// the main menu
void MainMenu() {
	system("CLS");
	system("color 0B");
	cout << "********************************************************************************\n";
	cout << "*                                 /------------\\                               *\n";
	cout << "*                                 |HNcheat menu|                               *\n";
	cout << "*                                 \\------------/                               *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      1: total player ram                                                     *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      0: exit                                                                 *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      C:\\Root\\                                                                *\n";
	cout << "*      Running........................                                         *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      choose an option: ";
}
// the first menu, for the total player ram
void firstMenu() {
	system("CLS");
	cout << "********************************************************************************\n";
	cout << "*                                 /------------\\                               *\n";
	cout << "*                                 |HNcheat menu|                               *\n";
	cout << "*                                 \\------------/                               *\n";
	cout << "*                      current total player ram: ";
	// an up-to-date number for the player ram is given here
	HWND hwnd = FindWindowA(NULL, "Hacknet");
	if (!hwnd) {
		cout << "couldn't find the window!\n";
		system("PAUSE");
		exit(-1);
	}
	DWORD processID;                                                   // stores the process id of the window
	GetWindowThreadProcessId(hwnd, &processID);                     // gets the process id of the window
																	// error message if the process ID isn't found
	if (!processID) {
		cout << "couldn't obtain the process ID!\n";
		system("PAUSE");
	}// gets the process id of the window
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID); // opens the process with full access
	if (!handle) {
		cout << "couldn't initiate a handle!\n";
	}
	ReadProcessMemory(handle, (LPVOID)0x044A57C0, &currentTotalRam, 4, NULL);
	if (!currentTotalRam) {
		cout << "couldn't read memory!\n";
	}
	CloseHandle(handle);
	cout << currentTotalRam << "                           *\n";
	cout << "*                                                                              *\n";
	cout << "*      1: change total ram                                                     *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*     0: go back                                                               *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      C:\\Root\\total_Player_Ram                                                *\n";
	cout << "*      Running........................                                         *\n";
	cout << "*                                                                              *\n";
	cout << "*                                                                              *\n";
	cout << "*      choose an option: ";
}
void firstMenuOOne() {
	system("CLS");
	cout << "what to you want to change " << currentTotalRam << " to?\n";
	cin >> newTotalRam;
	// this adds in the new ram
	HWND hwnd = FindWindowA(NULL, "Hacknet");
	if (!hwnd) {
		cout << "couldn't find the window!\n";
		system("PAUSE");
		exit(-1);
	}
	DWORD processID;                                                   // stores the process id of the window
	GetWindowThreadProcessId(hwnd, &processID);                        // gets the process id of the window
	if (!processID) {                                                  // error message if the process ID isn't found
		cout << "couldn't obtain the process ID!\n";
		system("PAUSE");
	}
	HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID); // opens the process with full access
	if (!handle) {
		cout << "couldn't initiate a handle!\n";
	}
	WriteProcessMemory(handle, (LPVOID)0x044A57C0, &newTotalRam, 4, NULL);
	CloseHandle(handle);
	system("CLS");
	cout << "written!\n";
	system("PAUSE");
}