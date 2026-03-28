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
    void stergeVehicul(int id);
    void afisareFlota() const;
    Vehicul* cautaVehicul(int id) const;
    void modificaBaterieVehicul(int id, int baterieNoua);
};