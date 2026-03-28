#pragma once
#include "ManagerFlota.h"
#include <iostream>

class Meniu {
private:
    static Meniu* instance;
    ManagerFlota manager;

    Meniu();

    // functii ajutatoare interne
    void afisareOptiuni() const;
    void optiuneAdaugaVehicul();
    void optiuneModificaVehicul();
    void optiuneStergeVehicul();

public:
    static Meniu* getInstance();
    void ruleaza();
};