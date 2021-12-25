#pragma once
#include"Clients_base.h"

/*Clients_base::Clients_base()
{
	this->pNext = nullptr;
}

Clients_base::Clients_base(string name_, string surname_) : Person(name_, surname_)
{
	this->pNext = nullptr;
}

Clients_base::~Clients_base()
{}

void Clients_base::add_to_base(Clients_base*& pHead, string name_, string surname_)
{
	if (pHead == nullptr)
	{
		pHead = new Clients_base(name_, surname_);
		pHead->pNext = nullptr;
	}
	else
	{
		auto p = pHead;
		while (pHead->pNext) { pHead = pHead->pNext; }
		pHead->pNext = new Clients_base(name_, surname_);
		pHead->pNext->pNext = nullptr;
		pHead = p;
	}
	return;
}
void show_elements(Clients_base* pHead)
{
	while (pHead)
	{
		cout << pHead->get_name() << " " << pHead->get_surname() << "\n";
		pHead = pHead->pNext;
	}
}*/