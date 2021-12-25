#pragma once
#include"Person.h"
#include"Client.h"
#include"Broker.h"
#include"Turbo.h"
#include "ETF.h"
#include"Functions.h"
#include"Plot.h"

/*
* Class representanting controller of the menu
*/
class Menu
{
public:

	/*
	* Method that supports the processes related to logging in and handling the logged-in client
	* @param flag
	* @param pointer to the clients list
	* @param pointer to the brokers list
	* @param pointer to the turbos list
	* @param pointer to the ETFs list
	* @param font
	*/
	static void startUser(bool& flag, unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_, const Font& font);

	/*
	* Method that supports the processes related to registration new user 
	* @param pointer to the clients list
	* @param pointer to the brokers list
	* @param pointer to the turbos list
	* @param pointer to the ETFs list
	*/
	static void newUser(unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_);

	/*
	* Method that handles processes related to logging in and handling a logged-in broker
	* @param flag
	* @param pointer to the clients list
	* @param pointer to the brokers list
	* @param pointer to the turbos list
	* @param pointer to the ETFs list
	* @param font
	*/
	static void startBroker(bool& flag, unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_, const Font& font);
	
	/*
	* Method that handles the main menu of the program
	* @param pointer to the clients list
	* @param pointer to the brokers list
	* @param pointer to the turbos list
	* @param pointer to the ETFs list
	* @param font
	*/
	static void startProgram(unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_,  bool& stop_thread_1, const Font& font);

	/*
	* a method that handles the process of creating a ETF chart
	* @param pointer to the ETFs list
	* @param index of ETF that has to be printed
	* @param font
	*/
	static void printPlotETF(unique_ptr<list<ETF>>& ETF_list_, int count_, const Font& font);
	
	/*
	* a method that handles the process of creating a turbo chart
	* @param pointer to the Turbos list
	* @param index of Turbo that has to be printed
	* @param font
	*/
	static void printPlotTurbo(unique_ptr<list<Turbo>>& Turbos_list_, int count_, const Font& font);

	/*
	* Method that deletes all lists in the program
	*/
	static void deleteLists(unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_);
};

