#pragma once
#include "Vehicul.h"

class TransportPublic : virtual public Vehicul {

protected:
    int nrLocuri;

public:
    // constructor
    TransportPublic(int id, const std::string& producator, int nrLocuri);

    // destructor
    ~TransportPublic() override;

    // suprascrierea functiei virtuale pure din clasa de baza 
    void afisareDetalii() const override;

};