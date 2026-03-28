#include "Vehicul.h"
#include <iostream>

// initializare membru static
int Vehicul::nrTotalVehicule = 0;

// implementare constructor
Vehicul::Vehicul(int id, const std::string& producator) : id(id), producator(producator) {
    nrTotalVehicule++;
}

// implementare destructor
Vehicul::~Vehicul() {
    nrTotalVehicule--;
}

// implementare metoda statica
int Vehicul::getNrTotalVehicule() {
    return nrTotalVehicule;
}