#pragma once
#include "Regulator.h"

class RegulatorBB :public Regulator
{
	public:
	float steering(float temperature_zadana, float measured_temp, float time_probing)
	{
		if (temperature_zadana > measured_temp)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

