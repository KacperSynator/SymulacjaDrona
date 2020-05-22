#ifndef SYMULACJADRONA_SCENA_HH
#define SYMULACJADRONA_SCENA_HH

#include "Dron.hh"
#include "Dno.hh"
#include "PoziomMorza.hh"

class Scena{
private:
public:
    std::shared_ptr<drawNS::Draw3DAPI> api;
    Dron dron;
    Dno dno;
    PoziomMorza poziomMorza;
public:

    void Inicjalizuj();
    void WlaczMenuDrona();
};


#endif
