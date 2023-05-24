#pragma once
#include "Regulator.h"
#include <cmath>
#include <iostream>
#include "Pomieszczenie.h"
#include "Grzejnik.h"
using namespace std;
class RegulatorPID: public Regulator
{
	Grzejnik* grzejnik;
	Pomieszczenie* pomieszczenie;
	float kp, ki, kd;
	float e_calka,delta_e;
	float e;
public:
	RegulatorPID(Pomieszczenie& pomieszczenie, Grzejnik& grzejnik) { kp = 50.0; ki = 0.02; kd = 0.1; e_calka = 0; delta_e = 0; e = 0; this->pomieszczenie = &pomieszczenie; this->grzejnik = &grzejnik; };
	void steering(float temp_zadana, float time);
};

