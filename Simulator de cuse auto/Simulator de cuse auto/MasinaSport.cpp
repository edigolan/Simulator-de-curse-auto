#include "MasinaSport.h"
void MasinaSport::Update(double timp, bool areObstacol)  {
    if (timp <= 5 && !areObstacol) {
        distantaParcursa += 0.5 * (acceleratie * 1.2) * timp * timp;
    }
    else {
        Masina::update(timp, areObstacol);
    }
}
