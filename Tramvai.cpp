#include "Tramvai.h"
#include <iostream>

// implementare constructor
Tramvai::Tramvai(int id, const std::string& producator, int baterie, int nrLocuri, int nrVagoane) 
    : Vehicul(id, producator), 
      VehiculElectric(id, producator, baterie),
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
              << " | Baterie: " << baterie << " kWh" 
              << " | Locuri: " << nrLocuri 
              << " | Vagoane: " << nrVagoane << "\n";
}
