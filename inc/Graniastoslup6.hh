#ifndef SYMULACJADRONA_GRANIASTOSLUP6_HH
#define SYMULACJADRONA_GRANIASTOSLUP6_HH

#include "Bryla.hh"

class Graniastoslup6 : public Bryla {
protected:
    std::vector<Wektor3D> Pod1;
    std::vector<Wektor3D> Pod2;
public:
    void Set_Pod1(const std::vector<Wektor3D> & vekP) {Pod1=vekP;}
    void Set_Pod2(const std::vector<Wektor3D> & vekP) {Pod2=vekP;}
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api);
    bool Rysuj();
};


#endif
