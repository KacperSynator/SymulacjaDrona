#ifndef SYMULACJADRONA_PROSTOPADLOSCIAN_HH
#define SYMULACJADRONA_PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

class Prostopadloscian : public Bryla {
protected:

public:
    void Set_Pod1(const std::vector<Wektor3D> & vekP) {Pod1=vekP;}
    void Set_Pod2(const std::vector<Wektor3D> & vekP) {Pod2=vekP;}
    int Get_apii () {return apii;}
    void Inicjalizuj() ;
    bool Rysuj(drawNS::Draw3DAPI * api) ;
    std::vector<drawNS::Point3D> Pwek2Ppoint (const std::vector<Wektor3D> & P) const;
    void Ruch(const enum Kierunek kierunek,double odleglosc) ;
    void Obrot(const enum MacierzOb::OsObrotu os, double kat) ;
    void AnimujRuch(const enum Kierunek kierunek,double odleglosc,drawNS::Draw3DAPI * api);
    void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat,drawNS::Draw3DAPI * api);
    Wektor3D ObrocWektor(const enum MacierzOb::OsObrotu os, const Wektor3D & wek) const;
};


#endif
