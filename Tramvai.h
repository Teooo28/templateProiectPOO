#pragma once
#include "TransportPublic.h"

class Tramvai : public TransportPublic {

private:
    int nrVagoane;

public:
    // constructor
    Tramvai(int id, const std::string& producator, int nrLocuri, int nrVagoane);

    // destructor
    ~Tramvai() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

};