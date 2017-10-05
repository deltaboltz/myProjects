/*
 * LinkedList.h
 *
 *  Created on: Apr 30, 2017
 *      Author: delta
 */
#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class LinkedList
{
private:
	//Create a private struct to hold your next value and value of the node
	struct ListNode
	{
		int value;
		struct ListNode *next;
	};

	//Create two private objects of your struct(head and tail)
	ListNode *head;
	ListNode *tail;
public:
	//Create a contstructor to make an empty list
	LinkedList();

	void addToStart(int);
	void appendNode(int);
	void insertNodeAtLocal(int, int);
	void insertNodeInSortOrder(int);

	void deleteNodeOfVal(int);
	void deleteNodeAtLocal(int);

	int getNodeAtLocal(int);

	void mergeTwoNode(int, int);
	void swapNode(int, int);

	void deleteList();
	int numOfNodes();
	void removeAllDups();

	void displayList() const;
};




#endif /* LINKEDLIST_H */
