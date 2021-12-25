#pragma once
#include"Turbo.h"

Turbo::Turbo(string name_, string type_, float current_value_, int lever_, int count_, list<float> last_values_) : Stock(name_, current_value_, count_), lever(lever_), type(type_)
{
	this->last_values.swap(last_values_);
}
Turbo::~Turbo()
{
	this->last_values.erase(last_values.begin(), last_values.end());
}
Turbo::Turbo(string name_, string type_, float current_value_, int lever_, int count_, int quantity_) : Stock(name_, current_value_, count_, quantity_), lever(lever_), type(type_)
{}
Turbo::Turbo(string name_, string type_, float current_value_, int lever_, int count_, int quantity_, float value_when_purchased_) : Stock(name_, current_value_, count_, quantity_ , value_when_purchased_), lever(lever_), type(type_)
{}

void Turbo::change_current_value(float current_value_)
{
	this->current_value = current_value_;
}

