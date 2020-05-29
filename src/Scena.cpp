#include "../inc/Scena.hh"

void Scena::Inicjalizuj()
{
    Wektor3D sr;
    std::shared_ptr<drawNS::Draw3DAPI> apii(new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,1000));
    api=apii;
    api->change_ref_time_ms(-1);
    dron.InicjalizujDrona(api,sr);
    dno.Inicjalizuj(api,sr);
    poziomMorza.Inicjalizuj(api,sr);
}



void Scena::WlaczMenuDrona()
{
    dron.Menu();
}



