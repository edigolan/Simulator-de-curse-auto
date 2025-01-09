#include "Cursa.h"
using namespace std;
void Cursa::adaugaMasina(Masina* masina) {
    masini.push_back(masina);
    // Generare obstacole aleatorii
    obstacole.emplace_back(std::vector<bool>(50, false));
    for (int i = 0; i < 50; ++i) {
        if (rand() % 10 < 2) { // 20% sanse de obstacol
            obstacole.back()[i] = true;
        }
    }
}
void Cursa::afisareAnimata() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    for (size_t i = 0; i < masini.size(); ++i) {
        int pozitie = static_cast<int>(masini[i]->getDistantaParcursa() / circuit.getLungime() * 50);
        if (pozitie > 49) pozitie = 49; // Limiteaza la capatul circuitului

        std::cout << masini[i]->getNume() << ": ";
        for (int j = 0; j < 50; ++j) {
            if (j == 49) {
                std::cout << "&"; // Linia de sosire
            }
            else if (obstacole[i][j]) {
                std::cout << "#"; // Obstacol
            }
            else if (j == pozitie) {
                std::cout << "M"; // Pozitia masinii
            }
            else {
                std::cout << "-";
            }
        }
        std::cout << "\n";
    }
}

void Cursa::incepe() {
    std::cout << "Cursa a inceput pe circuitul " << circuit.getNume() << "!\n";

    bool cursaIncheiata = false;
    double timp = 0;
    const double intervalTimp = 0.5;
    size_t castigator = -1;

    while (!cursaIncheiata) {
        cursaIncheiata = true;
        for (size_t i = 0; i < masini.size(); ++i) {
            int pozitie = static_cast<int>(masini[i]->getDistantaParcursa() / circuit.getLungime() * 50);
            bool areObstacol = pozitie < 50 && obstacole[i][pozitie];
            masini[i]->update(intervalTimp, areObstacol);

            if (masini[i]->getDistantaParcursa() < circuit.getLungime()) {
                cursaIncheiata = false;
            }
            else if (castigator == -1) {
                castigator = i;
            }
        }

        afisareAnimata();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        timp += intervalTimp;
    }

    std::cout << "\nCursa s-a incheiat!\n";
    if (castigator != -1) {
        std::cout << "Castigator: " << masini[castigator]->getNume() << "!\n";
        std::cout << "\nFelicitari! \n";
    }

    // Sortare masini dupa distanta parcursa
    std::sort(masini.begin(), masini.end(), [](Masina* a, Masina* b) {
        return a->getDistantaParcursa() > b->getDistantaParcursa();
        });

    // Afisare clasament
    std::cout << "\nClasamentul final:\n";
    for (size_t i = 0; i < masini.size(); ++i) {
        std::cout << i + 1 << ". " << masini[i]->getNume() << '\n';
    }
}

