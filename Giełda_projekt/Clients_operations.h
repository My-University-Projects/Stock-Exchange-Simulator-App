#pragma once
#include"Person.h"
#include"Client.h"
#include"Broker.h"
#include"Turbo.h"
#include "ETF.h"
#include"Functions.h"
#include"Plot.h"

class ClientsOperations
{
public:

	/*
	* Method that prints clients base at the console output
	* @param clients base list pointer
	*/
	static void show(unique_ptr<list<Client>>& Clients_list_);

	/*
	* Method that checks if a given user exists in the database, it is used to log in the client
	* @param clients name
	* @param clients surname
	* @param clients password
	* @param pointer to the clints list
	* @return bool if user can log in
	*/
	static bool checkUser(string name_, string surname_, string password_, unique_ptr<list<Client>>& Clients_list);
	
	/*
	* Method that returns the iterator at the clients with passed data
	* @param pointer to the clients list
	* @param clients name
	* @param clients surname
	* @param clients password
	*/
	static list<Client>::iterator findClient(unique_ptr<list<Client>>& Clients_list, string name_, string surname_, string password_);
};

