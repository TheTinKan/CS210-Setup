#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void GroceryTracker::LoadFile()
{
	ifstream iFile("CS210_Project_Three_Input_File.txt");

	string item;

	while (iFile >> item)
	{
		itemFrequency[item]++;
	}

	iFile.close();
}

void GroceryTracker::CreateBackupFile()
{
	ofstream oFile("frequency.dat");

	for (auto item : itemFrequency)
	{
		oFile << item.first << " " << item.second << endl;
	}

	oFile.close();
}

void GroceryTracker::SearchItem()
{
	string itemName;

	cout << "Enter item to search for: ";
	cin >> itemName;

	if (itemFrequency.count(itemName) > 0)
	{
		cout << endl;
		cout << itemName << " was found " << itemFrequency[itemName] << " times." << endl;
	}
	else
	{
		cout << endl;
		cout << itemName << " was not found." << endl
			<< "Please ensure the first letter is capitalized "
			<< "Example: Apples" << endl;

	}
}

void GroceryTracker::DisplayAllItems()
{
	cout << endl;

	for (auto item : itemFrequency)
	{
		cout << item.first << " " << item.second << endl;
	}
}

void GroceryTracker::DisplayHistogram()
{
	cout << endl;

	for (auto item : itemFrequency)
	{
		cout << left << setw(15) << item.first;

		for (int i = 0; i < item.second; i++)
		{
			cout << "*";
		}

		cout << endl;
	}
}
	