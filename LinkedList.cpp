/*
*Created by: Connor Schultz
*LinkedList.cpp
*Apr 30, 2017
*9:25:14 PM
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList :: LinkedList()
{
	head = nullptr;
	tail = nullptr;
}

void LinkedList :: addToStart(int val)
{
	//Create a new pointer object of the ListNode struct
	ListNode * newNode;
	newNode = new ListNode;

	//Set the newNode.value to the value the user inputed earlier
	newNode->value = val;

	//If the list is empty simply just put down the value
	if(head == nullptr)
	{
		head = newNode;

		//Set newNode.next equal to the tail
		newNode->next = tail;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList :: appendNode(int val)
{
	//Create two new obj pointers of ListNode
	ListNode * newNode;

	ListNode * nodePtr;

	//Dynamically allocate memory for the newNode obj
	newNode = new ListNode;

	//Set the newNode.value equal to the value the user entered earlier
	newNode->value = val;
	newNode->next = 0;

	//If the list is empty simply put the value in the linked list
	if(head == nullptr)
	{
		head = newNode;
		newNode->next = tail;
	}
	else
	{
		//Set nodePtr to the head
		nodePtr = head;

		while(nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}
		//Set the next nodePtr equal to newNode
		nodePtr->next = newNode;
		newNode->next = tail;
	}

}

void LinkedList :: insertNodeAtLocal(int loc, int val)
{
	//Create two objs to the ListNode
	ListNode * newNode;

	//Set nodePtr to the head to traverse through the linked list
	ListNode * nodePtr = head;
	newNode = new ListNode;

	//Create a int var to go through the Linked List
	int i;

	//Set the newNode.value to the value the user entered earlier
	newNode->value = val;

	//If head still equals nullptr then make the head the newNode value
	if(head == nullptr)
	{
		head = newNode;
	}
	//else create a while loop to go until i equals the location
	else
	{
		while(i < loc)
		{
			//Keep setting the nodePtr to the next value
			nodePtr = nodePtr->next;
			i++;
		}
		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void LinkedList :: deleteNodeOfVal(int val)
{
	ListNode * nodePtr;
	ListNode * prevPtr;

	if(nodePtr->value == val)
	{
		head = nodePtr->next;
		delete nodePtr;
	}
	else
	{
		if(nodePtr->next == nullptr && nodePtr->value == val)
			{
				prevPtr->next = nullptr;
				delete nodePtr;
				tail = prevPtr;
			}
		else
		{
			while(nodePtr->next)
			{

				if(nodePtr->value == val)
				{
					prevPtr->next = nodePtr->next;
					delete nodePtr;
					break;
				}
					prevPtr = nodePtr;
					nodePtr = nodePtr->next;
			}
		}
	}

}

void LinkedList :: deleteNodeAtLocal(int loc)
{
	//Creat two new objs
	ListNode * nodePtr;
	ListNode * prevPtr;

	//Create a variable to go through the list
	int i;

	//Tried to test if the user enters 0 then it just replaces right away but it just crashes
	if(loc == 0)
	{
		head = nodePtr->next;
	}
	else
	{
		//While i doesn't equal location
		//Go through setting a prePtr to the nodePtr
		//Then set nodePtr to the next value
		//Add onto i
		while(i != loc)
		{
			prevPtr = nodePtr;
			nodePtr = nodePtr->next;
			i++;
		}
	}
	prevPtr->next = nodePtr->next;

	//Free up the unused memory now
	delete nodePtr;


}

int LinkedList :: getNodeAtLocal(int loc)
{
	//Create a new obj
	ListNode * nodePtr;

	//Set the nodePtr to head
	nodePtr = head;

	//Create a variable to go through the list
	int i;

	//While i < loc then go through the list
	//Set the nodePtr to the next value
	while(i < loc)
	{
		nodePtr = nodePtr->next;
		i++;
	}
	//Return the value that the nodePtr.value is now
	return nodePtr->value;
}

void LinkedList :: removeAllDups()
{
	//Create 4 obj variables
	ListNode * nodePtr;
	ListNode * prevPtr;
	ListNode * examPtr;
	ListNode * tempPtr;

	//Set the nodePtr equal to head.next or the second value
	nodePtr = head->next;

	//While the nodePtr doesn't equal the last value go through the list
	while(nodePtr != tail)
	{
		//start examPtr to the first variable
		examPtr = head;
		while(examPtr != nodePtr)
		{
			//If the two values equal eachother
			if(examPtr->value == nodePtr->value)
			{
				//Go through with a tempPtr to the node
				//Then set the node to the next value
				//Then set prePtr.next to the new nodePtr
				//Delete the temp to free up memory
				tempPtr = nodePtr;
				nodePtr = nodePtr->next;
				prevPtr->next = nodePtr;
				delete tempPtr;
				break;
			}
			examPtr = examPtr->next;
		}
		if(examPtr == nodePtr)
		{
			nodePtr = nodePtr->next;
			prevPtr = prevPtr->next;
		}
	}
}

int LinkedList :: numOfNodes()
{
	//Create a new object
	ListNode * nodePtr;

	//Create a variable to go through the list
	int i;

	//While the nodePtr doesn't equal the end of the list
	//Add onto i
	//And set nodePtr equal to the next value
	while(nodePtr != nullptr)
	{
		i++;
		nodePtr = nodePtr->next;
	}

	//Return the amount of times i was added
	return i;
}

void LinkedList :: deleteList()
{
	//Create two new objs
	ListNode * nodePtr;
	ListNode * prevPtr;

	//Set nodePtr equal to the head variable
	nodePtr = head;

	//If the list is empty then delte just the first variable even if null
	if(nodePtr == nullptr)
	{
		head = nodePtr->next;
		delete nodePtr;
	}

	//Else go through the list until nodePtr cannot point to another value
	//Go through and delete the prevPtr value
	else
	{
		while(nodePtr)
			{
				prevPtr = nodePtr;
				nodePtr = nodePtr->next;
				delete prevPtr;
			}
	}


}

void LinkedList :: mergeTwoNode(int a, int b)
{
	//Create 3 objs
	ListNode * nodeA;
	ListNode * nodeB;

	//Create a tempB pointer for the value of nodeB
	ListNode * tempB;

	//Create two variables to find the two values starting at 1
	int i = 1;
	int j = 1;

	//Start bouth nodes at head
	nodeA = head;
	nodeB = head;

	//Follow the list until value a is found
	while(i < a)
	{
		nodeA = nodeA->next;
		i++;
	}

	//Follow the list until value b is found
	while(i < b)
	{
		tempB = nodeB;
		nodeB = nodeB->next;
		i++;
	}

	nodeA->value = nodeA->value + nodeB->value;
	tempB->next = nodeB->next;
	delete nodeB;

}

void LinkedList :: displayList() const
{
	//Create a new obj
	ListNode *nodePtr;

	//Start the nodePtr at the head
	nodePtr = head;

	//Go through the list and just cout the nodePtr.value through the each next
	while(nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}
