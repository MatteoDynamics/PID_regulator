#pragma once
#include "Regulator.h"
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include <exception>
class RegulatorBB :public Regulator
{
	Grzejnik* grzejnik;
	Pomieszczenie* pomieszczenie;
	public:
		RegulatorBB(Pomieszczenie& pomieszczenie, Grzejnik& grzejnik) { this->pomieszczenie = &pomieszczenie; this->grzejnik = &grzejnik; };
	void steering(float temperature_zadana, float time_probing)
	{
		if (pomieszczenie == nullptr || grzejnik ==nullptr)
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
};

