#include "TransportPublic.h"
#include <iostream>

// implementare constructor
TransportPublic::TransportPublic(int id, const std::string& producator, int baterie) : Vehicul(id, producator), nrLocuri(nrLocuri) {
}

// implementare destructor
TransportPublic::~TransportPublic() {
}

// implementare functie pur virtuala
void TransportPublic::afisareDetalii() const {
    std::cout << "Transport Public -> ID: " << id << " | Producator: " << producator << " | Locuri: " << nrLocuri << "\n";
}