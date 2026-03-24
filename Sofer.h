#pragma once
#include "Angajat.h"

class Sofer : public Angajat {
private:
    int aniExperienta;

public:
    // constructor
    Sofer(int id, const std::string& nume, int aniExperienta);

    // destructor
    ~Sofer() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;
};