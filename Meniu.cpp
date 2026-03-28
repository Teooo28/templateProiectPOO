#include "Meniu.h"
#include "VehiculElectric.h"
#include "VehiculCombustibil.h"
#include "Tramvai.h"
#include "AutobuzElectric.h"
#include "MasinaElectrica.h"
#include "MasinaDiesel.h"
#include "Ruta.h"
#include <string>

Meniu* Meniu::instance = nullptr;

Meniu::Meniu() {}

Meniu* Meniu::getInstance() {
    if (instance == nullptr) {
        instance = new Meniu();
    }
    return instance;
}

void Meniu::afisareOptiuni() const {
    std::cout << "\n~ SISTEM MANAGEMENT SMART CITY ~\n";
    std::cout << "1. Adauga Vehicul in Flota\n";
    std::cout << "2. Afiseaza toata flota\n";
    std::cout << "3. Modifica baterie vehicul (doar electrice)\n";
    std::cout << "4. Sterge vehicul dupa ID\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alege o optiune: ";
}

void Meniu::optiuneAdaugaVehicul() {
    std::cout << "\n- Selecteaza Tip Vehicul -\n";
    std::cout << "1. Masina Electrica\n";
    std::cout << "2. Masina Diesel\n";
    std::cout << "3. Tramvai (Electric)\n";
    std::cout << "4. Autobuz Electric\n";
    std::cout << "Alegerea ta: ";
    
    int tip;
    std::cin >> tip;

    int id;
    std::string prod;
    std::cout << "ID: "; std::cin >> id;
    std::cout << "Producator: "; std::cin >> prod;

    try {
        if (tip == 1) { // Masina Electrica
            int baterie;
            std::string model;
            std::cout << "Baterie (kWh): "; std::cin >> baterie;
            std::cout << "Model masina: "; std::cin >> model;
            manager.adaugaVehicul(new MasinaElectrica(id, prod, baterie, model));

        } else if (tip == 2) { // Masina Diesel
            int rezervor;
            std::string norma;
            std::cout << "Capacitate rezervor (L): "; std::cin >> rezervor;
            std::cout << "Norma poluare (ex Euro6): "; std::cin >> norma;
            manager.adaugaVehicul(new MasinaDiesel(id, prod, rezervor, norma));

        } else if (tip == 3) { // Tramvai
            int baterie, locuri, vagoane;
            std::cout << "Baterie (kWh): "; std::cin >> baterie;
            std::cout << "Nr. Locuri: "; std::cin >> locuri;
            std::cout << "Nr. Vagoane: "; std::cin >> vagoane;
            manager.adaugaVehicul(new Tramvai(id, prod, baterie, locuri, vagoane));

        } else if (tip == 4) { // Autobuz Electric
            int baterie, locuri, nrStatii;
            std::string numeRuta;
            std::cout << "Baterie (kWh): "; std::cin >> baterie;
            std::cout << "Nr. Locuri: "; std::cin >> locuri;
            std::cout << "Nume Ruta: "; std::cin >> numeRuta;
            std::cout << "Numar statii: "; std::cin >> nrStatii;

            std::string* statiiTemp = new std::string[nrStatii];
            for (int i = 0; i < nrStatii; i++) {
                std::cout << "Statia " << (i + 1) << ": ";
                std::cin >> statiiTemp[i];
            }
            Ruta r(numeRuta, nrStatii, statiiTemp);
            delete[] statiiTemp;
            manager.adaugaVehicul(new AutobuzElectric(id, prod, baterie, locuri, r));

        } else {
            std::cout << "Optiune invalida!\n";
        }
    } 
    catch (const std::exception& e) {
        std::cout << "-> [EROARE] " << e.what() << "\n";
    }
}

void Meniu::optiuneModificaVehicul() {
    int id, baterieNoua;
    std::cout << "ID vehicul electric: "; std::cin >> id;
    std::cout << "Noua valoare baterie: "; std::cin >> baterieNoua;
    try {
        manager.modificaBaterieVehicul(id, baterieNoua);
    } catch (const std::exception& e) {
        std::cout << "-> [EROARE] " << e.what() << "\n";
    }
}

void Meniu::optiuneStergeVehicul() {
    int id;
    std::cout << "ID de sters: "; std::cin >> id;
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
            case 0: std::cout << "Inchidere sistem...\n"; break;
            default: std::cout << "Optiune inexistenta!\n"; break;
        }
    } while (optiune != 0);
}