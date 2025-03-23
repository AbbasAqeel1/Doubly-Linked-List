#pragma once
#include <iostream>
#include <exception>
using namespace std;


template <class T>
class Node
{
public:
	Node(T Val)
	{
		value = Val;
	}
	int value;
	Node<T>* next = NULL;
	Node<T>* prev = NULL;
};



template <class T>
class DoublyLinkedList
{

	Node<T>* Head;
	Node<T>* Tail;
	int Size;

public:
	DoublyLinkedList()
	{
		Head = NULL;
		Tail = NULL;
		Size = 0;
	}
	~DoublyLinkedList()
	{
		Node<T>* temp = NULL;
		while (Head)
		{
			temp = Head;
			Head = Head->next;
			delete temp;
		}
		Head = Tail = NULL;
	}
	int GetSize()
	{
		return Size;
	}

	void InsertAtBeginning(T Val)
	{
		Node<T>* Newnode = new Node<T>(Val);
		if (!Head)
		{
			Head = Newnode;
			Tail = Newnode;
		}
		else
		{
			Newnode->next = Head;
			Head->prev = Newnode;
			Head = Newnode;
		}
		Size++;
	}

	void InsertAtEnd(T Val)
	{
		Node<T>* Newnode = new Node<T>(Val);
		if (!Tail)
		{
			Tail = Newnode;
			Head = Newnode;
		}
		else
		{
			Newnode->prev = Tail;
			Tail->next = Newnode;
			Tail = Newnode;
		}
		Size++;
	}

	void InsertAt(int index, T Val)
	{
		if (index < 0 || index > Size)
		{
			throw exception("Error, Index out of range.");
		}

		if (index == Size)
		{
			InsertAtEnd(Val);
			return;
		}

		if (index == 0)
		{
			InsertAtBeginning(Val);
			return;
		}

		Node<T>* Newnode = new Node<T>(Val);

		int counter = 0;
		Node<T>* temp = Head;
		for (int i = counter;i < index && temp->next != NULL;i++)
		{
			temp = temp->next;
			counter++;
		}

		Newnode->next = temp;
		Newnode->prev = temp->prev;

		temp->prev->next = Newnode;
		temp->prev = Newnode;

		Size++;
	}

	void PrintAllNodes()
	{
		Node<T>* temp = Head;
		while (temp)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
	}

	void PrintAllNodesReversely()
	{
		Node<T>* Temp = Tail;

		while (Temp)
		{
			cout << Temp->value << " ";
			Temp = Temp->prev;
		}
	}

	Node<T>* Find(T Val)
	{
		Node<T>* temp = Head;
		while (temp)
		{
			if (temp->value == Val)
			{
				return temp;
			}
			temp = temp->next;
		}
		return NULL;
	}

	bool Delete(T Val)
	{
		Node<T>* temp = Head;
		while (temp)
		{
			if (temp->value == Val)
			{
				break;
			}
			temp = temp->next;
		}

		if (!temp)
			return false;
		if (temp->next)
			temp->next->prev = temp->prev;

		if (temp->prev)
			temp->prev->next = temp->next;

		if (temp->prev == NULL)
			Head = temp->next;
		if (temp->next == NULL)
			Tail = temp->prev;

		delete temp;
		return true;

	}

	bool DeleteFirstNode()
	{
		if (Head)
		{
			if (Head->next == NULL)
			{
				Head = Head->next;
				delete Tail;
				Tail = Head;
				return true;
			}
			else
			{
				Node<T>* temp = Head;
				Head = Head->next;
				Head->prev = NULL;
				delete temp;
				return true;
			}
		}
		return false;
	}

	bool DeleteLastNode()
	{
		if (Tail)
		{
			if (Tail->prev == NULL)
			{
				Tail = Tail->prev;
				delete Head;
				Head = Tail;
				return true;
			}
			else
			{
				Node<T>* temp = Tail;
				Tail = Tail->prev;
				Tail->next = NULL;
				delete temp;
				return true;
			}
		}
		return false;
	}


	void Reverse()
	{
		Node<T>* Curr = Head;
		Node<T>* Prev = Curr;

		while (Curr)
		{
			Curr = Curr->next;
			Prev->next = Prev->prev;
			Prev->prev = Curr;
			Prev = Curr;
		}

		Node<T>* temp = Head;
		Head = Tail;
		Tail = temp;

	}

	void Clear()
	{
		Node<T>* temp;
		while (Head)
		{
			temp = Head;
			Head = Head->next;
			delete temp;
		}
		Tail = NULL;
	}
};
