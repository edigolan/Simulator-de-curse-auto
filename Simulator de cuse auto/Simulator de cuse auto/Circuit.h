#pragma once
#include <iostream>
using namespace std;
class Circuit
{
private:
    double lungime; // in metri
    std::string nume;

public:
    Circuit(std::string nume, double lungime) : nume(nume), lungime(lungime) {}

    double getLungime();

    string getNume(); 

};

