#include "TransportPublic.h"
#include <iostream>
#include "ExceptiiCustom.h"

// implementare constructor
TransportPublic::TransportPublic(int id, const std::string& producator, int nrLocuri) 
    : Vehicul(id, producator), nrLocuri(nrLocuri) {

        if (nrLocuri <= 0) {
            throw EroareDateInvalide("Eroare Date: Un vehicul de transport trebuie sa aiba locuri!");
        }
}

// implementare destructor
TransportPublic::~TransportPublic() {
}

// implementare functie pur virtuala
void TransportPublic::afisareDetalii() const {
    std::cout << "Transport Public -> ID: " << id 
              << " | Producator: " << producator 
              << " | Locuri: " << nrLocuri << "\n";
}

void TransportPublic::urcaPasageri(int numarPasageri) {
    if (numarPasageri > nrLocuri) {
        throw EroareCapacitate("Eroare Capacitate: Prea multi pasageri! Limita a fost depasita.");
    }
    std::cout << numarPasageri << " pasageri au urcat cu succes in vehicul.\n";
}