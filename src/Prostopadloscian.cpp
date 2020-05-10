#include "../inc/Prostopadloscian.hh"

bool Prostopadloscian::Rysuj(drawNS::Draw3DAPI * api)
{

    if(Pod1.size() !=4 || Pod2.size() !=4 || api == nullptr )
    {
        std::cerr << "Blad podstawy nie maja 4 wierzcholkow lub api = nullptr\n";
        return false;
    }

    apii=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>> { Pwek2Ppoint(Pod1) ,Pwek2Ppoint(Pod2)}, "purple");
    return true;


}
void Prostopadloscian:: Inicjalizuj()
{
    std::vector<Wektor3D> P1 = {Wektor3D(1,1,0.5),Wektor3D(-1,1,0.5),Wektor3D(-1,-1,0.5),Wektor3D(1,-1,0.5)};
    std::vector<Wektor3D> P2 = {Wektor3D(1,1,-0.5),Wektor3D(-1,1,-0.5),Wektor3D(-1,-1,-0.5),Wektor3D(1,-1,-0.5)};
    Set_Pod1(P1);
    Set_Pod2(P2);
}

std::vector<drawNS::Point3D> Prostopadloscian::Pwek2Ppoint(const std::vector<Wektor3D> &P) const
{
    std::vector<drawNS::Point3D> tmp;
    for(int i=0;i<P.size();i++)
    {
        tmp.push_back(drawNS::Point3D(0,0,0));
        tmp[i] = P[i].Wektor2Point();
    }

    return tmp;
}

void Prostopadloscian::Ruch(const Bryla::Kierunek kierunek, double odleglosc)
{
    Wektor3D Kier;
    switch (kierunek)
    {
        case Bryla::Gora:
            Kier = Wektor3D(0,0,1) ;
            break;

        case Bryla::Dol:
            Kier = Wektor3D(0,0,-1) ;
            break;

        case Bryla::Przod:
            Kier = Wektor3D(0,1,0) ;
            break;

        case Bryla::Tyl:
            Kier = Wektor3D(0,-1,0) ;
            break;
    }

    for(int i=0;i<Pod1.size();i++) 
        Pod1[i] = Pod1[i] + ((orientacja * Kier) * odleglosc);




    for(int i=0;i<Pod2.size();i++)
        Pod2[i] = Pod2[i] + ((orientacja*Kier) * odleglosc);

    srodek=srodek + (orientacja*Kier * odleglosc);




}

void Prostopadloscian::Obrot(const MacierzOb::OsObrotu os, double kat)
{
    switch (os)
    {
        case MacierzOb::OX:
            orientacja=MacierzOb(MacierzOb::OX,kat);
            break;

        case MacierzOb::OY:
            orientacja=MacierzOb(MacierzOb::OY,kat);
            break;

        case MacierzOb::OZ:
            orientacja=MacierzOb(MacierzOb::OZ,kat);
            break;
    }

    for(int i=0;i<Pod1.size();i++)
        Pod1[i] = (srodek + (orientacja * Pod1[i]));




    for(int i=0;i<Pod2.size();i++)
        Pod2[i] = (srodek+ (orientacja  * Pod2[i]));


}

void Prostopadloscian::AnimujRuch(const Bryla::Kierunek kierunek, double odleglosc, drawNS::Draw3DAPI * api)
{
    for (int i = 0; i < 10000; i++)
    {
        Ruch(kierunek, odleglosc/10000);
        Rysuj(api);
        api->erase_shape(Get_apii());
    }
}

void Prostopadloscian::AnimujObrot(const MacierzOb::OsObrotu os, double kat, drawNS::Draw3DAPI *api)
{
    for(int i=0;i<10000;i++)
    {
        Obrot(os,kat/10000);
        Rysuj(api);
        api->erase_shape(Get_apii());
    }
}

Wektor3D Prostopadloscian::ObrocWektor(const enum MacierzOb::OsObrotu os,const Wektor3D &wek) const
{
    Wektor3D tmp=wek;
    MacierzOb MOP;
    MOP=MacierzOb(os,orientacja.Get_Kat());
    tmp=MOP*tmp;
    return tmp;
}



