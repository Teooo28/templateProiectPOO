#pragma once
#include <string>

class Vehicul {

protected:
    int id;
    std::string producator;
    static int nrTotalVehicule;     // numara cate vehiculeam creat in total

public:
    // constructor
    Vehicul(int id, const std::string& producator);

    // destructor
    virtual ~Vehicul();

    // transforma Vehicul intr-o clasa abstracta
    virtual void afisareDetalii() const = 0;

    // metoda statica pentru a putea citi contorul din exterior
    static int getNrTotalVehicule();

    // getter id
    int getId() const { return id; }

    // getter producator
    std::string getProducator() const { return producator; }
};