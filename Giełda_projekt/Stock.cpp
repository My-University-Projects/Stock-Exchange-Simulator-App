#pragma once
#include "Stock.h"

Stock::Stock()
{}
Stock::Stock(string name_, float current_value_, int count_) : valueWhenPurchased(current_value_), currentValue(current_value_), name(name_), count(count_)
{
	this->quantity = 0;
}
Stock::~Stock()
{}
Stock::Stock(string name_, float current_value_, int count_, int quantity_) : valueWhenPurchased(current_value_), currentValue(current_value_), name(name_), count(count_), quantity(quantity_)
{}
Stock::Stock(string name_, float current_value_, int count_, int quantity_, float value_when_purchased_) : valueWhenPurchased(value_when_purchased_), currentValue(current_value_), name(name_), count(count_), quantity(quantity_)
{}
void Stock::changeCurrentValue(float new_value_)
{
	this->currentValue = new_value_;
	return;
}