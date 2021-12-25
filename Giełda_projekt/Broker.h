#pragma once
#include"Person.h"
#include"Clients_base.h"

/*
* Class representanting a brokers account
*/
class Broker : public  Person
{
	friend class Menu;
	friend class FilesOperations;
	friend class BrokersOperations;
	friend class ClientsBase<string>; 
	friend class Client;

	int id;
	int commision;
	float balance;
	string password;
	ClientsBase<string>* clientsBasepHead; 
	
public:

	/*
	* 6-args Constructor 
	*/
	Broker(string name_, string surname_, string password_, int id_, int commision_, float balance_);
	
	/*
	* Destructor
	*/
	~Broker();

	/*
	* Method that deletes a client from the brokers base 
	* @param brokers id
	* @param brokers name
	* @param brokers surname
	*/
	void deleteFromClientsBase(int id_, string name_, string surname_);								

	/*
	* Method that show actual list of brokers clients
	*/
	void showBrokersClients();																		

	/*
	* Method that deletes brokers clients base 
	*/
	void deleteClientsBase();

};