#include <iostream>
#include "GroceryTracker.h"

using namespace std;

int main()
{
    GroceryTracker tracker;

    //Read file and create backup file
    tracker.LoadFile();
	tracker.CreateBackupFile();

    int choice = 0;

	//Menu loop
    while (choice != 4)
    {
		cout << "\n===== Corner Grocer Menu =====" << endl;
		cout << "1 - Search for an item" << endl;
		cout << "2 - Display all items and their frequencies" << endl;
		cout << "3 - Display a histogram of item frequencies" << endl;
		cout << "4 - Exit" << endl;
		cout << endl;
		cout << "Enter your choice: "; 
		
		cin >> choice;

		//check for valid input
		if (cin.fail())
		{
			cout << endl;
			cout << "Invalid input. Please enter a number between 1 and 4." << endl;
			
			cin.clear(); //clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard invalid input
			
			continue;
		}

		//Run menu options
		switch (choice)
		{
		case 1:
			tracker.SearchItem();
			break;

		case 2:
			tracker.DisplayAllItems();
			break;

		case 3:
			tracker.DisplayHistogram();
			break;

		case 4:
			cout << "Exiting program..." << endl;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
		}
    }
}
