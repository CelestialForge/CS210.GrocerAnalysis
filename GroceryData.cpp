#include "GroceryData.h"


// read data from an input file
void GroceryData::InputData(string fileName) {

	ItemMap = new map<string, int>();

	// Read data set
	ifstream inFS;
	inFS.open(fileName);
	// Error notification
	if (!inFS.is_open()) {
		cout << "Error opening file: " << fileName << endl;
		system("PAUSE");
		cout << "Error";
	}
	string readBuffer;

	// If item is in the map, increment, else add item to map
	while (!inFS.eof()) {
		getline(inFS, readBuffer);
		if (ItemMap->count(readBuffer) > 0) {
			ItemMap->at(readBuffer)++;
		}
		else {
			ItemMap->emplace(readBuffer, 1);
		}
	}
	inFS.close(); // close readfile
}

// Generate a back up file of the map data
void GroceryData::BackupData() {
	// Write backup file
	ofstream outFS;
	outFS.open("GrocerParsedData.txt");
	// error notification
	if (!outFS.is_open()) {
		cout << "Error opening file: GrocerParsedData.txt" << endl;
		system("PAUSE");
	}
	// Iterate the map and record items
	map<string, int>::iterator index = ItemMap->begin();
	while (index != ItemMap->end()) {
		outFS << index->first << " " << index->second << endl;
		//cout << index->first << " " << index->second << endl;
		index++;
	}
	outFS.close(); // close writefile
}

// Default CTOR
GroceryData::GroceryData() {
	InputData("GrocerInput.txt");
	BackupData();
}
// PARAM CTOR: takes a string indicating the filename to the data source
GroceryData::GroceryData(string fileName) {
	InputData(fileName);
	BackupData();
}

// Show the number of appearances for a given item
int GroceryData::FindNumOccurrences(string param) {
	// if item count is zero, return zero, else return value
	return ((ItemMap->count(param) == 0) ? 0 : ItemMap->at(param));
}

// List items in the data set and their appearance frequency	
void GroceryData::ItemFrequency() {
	map<string, int>::iterator index = ItemMap->begin();
	while (index != ItemMap->end()) {
		cout << fixed << setw(20) << left << index->first << " " << setw(3) << right << index->second << endl;
		index++;
	}
}

// List items in the data set and create a histogram of their appearance frequency	
void GroceryData::ChartHistogram() {
	map<string, int>::iterator index = ItemMap->begin();
	while (index != ItemMap->end()) {
		// SETFILL is at the end to make sure tables after are unaffected
		cout << fixed << setw(20) << right << index->first << " " << setfill('*');	// Item Column Setup
		cout << left << setw(index->second) << "*" << setfill(' ') << endl;			// Bar column setup
		index++;
	}
}