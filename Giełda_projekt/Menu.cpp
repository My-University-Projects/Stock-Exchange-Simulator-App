#pragma once
#include "Menu.h"
#include"File_operations.h"
#include"Brokers_operations.h"
#include"Clients_operations.h"
#include"ETF_operations.h"
#include"Turbos_operations.h"

void update_Turbos_values(unique_ptr<list<Turbo>>& Turbos_list, bool& flag);

void update_values(unique_ptr<list<ETF>>& ETF_list, bool& flag);

void check_stop_loss(unique_ptr<list<Client>>& Clients, unique_ptr<list<ETF>>& ETF_list, bool& flag);

void Menu::start_user(bool& flag_, unique_ptr<list<Client>>& Clients_list, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list,unique_ptr<list<ETF>>& ETF_list_, const Font& font)
{
	string name, surname, password;
	char choose;
	int choose_;

	while (1)
	{
		system("CLS");
		cout << "Wybrales opcje logowania na konto klienta\n";
		cout << "Podaj swoje imie: "; cin >> name; cout << endl;
		cout << "Podaj swoje nazwisko: "; cin >> surname; cout << endl;
		cout << "Podaj haslo do swojego konta: "; cin >> password; cout << endl;
		if (!Clients_operations::check_user(name, surname, password, Clients_list)) { cout << "Uzyles nieprawidlowych danych logowania. Sprobuj jeszcze raz."; Sleep(3000); }
		else { break; }
	}

	list<Client>::iterator user_ = Clients_operations::find_Client(Clients_list, name, surname, password);
	list<Broker>::iterator Broker_ = Brokers_operations::find_Broker(user_->Brokers_id, Brokers_list);

	user_->find_and_change_ETF_value(ETF_list_);
	user_->find_and_change_Turbo_value(Turbos_list);
	user_->add_values_ETF(ETF_list_, user_);
	user_->add_values_Turbo(Turbos_list);
	
	while (1)
	{
		system("CLS");
		cout << "Witamy " << user_->get_name() << endl;
		cout << "Twoje aktualne saldo: " << setprecision(4) << user_->balance << "zl\n";
		cout << "Co chcesz zrobic? Wybierz numer odpowiedniej opcji\n";
		cout << "0. Sprawdz porady maklera\n";
		cout << "1. Doladowanie saldo\n";
		cout << "2. Zakup akcji\n";
		cout << "3. Sprzedaz akcji\n";
		cout << "4. Sprawdz stan twoich papierow wartosciowych\n";
		cout << "5. Sprawdz aktualny stan rynku\n";
		cout << "6. Zmien maklera\n";
		cout << "7. Drukuj wykresy notowan twoich akcji\n";
		cout << "8. Drukuj wykresy notowan twoich certyfikatow Turbo\n";
		cout << "9. Wyloguj sie\n";
		cout << "Twoj wybor: ";  cin >> choose;

		switch (choose)
		{
		case '1':
		{
			float amount;
			while (1)
			{
				system("CLS");
				cout << "Wybrales opcje doladowania twojego konta.\n";
				cout << "Wpisz kwote, na jaka chcesz doladowac konto (maksymalnie 10000zl): "; cin >> amount;
				if (cin.fail() || amount > 10000) { cin.clear(); cout << "Wybrales zla kwote sprobuj jeszcze raz\n"; Sleep(3000); }
				else { break; }
			}
			user_->add_to_balance(amount);
			cout << "Konto zostalo doladowane\n"; for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); } break;
		}
		case '2':
		{
			bool flag = false;
			while (1)
			{
				system("CLS");
				cout << "Wybrales opcje zakupu akcji." << endl;
				cout << " Jaki rodzaj papierow wartosciowych chcesz kupic?\n";
				cout << "1. Certyfikaty Turbo\n2. Akcje\n";
				cout << "Twoj wybor: ";  cin >> choose;
				switch (choose)
				{
				case '1':
				{
					while (1)
					{
						system("CLS");
						Turbos_operations::show_list(Turbos_list);
						cout << "Wybierz numer certyfikatu, ktorego kupno chcesz zlecic: "; cin >> choose_;
						if (choose_ > 32 || choose_ < 1 || isdigit(choose_)) { cin.clear(); cout << "Wybrales zly numer. Sprobuj jeszcze raz"; Sleep(3000); }
						else { break; }
					}
					user_->buy_Turbo(choose_, Turbos_list, Broker_);
					flag = true;
					break;
				}
				case '2':
				{
					while (1)
					{
						system("CLS");
						ETF_operations::show_list(ETF_list_);
						cout << "Wybierz numer akcji, ktorej kupno chcesz zlecic: "; cin >> choose_;
						if (choose_ > 8 || choose_ < 1 || isdigit(choose_)) { cin.clear(); cout << "Wybrales zly numer. Sprobuj jeszcze raz"; Sleep(3000); }
						else { break; }
					}
					user_->buy_ETF(choose_, ETF_list_, Broker_);
					flag = true;
					break;
				}
				default:
				{
					cout << "Wybrales zla opcje. Sprobuj jeszcze raz.";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					break;
				}
				}
				if (flag == true) { break; }
			}
			break;
		}
		case '3':
		{
			bool flag = false;
			while (1)
			{
				system("CLS");
				cout << "Wybrales opcje sprzedazy akcji." << endl;
				cout << " Jaki rodzaj papierow wartosciowych chcesz sprzedac?\n";
				cout << "1. Certyfikaty Turbo\n2. Akcje\n";
				cout << "Twoj wybor: ";  cin >> choose;
				switch (choose)
				{
				case '1':
				{
					while (1)
					{
						system("CLS");
						user_->show_Turbos_list();
						cout << "Wybierz numer certyfikatu, ktorego sprzedaz chcesz zlecic: "; cin >> choose_;
						if (isdigit(choose_)) { cin.clear(); cout << "Wybrales zly numer. Sprobuj jeszcze raz"; Sleep(3000); }
						else { break; }
					}
					user_->sell_Turbo(choose_, Turbos_list, Broker_);
					flag = true;
					break;
				}
				case '2':
				{
					while (1)
					{
						system("CLS");
						user_->show_ETFs_list();
						cout << "Wybierz numer akcji, ktorej sprzedaz chcesz zlecic: "; cin >> choose_;
						if (isdigit(choose_)) { cin.clear(); cout << "Wybrales zly numer. Sprobuj jeszcze raz"; Sleep(3000); }
						else { break; }
					}
					user_->sell_ETF(choose_, ETF_list_, Broker_);
					flag = true;
					break;
				}
				default:
				{
					cout << "Wybrales zla opcje. Sprobuj jeszcze raz.";
					for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
					break;
				}
				}
				if (flag == true) { break; }
			}
			break;
		}
		case '4':
		{
			system("CLS");
			char x;
			user_->show_Turbos_list();
			cout << "\n\n";
			user_->show_ETFs_list();
			cout << "Wcisnij dowolny przycisk aby przejsc dalej "; cin >> x;
			break;
		}
		case '5':
		{
			system("CLS");
			cout << "Oto aktualny stan rynku: \n\n";
			Turbos_operations::show_list(Turbos_list);
			cout << endl << endl;
			ETF_operations::show_list(ETF_list_);
			cout << endl << endl;
			char x;
			cout << "Wcisnij dowolny przycisk aby przejsc dalej "; cin >> x;
			break;
		}
		case '6':
		{
			while (1)
			{
				system("CLS");
				cout << "Wybrales opcje zmiany maklera\n";
				Brokers_operations::show_Clients_Broker(user_->Brokers_id, Brokers_list);
				cout << endl;
				cout << "Oto lista naszych maklerow. Wybierz numer nowego maklera " << endl;
				Brokers_operations::show_Brokers(Brokers_list);
				cout << endl; cin >> choose_;
				if (choose_ > 5 || choose_ < 1 || isdigit(choose_)) { cout << "Podales zly wybor. Sprobuj jeszcze raz"; Sleep(3000); }
				else { break; }
			}
			list<Broker>::iterator Broker_ = Brokers_operations::find_Broker(user_->Brokers_id, Brokers_list);
			Broker_->delete_from_Clients_base(user_->Brokers_id, user_->get_name(), user_->get_surname());
			user_->Brokers_id = choose_;
			Clients_base<string> Client(user_->get_name(), user_->get_surname()); 
			Brokers_operations::find_Broker_and_add_Client(user_->Brokers_id, Client, Brokers_list);
			cout << "Makler zostal pomyslnie zmieniony.\n"; for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); } break;
		}
		case '7':
		{
			system("CLS");
			user_->show_ETFs_list();
			cout << "Wcisnij numer akcji, ktorej wykres chcesz przegladac:  "; cin >> choose_;
			print_Plot_ETF(ETF_list_,  choose_, font);
			break;
		}
		case '8':
		{
			system("CLS");
			user_->show_Turbos_list();
			cout << "Wcisnij numer certyfikatu, ktorego wykres chcesz przegladac:  "; cin >> choose_;
			print_Plot_Turbo(Turbos_list, choose_, font);
			break;
		}
		case '9':
		{
			flag_ = true;
			cout << "Dziekujemy za twoja obecnosc! Do widzenia :)\n";
			for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
			return;
		}
		case '0':
		{
			system("CLS");
			char x;
			user_->Brokers_advice(ETF_list_, Turbos_list);
			cout << "Nacisnij dowolny przycisk aby wrocic do menu: "; cin >> x;
			break;
		}
		default: 
		{ 
			cout << "Wybrales zla opcje. Sprobuj jeszcze raz\n"; Sleep(3000); break; 
		}
		}
	}
}

void Menu::new_user(unique_ptr<list<Client>>& Clients_list, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_)
{
	string name, surname, card_nb, password;
	int choose, day, month, year, Brokers_id;
	while (1)
	{
		system("CLS");
		cout << "Wybrales opcje rejestacji uzytkownika.\n Podaj swoje imie: "; cin >> name;
		if (!checkstring(name)) { cout << "Podales zle imie. Sprobuj jeszcze raz"; Sleep(3000); }
		else { break; }
	}
	while (1)
	{
		cout << "\nPodaj swoje nazwisko: "; cin >> surname;
		if (!checkstring(surname)) { cout << "Podales zle nazwisko. Sprobuj jeszcze raz"; Sleep(3000); }
		else { break; }
	}
	while (1)
	{
		cout << "\nPodaj swoja date urodzenia(dd.mm.rrrr):\nDzien [1 - 31] -  "; cin >> day;
		cout << "Miesiac[1- 12] - "; cin >> month; cout << "Rok - "; cin >> year;
		if (!check_if_adult(day, month, year)) { cout << "Podales zla date. Sprobuj jeszcze raz"; Sleep(3000); }
		else { break; }
	}
	while (1)
	{
		system("CLS");
		cout << " Oto lista naszych maklerow, ktorzy pomoga ci w inwestycjach\n\nWcisnij odpowiedni numer aby wybrac danego maklera\n\n";
		Brokers_operations::show_Brokers(Brokers_list);
		cout << "Twoj wybor: "; cin >> choose;
		if (choose > 5 || choose < 0 || isdigit(choose)) { cout << "Podales zly wybor. Sprobuj jeszcze raz"; Sleep(3000); }
		else { Brokers_id = Brokers_operations::get_id(choose, Brokers_list); break; }
	}
	while (1)
	{
		system("CLS");
		cout << "Nastepnie podaj numer karty kredytowej, dzieki czemu bedziesz mogl doladowac swoje saldo - ";
		cin >> card_nb;
		if (!check_card_nb(card_nb)) { cout << "Podales zly numer karty. Sprobuj jeszcze raz."; Sleep(3000); }
		else { break; }
	}
	while (1)
	{
		system("CLS");
		cout << "Na koncu stworz haslo do swojego konta. Pamietaj, aby twoje haslo bylo silne\n";
		cout << "Haslo: "; cin >> password;
		if (!check_password(password)) { Sleep(3000); }
		else { break; }
	}

	Client new_Client(name, surname, password, card_nb, Brokers_id);
	Clients_base<string> Client(name, surname);//////////////////////////////////////////
	Clients_list->push_back(new_Client);
	Brokers_operations::find_Broker_and_add_Client(Brokers_id, Client, Brokers_list);
	cout << "Twoje konto zostalo zalozone!\n";
	cout << "Wracamu do menu glownego\n"; for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
	return;
}

void Menu::start_Broker(bool& flag, unique_ptr<list<Client>>& Clients_list, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_, const Font& font)
{
	string name, surname, password;
	char choose;
	while (1)
	{
		system("CLS");
		cout << "Wybrales opcje logowania na konto maklera\n";
		cout << "Podaj swoje imie: "; cin >> name; cout << endl;
		cout << "Podaj swoje nazwisko: "; cin >> surname; cout << endl;
		cout << "Podaj haslo do swojego konta: "; cin >> password; cout << endl;
		if (!Brokers_operations::check_user(name, surname, password, Brokers_list)) { cout << "Uzyles nieprawidlowych danych logowania. Sprobuj jeszcze raz."; Sleep(3000); }
		else { break; }
	}
	auto user = Brokers_operations::find_Broker(name, surname, password, Brokers_list);
	while (1)
	{
		int choose_;
		char x;
		system("CLS");
		cout << "Witamy " << user->get_name() << "  Twoje aktualne zyski: " << setprecision(5) << user->balance << "zl" << endl;
		cout << "Co chcesz zrobic? Wybierz numer odpowiedniej opcji: \n";
		cout << "1. Lista twoich klientow\n";
		cout << "2. aktualny stan rynku\n";
		cout << "3. Drukuj wykres notowan akcji\n";
		cout << "4. Drukuj wykres notowan certyfikatow Turbo\n";
		cout << "5. Wyloguj sie\n"; 
		cout << "Twoj wybor: "; cin >> choose;
		switch (choose)
		{
		case '1':
		{
			system("CLS");
			user->show_Brokers_Clients();
			cout << "Wcisnij dowolny przycisk aby przejsc dalej "; cin >> x;
			break;
		}
		case '2': 
		{
			system("CLS");
			cout << "Oto aktualny stan rynku: \n\n";
			Turbos_operations::show_list(Turbos_list_);
			cout << endl << endl;
			ETF_operations::show_list(ETF_list_);
			cout << endl << endl;
			cout << "Wcisnij dowolny przycisk aby przejsc dalej "; cin >> x;
			break;
		}
		case '3':
		{
			system("CLS");
			ETF_operations::show_list(ETF_list_);
			
			cout << "Wcisnij numer akcji, ktorej wykres chcesz przegladac:  "; cin >> choose_;
			Menu::print_Plot_ETF(ETF_list_, choose_, font);
			break;
		}
		case '4':
		{
			Turbos_operations::show_list(Turbos_list_);
			cout << "Wcisnij numer certyfikatu, ktorego wykres chcesz przegladac:  "; cin >> choose_;
			Menu::print_Plot_Turbo(Turbos_list_, choose_, font);
			break;
		}
		case '5':
		{
			flag = true;
			cout << "Dziekujemy za twoja obecnosc! Do widzenia :)\n";
			for (int i = 0; i < 3; i++) { cout << "."; Sleep(750); }
			return;
		}
		default:
		{
			system("CLS");
			cout << "Wybrales nieprawidlowa opcje. Sprobuj jeszcze raz\n"; Sleep(3000);
			break;
		}
		}
 	}
}

void Menu::start_program(unique_ptr<list<Client>>& Clients_list, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list, unique_ptr<list<ETF>>& ETF_list, bool& stop_thread_1, const Font& font)
{
	int choose;
start:	system("CLS");
	cout << "Witamy w domu maklerskim TK\n";
	cout << "Menu glowne - wybierz co chcesz zrobic wciskajac odpowiedni klawisz\n\n";
	cout << "1. Rejestracja nowego uzytkownika\n";
	cout << "2. Logowanie na konto\n";
	cout << "3. Wyjscie z programu\n";
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		Menu::new_user(Clients_list, Brokers_list, Turbos_list, ETF_list);
		goto start;
	}
	case 2:
	{
		while (1)
		{
			int choose_;
			bool flag = false;
			system("CLS");
			cout << "Wybrales opcje logowania.\n";
			cout << "Wybierz rodzaj konta na jakie chcesz sie zalogowac:\n";
			cout << "1. Konto maklerskie\n";
			cout << "2. Konto klienta\n";
			cin >> choose_;
			switch (choose_)
			{
			case 1:
			{
				while (1)
				{
					stop_thread_1 = true;
					Menu::start_Broker(flag, Clients_list, Brokers_list, Turbos_list, ETF_list, font);
					stop_thread_1 = false;
					thread t1(update_values, ref(ETF_list), ref(stop_thread_1));
					t1.detach();
					thread t2(update_Turbos_values, ref(Turbos_list), ref(stop_thread_1));
					t2.detach();
					if (flag == true) { goto start; }
				}
			}
			case 2:
			{
				while (1)
				{
					stop_thread_1 = true;
					Menu::start_user(flag, Clients_list, Brokers_list, Turbos_list, ETF_list, font);
					stop_thread_1 = false;
					thread t1(update_values, ref(ETF_list), ref(stop_thread_1));
					t1.detach();
					thread t2(update_Turbos_values, ref(Turbos_list), ref(stop_thread_1));
					t2.detach();
					thread t3(check_stop_loss, ref(Clients_list), ref(ETF_list), ref(stop_thread_1));
					t3.detach();
					if (flag == true) { goto start; }
				}
			}
			default: cout << "Wybrales zla opcje. Sprobuj jeszcze raz\n"; Sleep(3000); break;
			}
		}
		break;
	}
	case 3:
	{
		stop_thread_1 = true;
		Files_operations::put_data_in_file(Brokers_list);
		Files_operations::put_data_in_file(Clients_list);
		Files_operations::put_Turbos_in_file(Turbos_list);
		Files_operations::put_ETF_in_file(ETF_list);
		Menu::delete_lists(Clients_list, Brokers_list, Turbos_list, ETF_list);
		return ;
	}
	default:
	{
		cout << "Wybrales niepoprawna opcje. Sprobuj jeszcze raz."; Sleep(3000); break;
	}
	}
}

void Menu::print_Plot_ETF(unique_ptr<list<ETF>>& ETF_list_, int count_, const Font& font)
{
	float tmp[100];
	auto q = ETF_list_->begin();
	for (q; q != ETF_list_->end(); q++)
	{
		if (q->count == count_) 
		{
			auto p = q->last_values.begin();
			int i = 0;
			for (p; p != q->last_values.end(); p++) { tmp[i] = *p; i++; }
			break;
		}
	}
	Plot chart;
	chart.zero = Vector2f(100, 100);
	chart.configxy(tmp);
	const string text("Wykres - " + q->name);
	RenderWindow w(VideoMode(1600, 1080), text);
	while (w.isOpen())
	{
		Event event;
		while (w.pollEvent(event))
		{
			//zamykanie okna:
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				w.close();
		}
		//czyœæ ekran:
		w.clear(sf::Color::Black);
		//poka¿:
		draw(w, chart, font, tmp);
		w.display();
	}
}

void Menu::print_Plot_Turbo(unique_ptr<list<Turbo>>& Turbos_list_, int count_, const Font& font)
{
	float tmp[100];
	auto q = Turbos_list_->begin();
	for (q; q != Turbos_list_->end(); q++)
	{
		if (q->count == count_)
		{
			auto p = q->last_values.begin();
			int i = 0;
			for (p; p != q->last_values.end(); p++) { tmp[i] = *p; i++; }
			break;
		}
	}
	Plot chart;
	chart.zero = Vector2f(100, 100);
	chart.configxy(tmp);
	const string text("Wykres - " + q->name);
	RenderWindow w(VideoMode(1600, 1080), text);
	while (w.isOpen())
	{
		Event event;
		while (w.pollEvent(event))
		{
			//zamykanie okna:
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				w.close();
		}
		//czyœæ ekran:
		w.clear(sf::Color::Black);
		//poka¿:
		draw(w, chart, font, tmp);
		w.display();
	}
}

void Menu::delete_lists(unique_ptr<list<Client>>& user_, unique_ptr<list<Broker>>& Brokers_list, unique_ptr<list<Turbo>>& Turbos_list_, unique_ptr<list<ETF>>& ETF_list_)
{
	user_->erase(user_->begin(), user_->end());
	Brokers_list->erase(Brokers_list->begin(), Brokers_list->end());
	Turbos_list_->erase(Turbos_list_->begin(), Turbos_list_->end());
	ETF_list_->erase(ETF_list_->begin(), ETF_list_->end());
}