#pragma once
#include "TransportPublic.h"
#include "VehiculElectric.h"

class Tramvai : public VehiculElectric, public TransportPublic {

private:
    int nrVagoane;

public:
    // constructor
    Tramvai(int id, const std::string& producator, int baterie, int nrLocuri, int nrVagoane);

    // destructor
    ~Tramvai() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

    // getter nr vagoane
    int getNrVagoane() const { return nrVagoane; }

};