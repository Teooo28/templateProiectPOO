#include "MasinaElectrica.h"
#include <iostream>

// implementare constructor
MasinaElectrica::MasinaElectrica(int id, const std::string& producator, int baterie, const std::string& model)
    : Vehicul(id, producator), 
      VehiculElectric(id, producator, baterie), 
      model(model) {
}

// implementare destructor
MasinaElectrica::~MasinaElectrica() {
}

// implementare functie pur virtuala
void MasinaElectrica::afisareDetalii() const {
    std::cout << "Masina Electrica -> ID: " << id 
              << " | Producator: " << producator 
              << " | Baterie: " << baterie << " kWh"
              << " | Model: " << model << "\n";
}