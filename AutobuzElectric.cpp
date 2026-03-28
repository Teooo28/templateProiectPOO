#include "AutobuzElectric.h"
#include <iostream>

// implementare constructor
AutobuzElectric::AutobuzElectric(int id, const std::string& producator, int baterie, int nrLocuri, const Ruta& rutaAutobuz) 
    : Vehicul(id, producator), 
      VehiculElectric(id, producator, baterie),
      TransportPublic(id, producator, nrLocuri),
      rutaAutobuz(rutaAutobuz) {
}

// implementare destructor
AutobuzElectric::~AutobuzElectric() {
}

// implementare functie pur virtuala
void AutobuzElectric::afisareDetalii() const {
    std::cout << "Autobuz Electric -> ID: " << id 
              << " | Producator: " << producator 
              << " | Baterie: " << baterie << " kWh" 
              << " | Locuri: " << nrLocuri << "\n";
    rutaAutobuz.afisareRuta();
}
