#ifndef SYMULACJADRONA_WIRNIK_HH
#define SYMULACJADRONA_WIRNIK_HH

#include "Graniastoslup6.hh"

class Wirnik : public Graniastoslup6{
public:
    void InicjalizujWirnik(const Wektor3D & sr, std::shared_ptr<drawNS::Draw3DAPI> api);
    void RuchDrona(const Wektor3D & sr,MacierzOb & ob,const double & kat);
};


#endif
