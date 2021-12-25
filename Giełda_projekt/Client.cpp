#pragma once
#include"Client.h"

Client::Client(string name_, string surname_, string password_, string credit_card_, int Brokers_id_) : Person(name_, surname_), creditCard(credit_card_), password(password_), Brokers_id(Brokers_id_)
{
	this->balance = 0;
}

Client:: ~Client()
{
	this->clientETFs.erase(clientETFs.begin(), clientETFs.end());
	this->clientTurbos.erase(clientTurbos.begin(), clientTurbos.end());
}

Client::Client(string name_, string surname_, string password_, string credit_card_, int Brokers_id_, float balance_) : Person(name_, surname_), creditCard(credit_card_), password(password_), Brokers_id(Brokers_id_), balance(balance_)
{}

void Client::buyTurbo(int count_, unique_ptr<list<Turbo>>& Turbos_list, list<Broker>::iterator Brokers)
{
	int amount_;
	float sum_;
	list<Turbo>::iterator i = Turbos_list->begin();
	while (1)
	{
		system("CLS");
		cout << "Podaj ilosc akcji, ktore chcesz zakupic: "; cin >> amount_;
		for (i; i != Turbos_list->end(); i++)
		{
			if (count_ == i->count) { float x = i->currentValue; sum_ = amount_ * x;  break; }
		}
		if (this->balance - (sum_ + ((sum_ * Brokers->commision) / 100)) < 0 || sum_ > 0.25 * this->balance) { cout << "Nie mozesz zakupic takiej ilosci certyfikatow!\n";  Sleep(3000); }
		else 
		{ 
			this->balance -= ((sum_ * Brokers->commision) / 100);
			Brokers->balance += ((sum_ * Brokers->commision) / 100);
			cout << "Dziêkujemy za zakup certyfikatu Turbo. Wracamy do Menu; "; for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
			break;
		}
	}
	this->balance = this->balance - sum_;
	Turbo tmp(i->name, i->type, i->currentValue, i->lever, i->count, amount_);
	this->clientTurbos.push_back(tmp);
}

void Client::buyETF(int count_, unique_ptr<list<ETF>>& ETF_list, list<Broker>::iterator Brokers)
{
	int amount_;
	float sum_;
	list<ETF>::iterator i = ETF_list->begin();
	while (1)
	{
		system("CLS");
		cout << "Podaj ilosc akcji, ktore chcesz zakupic: "; cin >> amount_;
		for (i; i != ETF_list->end(); i++)
		{
			if (count_ == i->count) { float x = i->currentValue; sum_ = amount_ * x;  break; }
		}
		if (this->balance - (sum_ + ((sum_ * Brokers->commision) / 100)) < 0) { cout << "Nie mozesz zakupic takiej ilosci akcji!\n"; Sleep(3000); return; }
		else 
		{
			this->balance -= ((sum_ * Brokers->commision) / 100);
			Brokers->balance += ((sum_ * Brokers->commision) / 100);
			cout << "Dziêkujemy za zakup akcji. Wracamy do Menu; "; for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
			break;
		}
	}
	this->balance = this->balance - sum_;
	ETF tmp(i->name, i->currentValue, i->count, amount_);
	this->clientETFs.push_back(tmp);
}

void Client::showTurbosList()
{
	cout << "Certyfikaty Turbo: " << endl;
	list<Turbo>::iterator i = this->clientTurbos.begin();
	for (i; i != this->clientTurbos.end(); i++)
	{
		cout << i->count << ". " << i->name << " " << i->type << "\nCena za sztuke w momencie zakupu: " << setprecision(4) << i->valueWhenPurchased <<  "zl\naktualny kurs:  " << setprecision(4) << i->currentValue << "zl  " << "wysokosc dzwigni: " << i->lever << endl;
		if (i->currentValue >= i->valueWhenPurchased) { cout << "Zysk za sztuke: " << setprecision(4) << i->currentValue - i->valueWhenPurchased << "zl" << endl << endl; }
		else { cout << "Strata za sztuke: " << setprecision(4) << i->valueWhenPurchased - i->currentValue << "zl" << endl << endl; }
	}
}

void Client::showETFsList()
{
	cout << "Akcje: \n";
	list<ETF>::iterator i = this->clientETFs.begin();
	for (i; i != this->clientETFs.end(); i++)
	{
		cout << i->count << ". " << i->name << "\nCena za sztuke w momencie zakupu: " << setprecision(4) << i->valueWhenPurchased << "zl\nAktualna cena: " << setprecision(4) << i->currentValue << "zl" << endl;
		if (i->currentValue >= i->valueWhenPurchased) { cout << "Zysk za sztuke: " << setprecision(4) << i->currentValue - i->valueWhenPurchased << "zl" << endl << endl; }
		else { cout << "Strata za sztuke: " << setprecision(4) << i->valueWhenPurchased - i->currentValue << "zl" << endl << endl; }
	}
}



void Client::addToBalance(float amount_)
{
	this->balance += amount_;
}

void Client::sellTurbo(int count_, unique_ptr<list<Turbo>>& Clients_list_, list<Broker>::iterator Broker)
{
	int amount_;
	float current_value_, sum_, sum_2;
	auto p = this->clientTurbos.begin();
	{
		for (p; p != this->clientTurbos.end(); p++)
		{
			if (p->count == count_)
			{
				current_value_ = p->currentValue;
				cout << "Podaj ilosc certyfikatow jaka chcesz sprzedac. Aktualna ilosc to " << p->quantity; cin >> amount_;
				if (amount_ >= p->quantity) 
				{
					amount_ = p->quantity; 
					sum_ = amount_ * current_value_ * Broker->commision / 100;
					sum_2 = (amount_ * current_value_) - sum_;
					Broker->balance += sum_;
					this->balance += sum_2;
					this->clientTurbos.erase(p);
					system("CLS");
					cout << " Gratulacje! Twoje papiery wartosciowe zostaly sprzedane. Wracamy do Menu\n";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					return;
				}
				else if (amount_ < p->quantity)
				{
					p->quantity -= amount_;
					sum_ = amount_ * current_value_ * Broker->commision / 100;
					sum_2 = (amount_ * current_value_) - sum_;
					Broker->balance += sum_;
					this->balance += sum_2;
					system("CLS");
					cout << " Gratulacje! Twoje papiery wartosciowe zostaly sprzedane. Wracamy do Menu\n";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					return;
				}
				else
				{
					cout << "podales zla ilosc\n"; return;
				}
			}
		}
	}
}

void Client::sellETF(int count_, unique_ptr<list<ETF>>& Clients_list_, list<Broker>::iterator Broker)
{
	int amount_;
	float current_value_, sum_, sum_2;
	auto p = this->clientETFs.begin();
	{
		for (p; p != this->clientETFs.end(); p++)
		{
			if (p->count == count_)
			{
				current_value_ = p->currentValue;
				cout << "Podaj ilosc akcji jaka chcesz sprzedac. Aktualna ilosc to " << p->quantity; cin >> amount_;
				if (amount_ >= p->quantity)
				{
					amount_ = p->quantity;
					sum_ = amount_ * current_value_ * Broker->commision / 100;
					sum_2 = (amount_ * current_value_) - sum_;
					Broker->balance += sum_;
					this->balance += sum_2;
					this->clientETFs.erase(p);
					system("CLS");
					cout << " Gratulacje! Twoje papiery wartosciowe zostaly sprzedane. Wracamy do Menu\n";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					return;
				}
				else if (amount_ < p->quantity)
				{
					p->quantity -= amount_;
					sum_ = amount_ * current_value_ * Broker->commision / 100;
					sum_2 = (amount_ * current_value_) - sum_;
					Broker->balance += sum_;
					this->balance += sum_2;
					system("CLS");
					cout << " Gratulacje! Twoje papiery wartosciowe zostaly sprzedane. Wracamy do Menu\n";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					return;
				}
				else
				{
					cout << "podales zla ilosc\n"; return;
				}
			}
		}
	}
}

void Client::findAndChangeETFValue(unique_ptr<list<ETF>>& ETF_list)
{
	auto ETF_i = ETF_list->begin();
	for (ETF_i; ETF_i != ETF_list->end(); ETF_i++)
	{
		auto Client_i = this->clientETFs.begin();
		for (Client_i; Client_i != this->clientETFs.end(); Client_i++)
		{
			if (Client_i->count == ETF_i->count) { Client_i->currentValue = ETF_i->currentValue; break; }
		}
	}
	return;
}

void Client::findAndChangeTurboValue(unique_ptr<list<Turbo>>& Turbos_list)
{
	auto Turbo_i = Turbos_list->begin();
	for (Turbo_i; Turbo_i != Turbos_list->end(); Turbo_i++)
	{
		auto Client_i = this->clientTurbos.begin();
		for (Client_i; Client_i != this->clientTurbos.end(); Client_i++)
		{
			if (Client_i->count == Turbo_i->count) { Client_i->currentValue = Turbo_i->currentValue; break; }
		}
	}
	return;
}

void Client::printETF(unique_ptr<list<ETF>>& ETF_list)
{
	auto q = this->clientETFs.begin();
	for (q; q != this->clientETFs.end(); q++)
	{
		auto p = ETF_list->begin();
		for (p; p != ETF_list->end(); p++)
		{
			if (q->count == p->count)
			{
				fstream file;
				int i = 1;
				file.open(p->name + ".csv", ios::out);
				auto z = p->lastValues.begin();
				for (z; z != p->lastValues.end(); z++)
				{	
					int tmp = *z;
					file << i << ';' << tmp << endl;
					i++;
				}
				file.close();
			}
		}
	}
}

void Client::printTurbos(unique_ptr<list<Turbo>>& Turbos_list)
{
	fstream file;
	auto p = Turbos_list->begin();
	auto q = this->clientTurbos.begin();

	for (q; q != this->clientTurbos.end(); q++)
	{
		for (p; p != Turbos_list->end(); p++)
		{
			if (q->count == p->count)
			{
				int i = 1;
				file.open(p->name + ".csv", ios::out);
				auto z = p->lastValues.begin();
				for (z; z != p->lastValues.end(); z++)
				{
					int tmp = *z;
					file << i << ';' << tmp << endl;
					i++;
				}
			}
		}
	}
}

void Client::addValuesETF(unique_ptr<list<ETF>>& ETF_list, list<Client>::iterator& Client_)
{
	list<ETF>::iterator p = ETF_list->begin();
	for (p; p != ETF_list->end(); p++)
	{
		list<ETF>::iterator q = Client_->clientETFs.begin();
		for (q; q != this->clientETFs.end(); q++)
		{
			if (q->count == p->count)
			{
				auto z = q->lastValues;
				list<float>::iterator t = p->lastValues.begin();
				for (t; t != p->lastValues.end(); t++)
				{
					z.push_back(*t);
				}
			}
		}
	}
}

void Client::addValuesTurbo(unique_ptr<list<Turbo>>& Turbos_list)
{
	list<Turbo>::iterator p = Turbos_list->begin();
	for (p; p != Turbos_list->end(); p++)
	{
		list<ETF>::iterator q = this->clientETFs.begin();
		for (q; q != this->clientETFs.end(); q++)
		{
			if (q->count == p->count)
			{
				auto z = q->lastValues;
				list<float>::iterator t = p->lastValues.begin();
				for (t; t != p->lastValues.end(); t++)
				{
					z.push_back(*t);
				}
			}
		}
	}
}

void Client::stopLossETF(unique_ptr<list<ETF>>& ETF_list)
{
	if (this->clientETFs.size() == 0) { return; }
	float sum_;
	int amount_;
	auto p = this->clientETFs.begin();
	for (p; p != this->clientETFs.end(); p++)
	{
		auto q = ETF_list->begin();
		for (q; q != ETF_list->end(); q++)
		{
			if (p->count == q->count)
			{
				if (p->currentValue >= 2 * q->currentValue)
				{
					amount_ = p->quantity;
					sum_ = amount_ * q->currentValue;
					this->balance += sum_;
					this->clientETFs.erase(p);
					break;
				}
			}
		}
	}
}

void Client::brokersAdvice(unique_ptr<list<ETF>>& ETF_list, unique_ptr<list<Turbo>>& Turbos_list)
{
	float last = 0;
	float last_100_avg = 0;
	auto p = this->clientETFs.begin();
	cout << "Akcje: \n";
	for (p; p != this->clientETFs.end(); p++)
	{
		auto y = ETF_list->begin();
		for (y; y != ETF_list->end(); y++)
		{
			if (y->count == p->count)
			{
				cout << y->name << ": \n";
				auto q = y->lastValues.begin();
				for (int i = 0; i < 100; i++, q++)
				{
					last_100_avg += *q;
					if (i >= 90) { last += *q; }
				}
				last_100_avg /= 100;
				last /= 10;
				if (last > last_100_avg) { cout << "Prognozowany wzrost \n"; }
				else { cout << "Prognozowany spadek \n"; }
			}
		}
	}
	cout << endl << endl;

	cout << "Certyfikaty Turbo: \n";
	last_100_avg = 0;
	last = 0;
	auto z = this->clientTurbos.begin();
	for (z; z != this->clientTurbos.end(); z++)
	{
		auto w = Turbos_list->begin();
		for (w; w != Turbos_list->end(); w++)
		{
			if (z->count == w->count)
			{
				cout << w->name << ": \n";
				auto q = w->lastValues.begin();
				for (int i = 0; i < 100; i++, q++)
				{
					last_100_avg += *q;
					if (i >= 90) { last += *q; }
				}
				last_100_avg /= 100;
				last /= 10;
				if (last > last_100_avg) { cout << "Prognozowany wzrost \n"; }
				else { cout << "Prognozowany spadek \n"; }
			}
		}
	}
}