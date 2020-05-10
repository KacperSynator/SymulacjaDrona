#ifndef SYMULACJADRONA_BRYLA_H
#define SYMULACJADRONA_BRYLA_H

#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include <vector>

/*!
 * \brief Implementacja klasy bryła
 */

class Bryla
{
protected:
int apii;
MacierzOb orientacja;
Wektor3D srodek=Wektor3D(0,0,0);
std::vector<Wektor3D> Pod1;
std::vector<Wektor3D> Pod2;

public:

    enum Kierunek{Przod, Tyl, Gora, Dol};
    virtual void Ruch(const enum Kierunek,const double odleglosc) = 0;
    virtual void Obrot(const enum MacierzOb::OsObrotu, double kat) = 0;
    virtual void Inicjalizuj() = 0;
    virtual int Get_apii() = 0;
    virtual void Set_Pod1(const std::vector<Wektor3D> & vekP) = 0;
    virtual void Set_Pod2(const std::vector<Wektor3D> & vekP) = 0;
    virtual bool Rysuj(drawNS::Draw3DAPI * api) = 0;


};


#endif
