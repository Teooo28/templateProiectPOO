#pragma once
#include <iostream>
#include <string>

class Ruta {

private:
    std::string nume;
    int nrStatii;
    std::string* statii;

public:
    // constructor
    Ruta(const std::string& nume, int nrStatii, const std::string* arrayStatii);

    // regula 1: destructor
    ~Ruta();

    // regula 2: constructor de copiere
    Ruta(const Ruta& other);

    // regula 3: operatorul de atribuire
    Ruta& operator=(const Ruta& other);

    // functie de afisare
    void afisareRuta() const;

};