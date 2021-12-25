#include "Clients_operations.h"

void ClientsOperations::show(unique_ptr<list<Client>>& Clients_list_)
{
	list<Client>::iterator p = Clients_list_->begin();
	for (p; p != Clients_list_->end(); p++)
	{
		cout << p->getName() << endl;
		cout << p->getSurname() << endl;
		cout << p->balance << endl;
		cout << p->password << endl;
		cout << p->creditCard << endl;
		cout << p->Brokers_id << endl;
	}

}

bool ClientsOperations::checkUser(string name_, string surname_, string password_, unique_ptr<list<Client>>& Clients_list)
{
	list<Client>::iterator i = Clients_list->begin();
	for (i; i != (*Clients_list).end(); i++)
	{
		if (i->getName() == name_ && i->getSurname() == surname_ && i->password == password_) { return true; }
	}
	return false;
}

list<Client>::iterator ClientsOperations::findClient(unique_ptr<list<Client>>& Clients_list, string name_, string surname_, string password_)
{
	list<Client>::iterator i = (*Clients_list).begin();
	for (i; i != (*Clients_list).end(); i++)
	{
		if (i->getName() == name_ && i->getSurname() == surname_ && i->password == password_) { return i; }
	}
}
