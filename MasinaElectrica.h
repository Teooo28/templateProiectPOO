#pragma once
#include "VehiculElectric.h"

class MasinaElectrica : public VehiculElectric {

private:
    std::string model;

public:
    // constructor
    MasinaElectrica(int id, const std::string& producator, int baterie, const std::string& model);

    // destructor
    ~MasinaElectrica() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

    // getter model
    std::string getModel() const { return model; }
};