#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include "Masina.h"
#include "MasinaSport.h"
#include <algorithm>
#include <windows.h>
#include "Circuit.h"
using namespace std;
class Cursa {
private:
    Circuit circuit;
    std::vector<Masina*> masini;
    std::vector<std::vector<bool>> obstacole; // Matrice obstacole per masina

public:
    Cursa(Circuit circuit) : circuit(circuit) {}

    void adaugaMasina(Masina* masina); 

    void afisareAnimata(); 

    void incepe(); 

    ~Cursa() {
        for (auto& masina : masini) {
            delete masina;
        }
    }
};

