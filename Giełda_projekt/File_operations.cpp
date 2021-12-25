#include"File_operations.h"

void FilesOperations::loadDataFromFile(unique_ptr<list<Client>>& Clients_list)
{
	fstream file;
	file.open("Baza_danych_klientow.bin", ios::in, ios::binary);
	try
	{
		if (!file.good()) { throw 2; }
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (int)
	{
		exit(-1);
	}


	string name_, surname_, password_, credit_card_, type_;
	int Brokers_id_, count_, quantity_, lever_;
	float balance_, current_value_, value_when_purchased_;
	while (file >> name_)
	{
		file >> surname_ >> password_ >> credit_card_ >> Brokers_id_ >> balance_;
		Client tmp(name_, surname_, password_, credit_card_, Brokers_id_, balance_);
		Clients_list->push_front(tmp);
		list<Client>::iterator i = Clients_list->begin();
		while (1)
		{
			file >> name_;
			if (name_ == "end") { break; }
			file >> count_ >> type_ >> lever_ >> quantity_ >> current_value_ >> value_when_purchased_;
			Turbo tmp(name_, type_, current_value_, lever_, count_, quantity_, value_when_purchased_);
			i->clientTurbos.push_front(tmp);
		}
		while (1)
		{
			file >> name_;
			if (name_ == "end") { break; }
			file >> count_ >> quantity_ >> current_value_ >> value_when_purchased_;
			ETF tmp(name_, current_value_, count_, quantity_, value_when_purchased_);
			i->clientETFs.push_front(tmp);
		}
	}

}

void FilesOperations::putDataInFile(unique_ptr<list<Client>>& Clients_list_)
{
	fstream file;
	file.open("Baza_danych_klientow.bin", ios::out, ios::binary);
	if (!file.good()) { cout << "nie udalo sie otworzyc pliku!\n"; return; }
	else
	{
		list<Client>::iterator i = Clients_list_->begin();
		for (i; i != Clients_list_->end(); i++)
		{
			file << i->getName() << " " << i->getSurname() << " " << i->password << " " << i->creditCard << " ";
			file << i->Brokers_id << " " << i->balance << "\n";
			list<Turbo>::iterator p = i->clientTurbos.begin();
			for (p; p != i->clientTurbos.end(); p++)
			{
				file << p->name << " " << p->count << " " << p->type << " " << p->lever << " " << p->quantity << " ";
				file << p->valueWhenPurchased << " " << p->currentValue << " ";
			}
			file << "end\n";
			list<ETF>::iterator q = i->clientETFs.begin();
			for (q; q != i->clientETFs.end(); q++)
			{
				file << q->name << " " << q->count << " " << q->quantity << " " << q->currentValue << " " << q->valueWhenPurchased << " ";
			}
			file << "end\n";
		}
	}
}

void FilesOperations::loadDataFromFile(unique_ptr<list<Broker>>& Brokers_list)
{
	fstream file;
	file.open("Baza_danych_maklerow.bin", ios::in, ios::binary);
	try
	{
		if (!file.good()) { throw 3; }
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (int)
	{
		exit(-1);
	}

	string name_, surname_, password_, Clients_name_, Clients_surname_;
	float balance_;
	int id_, commision_;
	while (file >> name_)
	{
		file >> surname_;
		file >> id_;
		file >> password_;
		file >> balance_;
		file >> commision_;
		Broker tmp(name_, surname_, password_, id_, commision_, balance_);
		(*Brokers_list).push_front(tmp);
		list<Broker>::iterator i = (*Brokers_list).begin();
		while (file >> Clients_name_)
		{
			if (Clients_name_ == "end") { break; }
			file >> Clients_surname_;
			i->clientsBasepHead->addToBase(i->clientsBasepHead, Clients_name_, Clients_surname_);
		}
	}
	file.close();
}

void FilesOperations::putDataInFile(unique_ptr<list<Broker>>& Brokers_list)
{
	fstream file;
	file.open("Baza_danych_maklerow.bin", ios::out, ios::binary);
	if (!file.good()) { cout << "Nie udalo sie otworzyc pliku." << endl; return; }
	else
	{
		list<Broker>::iterator i = (*Brokers_list).begin();
		for (i; i != (*Brokers_list).end(); i++)
		{
			file << i->getName() << " ";
			file << i->getSurname() << " ";
			file << i->id << " ";
			file << i->password << " ";
			file << i->balance << " ";
			file << i->commision << "\n";
			ClientsBase<string>* p = i->clientsBasepHead; ////////////////////////////////////////////////
			if (p == nullptr) { file << "end\n"; }
			while (p)
			{
				file << p->name << " ";
				file << p->surname << " ";
				if (p->pNext == nullptr) { file << "end\n"; break; }
				p = p->pNext;
			}
		}
	}
}

void FilesOperations::loadTurboFromFile(unique_ptr<list<Turbo>>& Stocks_list)
{
	fstream file;
	file.open("Baza_danych_akcji_Turbo.bin", ios::in, ios::binary);
	try
	{
		if (!file.good()) { throw 4; }
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (int)
	{
		exit(-1);
	}
	string type_, name_, tmp_2;
	int count_ = 1;
	int lever_;
	float value_;
	while (file >> name_)
	{
		list<float> tmp;
		float tmp_;
		file >> type_ >> value_ >> lever_;
		for (int i = 0; i < 100; i++)
		{
			file >> tmp_2;
			tmp_ = atof(tmp_2.c_str());
			tmp.push_back(tmp_);
		}
		Turbo new_Turbo(name_, type_, value_, lever_, count_, tmp);
		Stocks_list->push_back(new_Turbo);
		count_++;
	}
	file.close();
	return;
}

void FilesOperations::loadETFFromFile(unique_ptr<list<ETF>>& ETF_list)
{
	fstream file;
	file.open("Baza_danych_akcji_ETF.bin", ios::in, ios::binary);
	try
	{
		if (!file.good()) { throw 5; }
	}
	catch (runtime_error& error)
	{
		cout << error.what() << endl;
	}
	catch (int)
	{
		exit(-1);
	}
	int count_ = 1;
	string name_, tmp_2;
	float current_value_;
	while (file >> name_)
	{
		file >> current_value_;
		list<float> tmp;
		float tmp_;
		for (int i = 0; i < 100; i++)
		{
			file >> tmp_2;
			if (tmp_2 == "end") { break; }
			tmp_ = atof(tmp_2.c_str());
			tmp.push_back(tmp_);
		}
		ETF etf(name_, current_value_, count_, tmp);
		ETF_list->push_back(etf);
		count_++;
	}
	file.close();
	return;
}

void FilesOperations::putTurbosInFile(unique_ptr<list<Turbo>>& Turbos_list)
{
	fstream file;
	file.open("Baza_danych_akcji_Turbo.bin", ios::out, ios::binary);
	if (!file.good()) { cout << "Nie mozna otworzyc pliku!\n"; return; }
	else
	{
		auto p = Turbos_list->begin();
		for (p; p != Turbos_list->end(); p++)
		{
			file << p->name << " " << p->type << " " << p->currentValue << " " << p->lever << endl;
			auto q = p->lastValues.begin();
			for (q; q != p->lastValues.end(); q++) { file << *q << " "; }
		}
		file.close();
		return;
	}
}

void FilesOperations::putETFInFile(unique_ptr<list<ETF>>& ETF_list)
{
	fstream file;
	file.open("Baza_danych_akcji_ETF.bin", ios::out, ios::binary);
	if (!file.good()) { cout << "Nie mozna otworzyc pliku!\n"; return; }
	else
	{
		auto p = ETF_list->begin();
		for (p; p != ETF_list->end(); p++)
		{
			file << p->name << " " << p->currentValue << endl;
			auto q = p->lastValues.begin();
			for (q; q != p->lastValues.end(); q++) { file << *q << " "; }
		}
		file.close();
		return;
	}
}