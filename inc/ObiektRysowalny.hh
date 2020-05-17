#ifndef SYMULACJADRONA_OBIEKTRYSOWALNY_HH
#define SYMULACJADRONA_OBIEKTRYSOWALNY_HH

#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include <vector>

class ObiektRysowalny {
protected:
    int apii;
    std::shared_ptr<drawNS::Draw3DAPI> apiSceny;
public:
    virtual void Inicjalizuj() = 0;
    virtual bool Rysuj() = 0;
    void Zmarz() {apiSceny->erase_shape(apii);}
    void Set_apiSceny(std::shared_ptr<drawNS::Draw3DAPI> api) {apiSceny=api;}
    std::shared_ptr<drawNS::Draw3DAPI> Get_apiSceny() {return apiSceny;}
};


#endif
