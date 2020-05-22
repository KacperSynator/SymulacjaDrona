#include "../inc/Wirnik.hh"



void Wirnik::InicjalizujWirnik(const Wektor3D &sr, std::shared_ptr<drawNS::Draw3DAPI> api)
{
    srodek=sr;
    Inicjalizuj(api);
}

void Wirnik::RuchDrona(const Wektor3D &sr, MacierzOb &ob,const double & kat)
{
    srodek=sr;
    orientacja=ob;
    Obrot(MacierzOb::OY,kat);
    Zmarz();
    Rysuj();
    apiSceny->redraw();

}
