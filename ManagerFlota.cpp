#include "ManagerFlota.h"
#include "ExceptiiCustom.h"
#include <iostream>

// constructorul
ManagerFlota::ManagerFlota() {}

// destructorul - elibereaza memoria
ManagerFlota::~ManagerFlota() {
    for (Vehicul* v : vehicule) {
        delete v;
    }
    vehicule.clear();
}

// metoda de adaugare a unui vehicul
void ManagerFlota::adaugaVehicul(Vehicul* v) {
    vehicule.push_back(v);
    std::cout << "Vehiculul a fost adaugat!\n";
}

// metoda de afisare a flotei
void ManagerFlota::afisareFlota() const {
    if (vehicule.empty()) {
        std::cout << "Flota este goala!\n";
    }

    for (const Vehicul* v : vehicule) {
        v->afisareDetalii();
    }
}

// metoda de stergere a unui vehicul
void ManagerFlota::stergeVehicul(int id) {
    bool gasit = false;

    for (auto i = vehicule.begin(); i != vehicule.end(); ++i) {
        if ((*i)->getId() == id) {
            gasit = true;
            delete *i;
            vehicule.erase(i);
            std::cout << "Vehiculul a fost sters!\n";
            break;
        }
    }

    if (!gasit) {
        throw EroareIdInexistent("Eroare Runtime: Vehicului cu ID-ul " + std::to_string(id) + " nu exista!\n");
    }
}
