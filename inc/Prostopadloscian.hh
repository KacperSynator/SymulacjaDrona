#ifndef SYMULACJADRONA_PROSTOPADLOSCIAN_HH
#define SYMULACJADRONA_PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

class Prostopadloscian : public Bryla {
protected:
    std::vector<Wektor3D> Pod1;
    std::vector<Wektor3D> Pod2;
public:
    void Set_Pod1(const std::vector<Wektor3D> & vekP) {Pod1=vekP;}
    void Set_Pod2(const std::vector<Wektor3D> & vekP) {Pod2=vekP;}
    void Inicjalizuj() ;
    bool Rysuj() ;

};


#endif
