#pragma once
#include <map>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

class GroceryData {
private:
	map<string, int>* ItemMap;
	void InputData(string fileName);
	void BackupData();
public:
	// Default CTOR
	GroceryData();
	// PARAM CTOR: takes a string indicating the filename to the data source
	GroceryData(string fileName);

	int FindNumOccurrences(string param);
	void ItemFrequency();
	void ChartHistogram();
};