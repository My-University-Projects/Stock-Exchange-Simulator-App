#pragma once
#include "ETF.h"

ETF::ETF()
{}

ETF::ETF(string name_, float current_value_, int count_, list<float> last_values_) : Stock(name_, current_value_, count_)
{
	this->quantity = 0;
	this->lastValues.swap(last_values_);
}

ETF::ETF(string name_, float current_value_, int count_, int quantity_) : Stock(name_, current_value_, count_, quantity_)
{}

ETF::ETF(string name_, float current_value_, int count_, int quantity_, float value_when_purchased_) : Stock(name_, current_value_, count_, quantity_, value_when_purchased_)
{}

ETF::~ETF()
{
	this->lastValues.erase(lastValues.begin(), lastValues.end());
}

void ETF::changeCurrentValue(float current_value_)
{
	this->currentValue = current_value_;
}


