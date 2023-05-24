#include "Grzejnik.h"

void Grzejnik::set_current_power(float current_power)
{
	if (current_power < 0)
	{
		current_power = 0;
	}
	else if (current_power > 1)
	{
		current_power = 1;
	}
	this->current_power = current_power;
}