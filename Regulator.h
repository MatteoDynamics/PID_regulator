#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
class Regulator
{
	float temperature;
public:
	virtual void steering(float temperature_zadana, float time_probing) =0;
	
};

