#pragma once
#include"Person.h"
#include"Client.h"
#include"Broker.h"
#include"Turbo.h"
#include "ETF.h"
#include"Functions.h"
#include"Plot.h"

class BrokersOperations
{

public:

	/*
	* Method that returns an iterator to the broker. it is used to log into the broker account
	*/
	static list<Broker>::iterator findBroker(string name_, string surname_, string password_, unique_ptr<list<Broker>>& Brokers_list);

	/*
	* Method that returns an iterator to the broker with the given id
	* @param id_ brokers id
	* @param smart pointer to the Brokers list
	*/
	static list<Broker>::iterator findBroker(int id_, unique_ptr<list<Broker>>& Brokers_list);
	
	/*
	* Method that prints brokers list at the console output
	* @param smart pointer to the brokers list
	*/
	static void showBrokers(unique_ptr<list<Broker>>& Brokers_list);

	/*
	* Method returns the id of a given broker, it is used to select a broker by the client during registration
	* @param count brokers id
	* @param Brokers_List smart pointer to the brokers list
	*/
	static int getId(int count, unique_ptr<list<Broker>>& Brokers_list);

	/*
	* Method that search for a broker with a given id and then add it to his client base
	* @param Brokers id
	* @param clients base
	* @param pointer to the brokers list
	*/
	static void findBrokerAndAddClient(int Brokers_id_, ClientsBase<string> Client_, unique_ptr<list<Broker>>& Brokers_list); 

	/*
	* Method that prints all brokers at the console output
	*/
	static void show(unique_ptr<list<Broker>>& Brokers_list);

	/*
	* Method that prints brokers clients list
	* @param brokers id 
	* @param pointer to the brokers list
	*/
	static void showBrokersClients(int id_, unique_ptr<list<Broker>>& Brokers_list_);

	/*
	* Method that authenthicates broker that wants to log in
	* @param brokers name
	* @param brokers surname
	* @param brokers password
	* @param pointer to the brokers list
	* @return bool true if brokers is in the base
	*/
	static bool checkUser(string name_, string surname_, string password_, unique_ptr<list<Broker>>& Brokers_list);

};

