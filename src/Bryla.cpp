#include "../inc/Bryla.hh"


void Bryla::Ruch(const Wektor3D & kierunek, const double odleglosc)
{
    srodek=srodek+orientacja*(kierunek*odleglosc);
}


void Bryla::Obrot(const MacierzOb::OsObrotu os, double kat)
{
    MacierzOb MP;

    switch (os)
    {
        case MacierzOb::OX:
            MP=MacierzOb(MacierzOb::OX,kat);
            orientacja=orientacja*MP;
            break;

        case MacierzOb::OY:
            MP=MacierzOb(MacierzOb::OY,kat);
            orientacja=orientacja*MP;
            break;

        case MacierzOb::OZ:
            MP=MacierzOb(MacierzOb::OZ,kat);
            orientacja=orientacja*MP;
            break;
    }
}


