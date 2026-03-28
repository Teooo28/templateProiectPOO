#pragma once
#include "Vehicul.h"

class VehiculCombustibil : virtual public Vehicul {
protected:
    int capacitateRezervor;

public:
    // constructor
    VehiculCombustibil(int id, const std::string& producator, int capacitateRezervor);

    // destructor
    virtual ~VehiculCombustibil() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

    // getter pentru capacitate rezervor
    int getCapacitateRezervor() const { return capacitateRezervor; }
};