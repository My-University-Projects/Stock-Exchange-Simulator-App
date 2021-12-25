#pragma once
#include"Person.h"
#include"Client.h"
#include"Broker.h"
#include"Turbo.h"
#include "ETF.h"
#include"Functions.h"
#include"Plot.h"

/*
* Class representanting files operations
*/
class FilesOperations
{
public:
	
	/*
	* method that loads the client list into the program
	* @param pointer to the clients list
	*/
	static void loadDataFromFile(unique_ptr<list<Client>>& Clients_list);
	
	/*
	* method that writes a client list to a file
	* @param pointer to the clients list
	*/
	static void putDataInFile(unique_ptr<list<Client>>& Clients_list_);
	 
	/*
	* method that writes a brokers list to a file
	* @param pointer to the brokers list
	*/
	static void putDataInFile(unique_ptr<list<Broker>>& Brokers_list);

	/*
	* method that loads the brokers list into the program
	* @param pointer to the brokers list
	*/
	static void loadDataFromFile(unique_ptr<list<Broker>>& Brokers_list);

	/*
	* Method that loads the turbos list from file
	* @param pointer to the turbos list
	*/
	static void loadTurboFromFile(unique_ptr<list<Turbo>>& Stocks_list);

	/*
	* Method that loads the ETFs list from file
	* @param pointer to the ETFs list
	*/
	static void loadETFFromFile(unique_ptr<list<ETF>>& ETF_list);

	/*
	* Method that writes turbos list to the file
	* @param turbos list pointer
	*/
	static void putTurbosInFile(unique_ptr<list<Turbo>>& Turbos_list);

	/*
	* Method that writes ETFs list to the file
	* @param ETFs list pointer
	*/
	static void putETFInFile(unique_ptr<list<ETF>>& ETF_list);
};