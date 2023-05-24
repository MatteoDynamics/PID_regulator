#include "RegulatorBB.h"
void RegulatorBB::steering(float temperature_zadana, float time_probing)
{
	if (pomieszczenie == nullptr || grzejnik == nullptr)
	{
		throw std::exception();
	}
	pomieszczenie->aktualizuj(time_probing);
	float measured_temp = pomieszczenie->getTemperatura();
	if (temperature_zadana > measured_temp)
	{
		grzejnik->set_current_power(1);
		pomieszczenie->dodajCieplo(grzejnik->power());
	}
	else
	{
		return;
	}
}