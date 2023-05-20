#pragma once
class Regulator
{
	float temperature;
public:
	virtual float steering(float temperature_zadana, float measured_temp, float time_probing) =0;
	
};

