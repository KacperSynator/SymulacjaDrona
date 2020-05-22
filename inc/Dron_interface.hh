#ifndef SYMULACJADRONA_DRON_INTERFACE_HH
#define SYMULACJADRONA_DRON_INTERFACE_HH


class DronInterface{
public:
    virtual void AnimujRuch(const Wektor3D & Kier,const double & odleglosc) =0;
    virtual void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat) =0;
    virtual void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & h,const double & odleglosc)=0;
    virtual void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api)=0;
};

#endif
