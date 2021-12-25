#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include <iostream>
#include<list>
#include<Windows.h>
#include<time.h>
#include<fstream>
#include<memory>
#include<thread>
#include <cstdlib>
#include <iomanip>
#include<iterator>

using namespace sf;
using namespace std;

/*
* Abstract class representanting a person
*/
class Person
{
	friend class Menu;

	string name;
	string surname;

public:

	/*
	* No args contructor
	*/
	Person();												

	/*
	* 2- args constructor
	*/
	Person(string name_, string surname_);				

	/*
	* Destructor
	*/
	~Person();												

	/*
	* Getter of the name
	*/
	string getName();										

	/*
	* Name setter
	*/
	void setName(string name_);						

	/*
	* surname getter
	*/
	string getSurname();									

	/*
	* surname setter
	*/
	void setSurname(string surname_);					

};
