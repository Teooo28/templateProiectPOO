#include "Meniu.h"
#include "VehiculElectric.h"
#include "Tramvai.h"
#include "AutobuzElectric.h"
#include "Ruta.h"
#include <string>

Meniu* Meniu::instance = nullptr;

Meniu* Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

void Meniu::afisareOptiuni() const {
    std::cout << "\n~ MENIU SMART CITY ~\n";
    std::cout << "1. Adauga Vehicul Electric\n";
    std::cout << "2. Afiseaza toata flota\n";
    std::cout << "3. Modifica baterie vehicul\n";
    std::cout << "4. Sterge vehicul dupa ID\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alege o optiune: ";
}

void Meniu::optiuneAdaugaVehicul() {
    std::cout << "\nCe tip de vehicul doresti sa adaugi?\n";
    std::cout << "1. Vehicul Electric Simplu\n";
    std::cout << "2. Tramvai\n";
    std::cout << "3. Autobuz Electric\n";
    std::cout << "Alegerea ta: ";
    
    int tip;
    std::cin >> tip;

    int id;
    std::string prod;
    std::cout << "Introdu ID: "; 
    std::cin >> id;
    std::cout << "Introdu Producator: "; 
    std::cin >> prod;

    try {
        if (tip == 1) {
            int baterie;
            std::cout << "Baterie: "; 
            std::cin >> baterie;
            Vehicul* v = new VehiculElectric(id, prod, baterie);
            manager.adaugaVehicul(v);
            
        } else if (tip == 2) {
            int locuri, vagoane;
            std::cout << "Numar locuri: "; 
            std::cin >> locuri;
            std::cout << "Numar vagoane: "; 
            std::cin >> vagoane;
            Vehicul* v = new Tramvai(id, prod, locuri, vagoane);
            manager.adaugaVehicul(v);
            
        } else if (tip == 3) {
            int baterie, locuri;
            std::cout << "Baterie: "; 
            std::cin >> baterie;
            std::cout << "Numar locuri: "; 
            std::cin >> locuri;
    
            std::string numeRuta;
            int nrStatii;
            std::cout << "Numele Rutei (fara spatii): "; 
            std::cin >> numeRuta;
            std::cout << "Numar de statii: "; 
            std::cin >> nrStatii;

            std::string* statiiTemp = new std::string[nrStatii];
            for (int i = 0; i < nrStatii; i++) {
                std::cout << "Nume statia " << (i + 1) << " (fara spatii): ";
                std::cin >> statiiTemp[i];
            }

            Ruta rutaAutobuz(numeRuta, nrStatii, statiiTemp);

            delete[] statiiTemp;

            Vehicul* v = new AutobuzElectric(id, prod, baterie, locuri, rutaAutobuz);
            manager.adaugaVehicul(v);
            
        } else {
            std::cout << "-> Optiune invalida! Intoarcere la meniul principal.\n";
        }
    } 
    catch (const std::exception& e) {
        std::cout << "-> [EROARE] " << e.what() << "\n";
    }
}

void Meniu::optiuneModificaVehicul() {
    int id, baterieNoua;
    std::cout << "Introdu ID-ul vehiculului: "; 
    std::cin >> id;
    std::cout << "Introdu noua baterie: "; 
    std::cin >> baterieNoua;

    try {
        manager.modificaBaterieVehicul(id, baterieNoua);
    } catch (const std::exception& e) {
        std::cout << "-> [EROARE] " << e.what() << "\n";
    }
}

void Meniu::optiuneStergeVehicul() {
    int id;
    std::cout << "Introdu ID-ul vehiculului de sters: "; 
    std::cin >> id;

    try {
        manager.stergeVehicul(id);
    } catch (const std::exception& e) {
        std::cout << "-> [EROARE] " << e.what() << "\n";
    }
}

void Meniu::ruleaza() {
    int optiune;
    do {
        afisareOptiuni();
        std::cin >> optiune;

        switch (optiune) {
            case 1: optiuneAdaugaVehicul(); break;
            case 2: manager.afisareFlota(); break;
            case 3: optiuneModificaVehicul(); break;
            case 4: optiuneStergeVehicul(); break;
            case 0: std::cout << "Sistem inchis.\n"; break;
            default: std::cout << "Optiune invalida!\n"; break;
        }
    } while (optiune != 0);
}