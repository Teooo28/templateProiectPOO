#pragma once
#include "Vehicul.h"

class VehiculElectric : virtual public Vehicul {

protected:
    int baterie;

public:
    // constructor
    VehiculElectric(int id, const std::string& producator, int baterie);

    // destructor
    ~VehiculElectric() override;

    // suprascrierea functiei virtuale pure din clasa de baza 
    void afisareDetalii() const override;

    // setter baterie
    void setBaterie(int baterieNoua);

};