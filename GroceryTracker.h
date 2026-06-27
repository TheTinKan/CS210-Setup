#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

using namespace std;

class GroceryTracker
{
private:
	map<string, int> itemFrequency;

public:
	//Reads the grocery file
	void LoadFile();

	//Create frequency.dat
	void CreateBackupFile();

	//Menu option 1
	void SearchItem();

	//Menu option 2
	void DisplayAllItems();

	//Menu option 3
	void DisplayHistogram();
};

#endif
