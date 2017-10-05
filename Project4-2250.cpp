/*
*Created by: Connor Schultz
*Project4-2250.cpp
*Apr 30, 2017
*9:24:40 PM
*/
#include <iostream>
#include "LinkedList.h" //Needed for all the function calls

using namespace std;

//I created a menu prototype function just to make calling a menu easier
int menu();

int main()
{
	//Create a LinkedList Obj
	LinkedList list;

	//Call the constructor to create an empty list and allocate new memory

	//Create a variable that will be equal to what is returned by the menu
	int decision;

	//Create variables for values a user wants to input and the two locations for some functions
	int value;
	int location, location2;

	//Create a variable to be equal to the return value of numOfNodes
	int numOfNodes;

	cout << "Please choose what you would like to do to the Linked List" << endl;

	//Call the menu function
	decision = menu();

	//While the decision doesn't equal 11 aka EXIT
	while(decision != 11)
	{
		//Go through if statements for the menu choices
		if(decision == 1)
		{
			cout << "Enter a value you would like to enter in the beginning" << endl;
			cin >> value;
			//use your object to call each function inside LinkedList.h & .cpp
			list.addToStart(value);
		}
		else if(decision == 2)
		{
			cout << "Enter a value you would like to enter at the end" << endl;
			cin >> value;
			list.appendNode(value);
			decision = menu();
		}
		else if(decision == 3)
		{
			cout << "Enter the value of the Node you wish to delete" << endl;
			cin >> value;
			list.deleteNodeOfVal(value);
		}
		else if(decision == 4)
		{
			cout << "Enter the location you wish delete" << endl;
			cin >> location;
			list.deleteNodeAtLocal(location);
		}
		else if(decision == 5)
		{
			cout << "Choose the location of the two nodes you wish to merge" << endl;
			cin >> location;
			cin >> location2;
			list.mergeTwoNode(location, location2);
		}
		else if(decision == 6)
		{
			cout << "Choose the locations you wish to swap" << endl;
			cout << "I'm sorry this does not work" << endl;
		}
		else if(decision == 7)
		{
			cout << "REMOVING ALL DUPLICATES... PLEASE WAIT" << endl;
			list.removeAllDups();
		}
		else if(decision == 8)
		{
			cout << "SHOWING NUMBER OF CURRENT NODES... PLEASE WAIT" << endl;
			numOfNodes = list.numOfNodes();
			cout << numOfNodes;
		}
		else if(decision == 9)
		{
			cout << "DISPLAYING LIST... PLEASE WAIT" << endl;
			list.displayList();
		}
		else if(decision == 10)
		{
			cout << "DELETING LIST... PLEASE WAIT" << endl;
			list.deleteList();
		}
		else if(decision == 11)
		{
			cout << "NOW EXITING" << endl;
			break;
		}
		decision = menu();
	}
}

int menu()
{
	int choice;
	cout << endl;
	cout << endl;

	//Create a do-while loop for the menu sets
	do
		{
			cout << "1 : Add a Node to the Start" << endl;
			cout << "2 : Add a Node to the End" << endl;
			cout << "3 : Delete a Node of a Value" << endl;
			cout << "4 : Delete a Node at a Location" << endl;
			cout << "5 : Merge two Nodes at Location A & B" << endl;
			cout << "6 : Swap two Nodes at Location A & B" << endl;
			cout << "7 : Remove all Duplicates" << endl;
			cout << "8 : Show the Number of Nodes" << endl;
			cout << "9 : Show your List" << endl;
			cout <<"10 : DELETE THE LIST" << endl;
			cout << "11 : EXIT" << endl;

			cin >> choice;
		}while(choice < 1 || choice > 10);

	//Return what the user chooses
	return choice;
}


