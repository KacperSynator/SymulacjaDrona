#include "../inc/Wirnik.hh"



void Wirnik::InicjalizujWirnik(const Wektor3D &sr)
{
    srodek=sr;
    Inicjalizuj();
}

void Wirnik::RuchDrona(const Wektor3D &sr, MacierzOb &ob,int kat)
{
    srodek=sr;
    orientacja=ob;
    Obrot(MacierzOb::OY,kat);
    Zmarz();
    Rysuj();
    apiSceny->redraw();

}
