#include "Angajat.h"
#include <iostream>

// implementare constructor
Angajat::Angajat(int id, const std::string& nume) : Entitate(id), nume(nume) {}

// implrmrntare destructor
Angajat::~Angajat() {}

// implementare functie pur virtuala
void Angajat::afisareDetalii() const {
    std::cout << "ID angajat: " << id << " | Nume: " << nume << "\n";
}