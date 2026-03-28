#pragma once
#include "ManagerFlota.h"
#include <vector>
#include <iostream>

class Meniu {
private:
    static Meniu* instance;
    ManagerFlota manager;

    // constructor privat pentru modelul Singleton
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