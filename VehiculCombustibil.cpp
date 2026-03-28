#include "VehiculCombustibil.h"
#include "ExceptiiCustom.h"
#include <iostream>

// implementare constructor
VehiculCombustibil::VehiculCombustibil(int id, const std::string& producator, int capacitateRezervor)
    : Vehicul(id, producator), 
      capacitateRezervor(capacitateRezervor) {
    
    // validare date
    if (capacitateRezervor <= 0) {
        throw EroareDateInvalide("Eroare Date: Rezervorul trebuie sa aiba o capacitate pozitiva!");
    }
}

// implementare destructor
VehiculCombustibil::~VehiculCombustibil() {
}

// implementare afisare
void VehiculCombustibil::afisareDetalii() const {
    std::cout << "Vehicul Combustibil -> ID: " << id 
              << " | Producator: " << producator 
              << " | Rezervor: " << capacitateRezervor << " litri\n";
}