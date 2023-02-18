#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <algorithm>

void GenerateArray(int* array);
void PrintArray(int* array);
void PrintComparisons();
void SortArray(int* array);

class Node
{
	public:
		Node()
		{
			value = 0;
			nextptr = nullptr;
		}
		int getValue()
		{
			return value;
		}
		void setValue(int newValue)
		{
			value = newValue;
		}
		Node* getNext()
		{
			return nextptr;
		}
		void setNext(Node* newNext)
		{
			nextptr = newNext;
		}



	private:
		int value;
		Node* nextptr;
};

class LinkedListHolder
{
public:
	LinkedListHolder()
	{

		head = nullptr;
		tail = nullptr;
	}
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
	//This functions goes through the linked list and finalizes the array into a sorted form
	void FinalizeArray(int* array)
	{
		Node* cur = this->head;
		//I only do it like this to avoid comparisons in a for loop
		array[0] = cur->getValue();
		cur = cur->getNext();
		array[1] = cur->getValue();
		cur = cur->getNext();
		array[2] = cur->getValue();
		cur = cur->getNext();
		array[3] = cur->getValue();
		cur = cur->getNext();
		array[4] = cur->getValue();
		cur = cur->getNext();
	}
	/*Inserts a Node at the front of the LinkedList with 0 comparisons
	Only to be used with first element, as there is no error checking to avoid comparisons*/
	void InsertAtFront(Node* newHead)
	{
		//only use for first element
		newHead->setNext(head);
		head = newHead;
		tail = head;
	}
	//Inserts a Node at the end of the LinkedList with 0 comparisons
	void InsertAtEnd(Node* newTail)
	{	
		//assumes list is not empty for comparison count, if list is empty I will use InsertAtFront
		tail->setNext(newTail);
		tail = newTail;
		newTail->setNext(nullptr);
		
	}
	//Finds and inserts a Node containing the 5th element in the array, into the correct spot of the linked list using 2 comparisons
	void InsertE(Node* ENode)
	{
		Node* cur = head->getNext();
		Node* placeholder;
		PrintComparisons();
		if (ENode->getValue() < cur->getValue()) //If Enode less than second element in linked list
		{
			PrintComparisons();
			if (ENode->getValue() < head->getValue()) //if Enode less than head, make Enode new fist element
			{
				ENode->setNext(head);
				head = ENode;
			}
			else //else, Enode must become second element in array
			{
				InsertSecond(ENode);

			}
		}
		else
		{
			PrintComparisons();
			if (ENode->getValue() < tail->getValue())
			{
				placeholder = cur->getNext();
				cur->setNext(ENode);
				ENode->setNext(placeholder);
			}
			else
			{
				InsertAtEnd(ENode);
			}
		}
	}
	//Finds and inserts a Node containing the final element to insert, into the correct spot of the linked list using 2 comparisons
	void InsertLast(Node* LastNode) 
	{
		Node* cur = head->getNext();
		Node* placeholder;
		PrintComparisons();
		if (LastNode->getValue() < cur->getValue())
		{
			PrintComparisons();
			if (LastNode->getValue() < head->getValue())
			{
				InsertAtFront(LastNode);
			}
			else
			{
				InsertSecond(LastNode);
			}
		}
		else
		{
			PrintComparisons();
			if (LastNode->getValue() < cur->getNext()->getValue())
			{
				placeholder = cur->getNext();
				cur->setNext(LastNode);
				LastNode->setNext(placeholder);
			}
			else
			{
				cur->getNext()->setNext(LastNode);
				LastNode->setNext(this->getTail());
			}
		}

	}
	void InsertSecond(Node* newNode)
	{
		Node* temp = head->getNext();
		head->setNext(newNode);
		newNode->setNext(temp);
	}
	void WipeList()
	{
		Node* cur = head;
		Node* temp;
		while(cur != nullptr)
		{
			temp = cur;
			cur = cur->getNext();
			delete temp;
			
		}
	}


private:
	Node* head;
	Node* tail;
};