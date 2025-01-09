#pragma once
#include <iostream>
#include <windows.h>
using namespace std;
class Masina
{
protected:
    std::string nume;
    double vitezaMaxima; // in km/h
    double acceleratie; // in m/s^2
    double distantaParcursa; // in metri

public:
    Masina(std::string nume, double vitezaMaxima, double acceleratie)
        : nume(nume), vitezaMaxima(vitezaMaxima), acceleratie(acceleratie), distantaParcursa(0) {
    }

    virtual void update(double timp, bool areObstacol); 

    double getDistantaParcursa(); 

    std::string getNume();
    

    virtual ~Masina() {}
};


