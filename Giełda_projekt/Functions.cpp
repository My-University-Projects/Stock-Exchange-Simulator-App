#pragma once
#include"Functions.h"
#include"ETF.h"
#include"Turbo.h"
#include<regex>

bool checkString(string text)										// funkcja sprawdza, czy w danym tekscie jest jakas cyfra
{
	if (regex_search(text, regex("[[:blank:]|[:cntrl:]|[:punct:]]|[0-9]"))) { return false; }
	return true;
}

bool checkIfAdult(int day, int month, int year)										// funkcja sprawdza, czy osoba rejestrujaca sie jest pelnoletnia oraz czy zostaly podane prawidlowe dane
{
	if ((day > 31 || day < 1) || (month > 12 || month < 1)) { return false; }
	time_t birth_date = (year * 365) + (month * 30) + day;
	time_t today_date;
	time(&today_date);
	today_date /= 86400;
	today_date += 719050;
	if ((today_date - birth_date) < 6551) { return false; }
	return true;
}

bool checkCardNumber(string card_nb_)
{
	if (regex_search(card_nb_, regex("[[:blank:]|[:cntrl:]|[:punct:]]|[a-z]")) || card_nb_.length() != 16) { return false; }
	return true;
}

bool checkPassword(string password)
{
	if (!regex_match(password, regex(".{8,}")) || (!regex_search(password, regex("[[:upper:]]+")) || !regex_search(password, regex("[[:d:]]+")) || !regex_search(password, regex("[[:lower:]]+")) || regex_search(password, regex("[[:blank:]|[:cntrl:]|[:punct:]]"))))
	{
		cout << "Twoje haslo nie spelnia nastepujacych punktow: \n";
		if (!regex_match(password, regex(".{8,}"))) { cout << "Haslo powinno zawierac co najmniej 8 znakow\n"; }
		if (!regex_search(password, regex("[[:upper:]]+"))) { cout << "Haslo powinno zawierac conajmniej 1 duza litere\n"; }
		if (!regex_search(password, regex("[[:d:]]+"))) { cout << "Haslo powinno zawierac co najmniej 1 cyfre\n"; }
		if (!regex_search(password, regex("[[:lower:]]+"))) { cout << "Haslo powinno zawierac conajmniej 1 mala litere\n"; }
		if (regex_search(password, regex("[[:blank:]|[:cntrl:]|[:punct:]]"))) { cout << "haslo nie moze zawierac znakow specjalnych / przestankowych / bialych\n"; }
		return false;
	}
	return true;
}


