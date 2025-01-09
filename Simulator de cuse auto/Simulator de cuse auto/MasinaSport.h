#pragma once
#include <iostream>
#include "Masina.h"
using namespace std;
class MasinaSport: public Masina {
public:
    MasinaSport(std::string nume, double vitezaMaxima, double acceleratie)
        : Masina(nume, vitezaMaxima, acceleratie) {
    }

    void Update(double timp, bool areObstacol); 
};

