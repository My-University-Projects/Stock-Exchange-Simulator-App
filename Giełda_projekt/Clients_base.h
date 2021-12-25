#pragma once
#include"Person.h"

/*
* Template class representanting a clients base
*/
template <class T> 
class ClientsBase 
{
public:

	T name, surname;
	ClientsBase* pNext;

	/*
	* No args constructor
	*/
	ClientsBase()
	{
		this->pNext = nullptr;
	}

	/*
	* 2- args contructor
	*/
	ClientsBase(T name_, T surname_) /////////////////////
	{
		this->name = name_;
		this->surname = surname_;
		this->pNext = nullptr;
	}

	/*
	* Destructor
	*/
	~ClientsBase()
	{}

	/*
	* Method that adds client to the base
	* @param clients base list head
	* @param clients name
	* @param clients surname
	*/
	void addToBase(ClientsBase*& pHead, T name_, T surname_)
	{
		if (pHead == nullptr)
		{
			pHead = new ClientsBase(name_, surname_);
			pHead->pNext = nullptr;
		}
		else
		{
			auto p = pHead;
			while (pHead->pNext) { pHead = pHead->pNext; }
			pHead->pNext = new ClientsBase(name_, surname_);
			pHead->pNext->pNext = nullptr;
			pHead = p;
		}
		return;
	}

	/*
	* Method that prints clients base at the console outpur
	* @param clients base list head
	*/
	void showElements(ClientsBase* pHead)
	{
		while (pHead)
		{
			cout << pHead->name << " " << pHead->surname << "\n";
			pHead = pHead->pNext;
		}
	}
};
