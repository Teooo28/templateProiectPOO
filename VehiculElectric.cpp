#include "VehiculElectric.h"
#include <iostream>

// implementare constructor
VehiculElectric::VehiculElectric(int id, const std::string& producator, int baterie) : Vehicul(id, producator), baterie(baterie) {
}

// implementare destructor
VehiculElectric::~VehiculElectric() {
}

// implementare functie pur virtuala
void VehiculElectric::afisareDetalii() const {
    std::cout << "Vehicul Electric -> ID: " << id 
              << " | Producator: " << producator 
              << " | Baterie: " << baterie << " kWh\n";
}