#pragma once
#include "Entitate.h"
#include <string>

class Angajat : public Entitate {
protected:
    std::string nume;

public:
    // constructor
    Angajat(int id, const std::string& nume);

    // dstructor
    ~Angajat() override;

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;
};