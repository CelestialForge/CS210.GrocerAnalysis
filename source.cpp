#include <iostream>
#include <string>
#include <windows.h>
#include "GroceryData.h"

using namespace std;


/*
Brian Larson
CS210 - 24EW4
Week 7 Project 3
Corner Grocer
*/


/*
bool WriteData(string p_fileName, string p_data){
	ofstream outFS;
	outFS.open(p_fileName);
	if (!outFS.is_open()) {
		cout << "Error opening file: " << p_fileName << endl;
		system("PAUSE");
		return false;
	}
	outFS << p_data;
	outFS.close();
	return true;
}
string ReadData(string p_fileName) {
	ifstream inFS;
	inFS.open(p_fileName);
	if (!inFS.is_open()) {
		cout << "Error opening file: " << p_fileName << endl;
		system("PAUSE");
		return "Error";
	}
	string returnData = "";
	string readbuffer;
	while (!inFS.eof()) {
		getline(inFS, readbuffer);
		returnData += readbuffer + '\n';
	}
	inFS.close();
	return returnData;
}
*/

// Menu Functions
// Print the Menu
void PrintMenu() {
	
	cout << "---=== Corner Grocer ===---" << endl;
	cout << "1 - Find Number of Item Occurrences" << endl;
	cout << "2 - List Item Frequencies" << endl;
	cout << "3 - Chart Item Histogram" << endl;
	cout << "4 - Quit" << endl;
}

// Print the Exit message
void ExitMessage() {
	cout << "Thank you for using our app." << endl;
	system("PAUSE");
}

void main() {
	
	GroceryData CornerGrocer = GroceryData();

	// Run Menu
	int choice = -1;
	string param;
	// Looping ops menu
	while (choice != 4) {
		PrintMenu();
		cin >> choice;
		switch (choice) {
		case 1: 
			system("CLS");
			cout << "Find Number of Item Occurrences" << endl;
			cout << "Enter the item to search: ";
			cin.ignore();
			getline(cin, param);
			cout << param << " occurs in the list " << CornerGrocer.FindNumOccurrences(param) << " times." << endl;
			system("PAUSE");
			system("CLS");
			break;
		case 2:
			system("CLS");
			cout << "Item Frequencies: " << endl;
			CornerGrocer.ItemFrequency();
			system("PAUSE");
			system("CLS");
			break;
		case 3:
			system("CLS");
			cout << "Frequency Histogram: 0        1         2" << endl;
			cout << "                     12345678901234567890" << endl;
			CornerGrocer.ChartHistogram();
			system("PAUSE");
			system("CLS");
			break;
		case 4:
			ExitMessage();
			break;
		default:
			cout << "Please enter a valid number." << endl;
			Sleep(1000);
			system("CLS");
		}
	}
}