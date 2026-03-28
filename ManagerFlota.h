#pragma once
#include <vector>
#include "Vehicul.h"

class ManagerFlota {
private:
    std::vector<Vehicul*> vehicule; 

public:
    ManagerFlota();
    ~ManagerFlota();

    void adaugaVehicul(Vehicul* v);
    void afisareFlota() const;
    void stergeVehicul(int id);
    void modificaBaterieVehicul(int id, int baterieNoua);
};