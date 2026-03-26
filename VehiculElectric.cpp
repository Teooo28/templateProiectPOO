#include "VehiculElectric.h"
#include <iostream>
#include "ExceptiiCustom.h"

// implementare constructor
VehiculElectric::VehiculElectric(int id, const std::string& producator, int baterie) 
    : Vehicul(id, producator), baterie(baterie) {
        
        if (baterie <= 0) {
            throw EroareDateInvalide("Eroare Date: Bateria trebuie sa fie mai mare decat 0!");
        }
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