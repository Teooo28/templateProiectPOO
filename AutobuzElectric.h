#pragma once
#include "TransportPublic.h"
#include "VehiculElectric.h"
#include "Ruta.h"

class AutobuzElectric : public VehiculElectric, public TransportPublic {

private:
    Ruta rutaAutobuz;

public:
    // constructor
    AutobuzElectric(int id, const std::string& producator, int baterie, int nrLocuri, const Ruta& rutaAutobuz);

    // destructor 
    ~AutobuzElectric() override;

    // suprascrierea metodei de afisare
    void afisareDetalii() const override;

};