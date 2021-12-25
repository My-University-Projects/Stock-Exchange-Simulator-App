#include "Brokers_operations.h"

void BrokersOperations::showBrokers(unique_ptr<list<Broker>>& Brokers_list)
{
	int count = 4;
	list<Broker>::iterator i = (*Brokers_list).begin();
	for (i; i != (*Brokers_list).end(); i++)
	{
		cout << count << ".";
		cout << "Makler " << i->getName() << " " << i->getSurname() << endl;
		cout << "Pobierana przez maklera prowizja - " << i->commision << "%" << endl << endl;
		count--;
	}
}

int BrokersOperations::getId(int count, unique_ptr<list<Broker>>& Brokers_list)
{
	list<Broker>::iterator i = (*Brokers_list).begin();
	for (i; i != (*Brokers_list).end(); i++)
	{
		if (i->id == count) { return i->id; }
	}
	return -1;
}

void BrokersOperations::findBrokerAndAddClient(int Brokers_id_, ClientsBase<string> Client_, unique_ptr<list<Broker>>& Brokers_list)
{
	list<Broker>::iterator i = (*Brokers_list).begin();
	for (i; i != (*Brokers_list).end(); i++)
	{
		if (Brokers_id_ == i->id) { i->clientsBasepHead->addToBase(i->clientsBasepHead, Client_.name, Client_.surname); }
	}
}

void BrokersOperations::show(unique_ptr<list<Broker>>& Brokers_list)
{
	list<Broker>::iterator i = (*Brokers_list).begin();
	for (i; i != (*Brokers_list).end(); i++)
	{
		cout << i->getName() << endl;
		cout << i->getSurname() << endl;
		cout << "Klienci:\n";
		auto p = i->clientsBasepHead;
		p->showElements(p);
	}
}

void BrokersOperations::showBrokersClients(int id_, unique_ptr<list<Broker>>& Brokers_list_)
{
	list<Broker>::iterator i = Brokers_list_->begin();
	for (i; i != Brokers_list_->end(); i++)
	{
		if (i->id == id_)
		{
			cout << "Aktualny makler: " << i->getName() << " " << i->getSurname() << endl;
			cout << "Prowizja: " << i->commision << "%\n";
			return;
		}
	}
}

list<Broker>::iterator BrokersOperations::findBroker(int id_, unique_ptr<list<Broker>>& Brokers_list)
{
	list<Broker>::iterator i = Brokers_list->begin();
	for (i; i != Brokers_list->end(); i++)
	{
		if (i->id == id_) { return i; }
	}
	return i;
}

bool BrokersOperations::checkUser(string name_, string surname_, string password_, unique_ptr<list<Broker>>& Brokers_list)
{
	list<Broker>::iterator i = Brokers_list->begin();
	for (i; i != Brokers_list->end(); i++)
	{
		if (i->getName() == name_ && i->getSurname() == surname_ && i->password == password_) { return true; }
	}
	return false;
}

list<Broker>::iterator BrokersOperations::findBroker(string name_, string surname_, string password_, unique_ptr<list<Broker>>& Brokers_list)
{
	auto p = Brokers_list->begin();
	for (p; p != Brokers_list->end(); p++)
	{
		if (name_ == p->getName() && surname_ == p->getSurname() && password_ == p->password) { return p; }
	}
	return p;
}
