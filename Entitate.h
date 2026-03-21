class Entitate {

protected:
    int id;

public:
    // constructor
    Entitate(int id);
    
    // destructor
    virtual ~Entitate();

    // transforma Entitate intr-o clasa abstracta
    virtual void afisareDetalii() const = 0;

};