#include "../inc/PrzeszkodaProst.hh"

bool PrzeszkodaProst::CzyKolizja(std::shared_ptr<DronInterface> D)
{
    Wektor3D WP;
    WP=srodek-D->ZwrocPozycje();
    cout<<"DZIALA\n";
    if(WP.dlugosc()<=4)
        return true;

    return false;
}

PrzeszkodaProst::PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> api,std::vector<std::shared_ptr<Przeszkoda_interface>> kp,const Wektor3D & sr)
{
    kp.push_back((std::shared_ptr<Przeszkoda_interface>) this);
    kolekcja_przeskod=kp;
    //utworzone++;
   // istniejace++;
    Inicjalizuj(api,sr);
}
