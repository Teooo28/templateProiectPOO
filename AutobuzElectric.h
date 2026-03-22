#pragma once
#include "TransportPublic.h"
#include "VehiculElectric.h"

class AutobuzElectric : public VehiculElectric, public TransportPublic {

private:
    std::string ruta;

public:
    // constructor
    AutobuzElectric(int id, const std::string& producator, int baterie, int nrLocuri, const std::string& ruta);

    // destructor 
    ~AutobuzElectric() override;

    // suprascrierea metodei de afisare
    void afisareDetalii() const override;

};