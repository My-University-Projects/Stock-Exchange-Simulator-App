#pragma once
#include"Person.h"
#include"Broker.h"
#include"Client.h"
#include"Functions.h"
#include"Clients_base.h"
#include "Menu.h"
#include "Turbo.h"
#include "ETF.h"
#include"Plot.h"
#include"File_operations.h"


/*
* Method that updates values in turbos list
* @param pointer to the turbos list
* @param flag if thread with this function has to be terminated
*/
void updateTurbosValues(unique_ptr<list<Turbo>>& Turbos_list, bool& flag)
{
	while (1)
	{
		if (flag == true) { return; }
		auto Turbo_i = Turbos_list->begin();
		for (Turbo_i; Turbo_i != Turbos_list->end(); Turbo_i++)
		{
			int rand_1 = (rand() % 3);
			if (rand_1 == 0)
			{
				int rand_2 = (rand() % 10);
				float new_value = Turbo_i->currentValue * (1 + ((Turbo_i->currentValue * rand_2 * Turbo_i->lever) / (Turbo_i->currentValue * 1000)));
				Turbo_i->currentValue = new_value;
				if (Turbo_i->lastValues.size() >= 100) { Turbo_i->lastValues.pop_front(); }
				Turbo_i->lastValues.push_back(new_value);
				Sleep(1000);
			}
			else if(rand_1 == 1 )
			{
				int rand_2 = (rand() % 10);
				float new_value = Turbo_i->currentValue * (1 - ((Turbo_i->currentValue * rand_2 * Turbo_i->lever) / (Turbo_i->currentValue * 1000)));
				Turbo_i->currentValue = new_value;
				if (Turbo_i->lastValues.size() >= 100) { Turbo_i->lastValues.pop_front(); }
				Turbo_i->lastValues.push_back(new_value);
				Sleep(1000);
			}
		}
	}
}

/*
* Method that updates values in ETFs list
* @param pointer to the ETFs list
* @param flag if thread with this function has to be terminated
*/
void updateValues(unique_ptr<list<ETF>>& ETF_list, bool& flag)
{
	while (1)
	{
		if (flag == true) { return; }
		auto etf_i = ETF_list->begin();
		for (etf_i; etf_i != ETF_list->end(); etf_i++)
		{
			int rand_1 = (rand() % 3);
			if (rand_1 == 0)
			{
				int rand_2 = (rand() % 10);
				float new_value = etf_i->currentValue * (1 + ((etf_i->currentValue * rand_2) / (etf_i->currentValue * 1000)));
				etf_i->currentValue = new_value;
				if (etf_i->lastValues.size() >= 100) { etf_i->lastValues.pop_front(); }
				etf_i->lastValues.push_back(new_value);
				Sleep(1000); //cout << etf_i->name << endl << new_value << " "; // bufor cykliczny
			}
			else if(rand_1 == 1)
			{
				int rand_2 = (rand() % 10);
				float new_value = etf_i->currentValue * (1 - ((etf_i->currentValue * rand_2) / (etf_i->currentValue * 1000)));
				etf_i->currentValue = new_value;
				if (etf_i->lastValues.size() >= 100) { etf_i->lastValues.pop_front(); }
				etf_i->lastValues.push_back(new_value);
				Sleep(1000);// cout << etf_i->name << endl << new_value << " ";
			}
		}
	}
}

/*
* Method that checks stop loss
* @param pointer to the clients list
* @param pointer to the ETFs list 
* @bool flag 
*/
void checkStopLoss(unique_ptr<list<Client>>& Clients, unique_ptr<list<ETF>>& ETF_list, bool& flag)
{
	while (1)
	{
		char x;
		if (flag == true) { return; }
		auto p = Clients->begin();
		for (p; p != Clients->end(); p++)
		{
			p->stopLossETF(ETF_list);
		}
		Sleep(10000);
		
	}
}

sf::Font font;

int main()
{ 

	
	try
	{
		if (!font.loadFromFile("C:/Users/tomek/Desktop/Giełda_projekt/Debug/ALGER.ttf")) { throw 1; }
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (int)
	{
		exit(-1);
	}
	
	srand(time(NULL));
	bool stop_thread_1 = false;

	unique_ptr<list<ETF>> ETF_list(new list<ETF>);
	unique_ptr<list<Turbo>> Turbos_list(new list<Turbo>);
	unique_ptr<list<Client>> Clients_list(new list<Client>);
	unique_ptr<list<Broker>> Brokers_list(new list<Broker>);

	FilesOperations::loadETFFromFile(ETF_list);
	FilesOperations::loadTurboFromFile(Turbos_list);
	FilesOperations::loadDataFromFile(Brokers_list);
	FilesOperations::loadDataFromFile(Clients_list);

	thread t1(updateValues, ref(ETF_list), ref(stop_thread_1));
	t1.detach();
	thread t2(updateTurbosValues, ref(Turbos_list), ref(stop_thread_1));
	t2.detach();
	thread t3(checkStopLoss, ref(Clients_list), ref(ETF_list), ref(stop_thread_1));
	t3.detach();

	Menu::startProgram(Clients_list, Brokers_list, Turbos_list, ETF_list, stop_thread_1, font);

	return 0;
}