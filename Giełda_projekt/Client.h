#pragma once
#include"Person.h"
#include"Stock.h"
#include"Turbo.h"
#include "Broker.h"
#include "ETF.h"

/*
* Class representanting a client at the stock exchange
*/
class Client : public Person
{
	friend class Menu;
	friend class FilesOperations;
	friend class ClientsOperations;

	string password;
	string creditCard;
	int Brokers_id;
	float balance;
	list<Turbo> clientTurbos;
	list<ETF> clientETFs;

public:

	/*
	* 5-args constructor
	*/
	Client(string name_, string surname_, string password_, string credit_card_, int Brokers_id_); 

	/*
	* 6-args constructor
	*/
	Client(string name_, string surname_, string password_, string credit_card_, int Brokers_id_, float balance_); 

	/*
	* Destructor
	*/
	~Client(); 

	/*
	* Method that add amout of money to the client balance
	* @param amount of the money
	*/
	void addToBalance(float amount_);

	/*
	* method that handles the Turbo certificate purchase process
	* @param count of the purchades certificates
	* @param pointer to the clients turbos list
	* @param brokers list iterator
	*/
	void buyTurbo(int count, unique_ptr<list<Turbo>>& Turbos_list_, list<Broker>::iterator Brokers_list);
	
	/*
	* Method that show clients turbos certificates list at the console output
	*/
	void showTurbosList(); 

	/*
	* method that handles the ETF certificate purchase process
	* @param count of the purchades certificates
	* @param pointer to the clients turbos list
	* @param brokers list iterator
	*/
	void buyETF(int count, unique_ptr<list<ETF>>& ETF_list, list<Broker>::iterator Brokers_list);
	
	/*
	* Method that show clients ETFs list at the console output
	*/
	void showETFsList();

	/*
	* a method that handles the sale of the client's Turbo certificates
	* @param count of the sold certificates
	* @param pointer to the clients turbos list
	* @param brokers list iterator
	*/
	void sellTurbo(int count_, unique_ptr<list<Turbo>>& Clients_list_, list<Broker>::iterator Broker); 

	/*
	* a method that handles the sale of the client's ETF certificates
	* @param count of the sold certificates
	* @param pointer to the clients ETF list
	* @param brokers list iterator
	*/
	void sellETF(int count_, unique_ptr<list<ETF>>& Clients_list_, list<Broker>::iterator Broker);

	/*
	* Method that changes value of ETFs
	* @param pointer to the ETFs list
	*/
	void findAndChangeETFValue(unique_ptr<list<ETF>>& ETF_list);

	/*
	* Method that changes value of Turbo certificate
	* @param pointer to the Turbos list
	*/
	void findAndChangeTurboValue(unique_ptr<list<Turbo>>& Turbos_list);

	/*
	* Method that creates .csv files with clients ETFs
	* @param pointer to the clients ETF list
	*/
	void printETF(unique_ptr<list<ETF>>& ETF_list);

	/*
	* Method that creates .csv files with clients Turboss
	* @param pointer to the clients Turbos list
	*/
	void printTurbos(unique_ptr<list<Turbo>>& Turbos_list);

	/*
	* Method that adds the last 100 ETFs quotes to the user's action board
	* @param pointer to the ETFs list
	* @param clients list iterator
	*/
	void addValuesETF(unique_ptr<list<ETF>>& ETF_list, list<Client>::iterator& Client_);
	
	/*
	* Method that adds the last 100 Turbos quotes to the user's action board
	* @param pointer to the ETFs list
	*/
	void addValuesTurbo(unique_ptr<list<Turbo>>& Turbos_list);

	/*
	* Method that handles Stop loss process for stocks
	* @param ponter to the ETFs list
	*/
	void stopLossETF(unique_ptr<list<ETF>>& ETF_list);

	/*
	* A method that supports the process of advising a client
	* @param pointer to the ETFs list
	* @param pointer to the Turbos list
	*/
	void brokersAdvice(unique_ptr<list<ETF>>& ETF_list, unique_ptr<list<Turbo>>& Turbo_list);

};
