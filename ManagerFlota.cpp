#include "ManagerFlota.h"
#include "VehiculElectric.h"
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
    if (v == nullptr) return;

    vehicule.push_back(v);
    std::cout << "Vehiculul a fost adaugat cu succes!\n";
}

// metoda de afisare a flotei
void ManagerFlota::afisareFlota() const {
    if (vehicule.empty()) {
        std::cout << "Flota este goala!\n";
        return;
    }

    std::cout << "\n- LISTA VEHICULE SMART CITY -\n";
    for (Vehicul* v : vehicule) {
        v->afisareDetalii();
    }
    std::cout << "Total vehicule in sistem: " << Vehicul::getNrTotalVehicule() << "\n";
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
            return;
        }
    }

    if (!gasit) {
        throw EroareIdInexistent("Eroare Runtime: Vehicului cu ID-ul " + std::to_string(id) + " nu exista!\n");
    }
}

// implementare cautare
Vehicul* ManagerFlota::cautaVehicul(int id) const {
    for (Vehicul* v : vehicule) {
        if (v->getId() == id) {
            return v;
        }
    }
    throw EroareIdInexistent("Eroare: Nu am gasit niciun vehicul cu ID-ul: " + std::to_string(id));
}

// metoda modificare baterie
void ManagerFlota::modificaBaterieVehicul(int id, int baterieNoua) {
    bool gasit = false;

    for (Vehicul* v : vehicule) {
        if (v->getId() == id) {
            gasit = true;

            VehiculElectric* masinaElectrica = dynamic_cast<VehiculElectric*>(v);

            if (masinaElectrica != nullptr) {
                masinaElectrica->setBaterie(baterieNoua);
                std::cout << "Baterie modificata cu succes!\n";
            }
            else {
                std::cout << "Eroare: Vehicului cu ID: " + std::to_string(id) + " nu este electric!\n"; 
            }
            return;
        }
    }

    if (!gasit) {
        throw EroareIdInexistent("Eroare Runtime: Vehicului cu ID-ul " + std::to_string(id) + " nu exista!\n");
    }
}
