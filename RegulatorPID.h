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
	void steering(float temp_zadana, float time)
	{
		if (pomieszczenie == nullptr || grzejnik == nullptr)
		{
			throw std::exception();
		}
		float temp_aktualna = pomieszczenie->getTemperatura();
		pomieszczenie->aktualizuj(time);
		float u_sum=0;
		float up=0, ui=0, ud=0, delta_e=0,e_poprzednia=0;
		//PROPORTIONAL PART
		e_poprzednia = e;
		e = temp_zadana - temp_aktualna;
		std::cout << "e = " << e << std::endl;
		up = kp * e;
		std::cout << "up = " << up << std::endl;
		//INTEGRAL PART
		e_calka += e * time;
		ui = ki * e_calka;
		std::cout << "ui = " << ui << std::endl;
		//DERIVATION PART
		delta_e = (e - e_poprzednia) / time;
		ud = kd * delta_e;
		std::cout << "ud = " << ud << std::endl;
		//SUM UP PID
		u_sum = up + ui + ud;
		cout << "u_sum = " << u_sum << std::endl;
		grzejnik->set_current_power(u_sum / 100);
		pomieszczenie->dodajCieplo(grzejnik->power());
	}
};

