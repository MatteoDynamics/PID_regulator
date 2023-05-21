#pragma once
#include "Pomieszczenie.h"

class Grzejnik
{
	const float nominal_power;
	float current_power;
public:
	Grzejnik(float power) : nominal_power(power), current_power(1) {};
	float get_nominal_power() const { return nominal_power; };
	void set_current_power(float current_power)
	{
		if (current_power < 0)
		{
			current_power = 0;
		}
		else if(current_power>1)
		{
			current_power = 1;
		}
		this->current_power = current_power;
	}
	float power()
	{
		return current_power * nominal_power;
	}
};

