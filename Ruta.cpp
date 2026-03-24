#include "Ruta.h"
#include "ExceptiiCustom.h"

// implementare constructor
Ruta::Ruta(const std::string& nume, int nrStatii, const std::string* arrayStatii) : nume(nume), nrStatii(nrStatii) {
    // validare date
    if (nrStatii <= 0) {
        throw ValoareInvalidaException("Eroare: O ruta trebuie sa aiba cel putin o statie!");
    }
    
    statii = new std::string[nrStatii];
    for(int i = 0; i < nrStatii; i++) {
        statii[i] = arrayStatii[i];
    }
}

// implementare destructor
Ruta::~Ruta() {
    delete[] statii;
}

// implementare constructor de copiere
Ruta::Ruta(const Ruta& other) : nume(other.nume), nrStatii(other.nrStatii) {
    // copiem datele de la other
    statii = new std::string[nrStatii];
    for(int i = 0; i < nrStatii; i++) {
        statii[i] = other.statii[i];
    }
}

// implementare operator de atribuire
Ruta& Ruta::operator=(const Ruta& other) {
    // verificare sa nu copiem acelasi obiect
    if(this == &other) {
        return *this;
    }

    // stergem statiile pe care le aveam deja
    delete[] statii;

    // copiem detaliile noi
    nume = other.nume;
    nrStatii = other.nrStatii;
    
    statii = new std::string[nrStatii];
    for(int i = 0; i < nrStatii; i++) {
        statii[i] = other.statii[i];
    }

    // returnam obiectul actual modificat
    return *this;
}

// functia pentru afisare
void Ruta::afisareRuta() const {
    std::cout << "Ruta '" << nume << "' are " << nrStatii << " statii: ";
    for(int i = 0; i < nrStatii; i++) {
        std::cout << statii[i] << " ";
    }
    std::cout << "\n";
}