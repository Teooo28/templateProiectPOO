#include "Tramvai.h"
#include <iostream>

// implementare constructor
Tramvai::Tramvai(int id, const std::string& producator, int nrLocuri, int nrVagoane) 
    : Vehicul(id, producator), 
      TransportPublic(id, producator, nrLocuri), 
      nrVagoane(nrVagoane) {
}

// implementare destructor
Tramvai::~Tramvai() {
}

// implementare functie pur virtuala
void Tramvai::afisareDetalii() const{
    std::cout << "Tramvai -> ID: " << id 
              << " | Producator: " << producator 
              << " | Locuri: " << nrLocuri 
              << " | Vagoane: " << nrVagoane << "\n";
}
