#pragma once
#include"Person.h"


Person::Person()
{}
Person::Person(string name_, string surname_) : name(name_), surname(surname_)
{}
Person::~Person()
{}
void Person::setName(string name_)
{
	this->name = name_;
}
string Person::getName()
{
	return this->name;
}
void Person::setSurname(string surname_)
{
	this->surname = surname_;
}
string Person::getSurname()
{
	return this->surname;
}