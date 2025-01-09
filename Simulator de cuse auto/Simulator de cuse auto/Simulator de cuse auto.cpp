#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Masina.h"
#include "MasinaSport.h"
#include "Circuit.h"
#include "Cursa.h"
int main() {
    std::srand(std::time(nullptr));

    std::vector<Circuit> circuite = {
        Circuit("Monza", 5000),
        Circuit("Silverstone", 7000),
        Circuit("Nurburgring", 3000),
        Circuit("Sprint 1km", 1000),
        Circuit("Mini 500m", 500),
        Circuit("Test", 100)
    };

    std::cout << "Selectati circuitul:\n";
    for (size_t i = 0; i < circuite.size(); ++i) {
        std::cout << i + 1 << ". " << circuite[i].getNume() << " (" << circuite[i].getLungime() / 1000 << " km)\n";
    }

    int alegere;
    std::cin >> alegere;
    while (alegere < 1 || alegere > static_cast<int>(circuite.size())) {
        std::cout << "Alegere invalida. Incercati din nou: ";
        std::cin >> alegere;
    }

    Cursa cursa(circuite[alegere - 1]);

    cursa.adaugaMasina(new Masina("Dacia", 120, 2.5));
    cursa.adaugaMasina(new MasinaSport("Ferrari", 320, 5.5));
    cursa.adaugaMasina(new Masina("Toyota", 200, 4.0));
    cursa.adaugaMasina(new MasinaSport("Lamborghini", 350, 6.0));

    cursa.incepe();

    return 0;
}
