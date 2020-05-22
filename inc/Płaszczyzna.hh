#ifndef SYMULACJADRONA_PLASZCZYZNA_HH
#define SYMULACJADRONA_PLASZCZYZNA_HH

#include "ObiektRysowalny.hh"

class Plaszczyzna : public ObiektRysowalny {
protected:
    std::vector<std::vector<drawNS::Point3D>> Wierzcholki;
public:
    virtual void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) =0 ;
    bool Rysuj() ;

};


#endif
