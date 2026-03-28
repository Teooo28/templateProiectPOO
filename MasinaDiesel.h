#pragma once
#include "VehiculCombustibil.h"

class MasinaDiesel : public VehiculCombustibil {

private:
    std::string normaPoluare;

public:
    // constructor
    MasinaDiesel(int id, const std::string& producator, int capacitateRezervor, const std::string& normaPoluare);

    // destructor
    ~MasinaDiesel() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

    // getter norma poluare
    std::string getNormaPoluare() const { return normaPoluare; }
};