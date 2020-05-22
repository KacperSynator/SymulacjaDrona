#ifndef SYMULACJADRONA_BRYLA_H
#define SYMULACJADRONA_BRYLA_H


#include "ObiektRysowalny.hh"


/*!
 * \brief Implementacja klasy bryła
 */

class Bryla : public ObiektRysowalny
{
protected:
MacierzOb orientacja;
Wektor3D srodek=Wektor3D(0,0,0);


public:

    void Ruch(const Wektor3D & kierunek,const double odleglosc);
    void Obrot(const enum MacierzOb::OsObrotu os, double kat) ;
    virtual void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) override = 0;
    virtual bool Rysuj() override = 0;


};


#endif
