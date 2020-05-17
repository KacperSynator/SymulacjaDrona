#ifndef SYMULACJADRONA_DRON_HH
#define SYMULACJADRONA_DRON_HH

#include "Prostopadloscian.hh"
#include "Dron_interface.hh"
#include "Wirnik.hh"

#define KONIEC 1

using std::cout;
using std::cin;

class Dron : public Prostopadloscian, public DronInterface {
protected:
    Wirnik wirnikP;
    Wektor3D pozWP;
    Wirnik wirnikL;
    Wektor3D pozWL;
public:
Dron() {};

    void AnimujRuch(const Wektor3D & kierunek,const double & odleglosc);
    void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat);
    void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & h,const double & odleglosc);
    void InicjalizujDrona ();
    void Menu();
};


#endif
