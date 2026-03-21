#pragma once
#include "Entitate.h"
#include <string>

class Vehicul : public Entitate {

protected:
    std::string producator;
    static int nrTotalVehicule;     // numara cate vehiculeam creat in total

public:
    // constructor
    Vehicul(int id, const std::string& producator);

    // destructor
    virtual ~Vehicul();

    // suprascrierea functiei virtuale pure din clasa de baza
    void afisareDetalii() const override;

    // metoda statica pentru a putea citi contorul din exterior
    static int getNrTotalVehicule();
};