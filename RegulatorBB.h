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
		void steering(float temperature_zadana, float time_probing);
};

