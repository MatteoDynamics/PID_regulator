#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include <iostream>
#include <vector>
#include "Regulator.h"

class Simulation {
    float time_sim;
    Pomieszczenie room;
    Grzejnik grzejnik;
    Regulator *regulator;
    std::vector <float> temp;
    std::vector <float> time;
    std::vector <float> power;

public:
    void iteration(float time);
    void run(int a, float b);
    void save(std::string filename);
    float get_time() { return time_sim; };

    Simulation(float wys_, float szer_, float gleb_, float nominal_power) : room(wys_, szer_, gleb_), grzejnik(nominal_power),time_sim(0),regulator(nullptr) {}
};



