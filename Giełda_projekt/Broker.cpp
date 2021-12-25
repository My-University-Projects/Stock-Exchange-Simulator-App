#pragma once
#include"Broker.h"


Broker::Broker(string name_, string surname_, string password_, int id_, int commision_, float balance_) : Person(name_, surname_), password(password_), id(id_), commision(commision_), balance(balance_)
{
	this->clientsBasepHead = nullptr;
}

Broker::~Broker()
{
	this->deleteClientsBase();
}

void Broker::deleteFromClientsBase(int id_, string name_, string surname_)
{
	auto p = this->clientsBasepHead;
	if (p->pNext == nullptr)
	{
		clientsBasepHead = p->pNext;
		delete p;
	}
	else
	{
		while (p->pNext)
		{
			if (p->pNext->name == name_ && p->pNext->surname == surname_)
			{
				auto q = p->pNext;
				delete p->pNext;
				p->pNext = nullptr;
				p->pNext->pNext = q->pNext;
				return;
			}
			p = p->pNext;
		}

	}
}

void Broker::showBrokersClients()
{
	cout << "Lista klientow: \n";
	auto p = this->clientsBasepHead;
	while (p)
	{
		cout << p->name << " " << p->surname;
		cout << endl;
		p = p->pNext;
	}
}

void Broker::deleteClientsBase()
{
	if (this->clientsBasepHead == nullptr) { return; }

	auto tmp = clientsBasepHead->pNext;
	while (clientsBasepHead)
	{
		tmp = clientsBasepHead->pNext;
		delete clientsBasepHead;
		clientsBasepHead = tmp;
	}
}