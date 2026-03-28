#include "Sofer.h"
#include "ExceptiiCustom.h"
#include <iostream>

// implementare constructor
Sofer::Sofer(int id, const std::string& nume, int aniExperienta) 
    : Angajat(id, nume), aniExperienta(aniExperienta) {
    
    // validare date
    if (aniExperienta < 0) {
        throw EroareDateInvalide("Eroare: Anii de experienta nu pot fi negativi!");
    }
}

// implementare destructor
Sofer::~Sofer() {}

// implementare functie pur virtuala
void Sofer::afisareDetalii() const {
    std::cout << "ID sofer: " << id 
              << " | Nume: " << nume 
              << " | Experienta: " << aniExperienta << " ani\n";
}