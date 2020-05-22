#ifndef SYMULACJADRONA_POZIOMMORZA_HH
#define SYMULACJADRONA_POZIOMMORZA_HH

#include "Płaszczyzna.hh"

class PoziomMorza : public Plaszczyzna{

public:
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) ;

};


#endif
