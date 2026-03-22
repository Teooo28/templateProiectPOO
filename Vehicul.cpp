#include "Vehicul.h"
#include <iostream>

// initializare membru static
int Vehicul::nrTotalVehicule = 0;

// implementare constructor
Vehicul::Vehicul(int id, const std::string& producator) : Entitate(id), producator(producator) {
    nrTotalVehicule++;
}

// implementare destructor
Vehicul::~Vehicul() {
    nrTotalVehicule--;
}

// implementare functie pur virtuala
void Vehicul::afisareDetalii() const{
    std::cout << "ID vehicul: " << id 
              << "| Producator: " << producator << "\n";
}

// implementare metoda statica
int Vehicul::getNrTotalVehicule() {
    return nrTotalVehicule;
}