#include "MasinaDiesel.h"
#include <iostream>

// implementare constructor
MasinaDiesel::MasinaDiesel(int id, const std::string& producator, int capacitateRezervor, const std::string& normaPoluare)
    : Vehicul(id, producator), 
      VehiculCombustibil(id, producator, capacitateRezervor), 
      normaPoluare(normaPoluare) {
}

// implementare destructor
MasinaDiesel::~MasinaDiesel() {
}

// implementare functie pur virtuala
void MasinaDiesel::afisareDetalii() const {
    std::cout << "Masina Diesel -> ID: " << id 
              << " | Producator: " << producator 
              << " | Rezervor: " << capacitateRezervor << " litri"
              << " | Norma: " << normaPoluare << "\n";
}