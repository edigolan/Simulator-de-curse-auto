#include "Masina.h"
using namespace std;
void Masina::update(double timp, bool areObstacol) {

    if (areObstacol) {
        Sleep(100); // Pierde timp fictiv din cauza obstacolului
    }
    distantaParcursa += 0.5 * acceleratie * timp * timp;
    double vitezaCurenta = acceleratie * timp;
    if (vitezaCurenta > vitezaMaxima * 1000 / 3600) {
        vitezaCurenta = vitezaMaxima * 1000 / 3600;
    }
    distantaParcursa += vitezaCurenta * timp;
}

double Masina::getDistantaParcursa() {
    return distantaParcursa;
}

std::string Masina::getNume() {
    return nume;
}
