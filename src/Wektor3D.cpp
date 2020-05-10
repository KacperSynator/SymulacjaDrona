#include "../inc/Wektor3D.hh"

drawNS::Point3D Wektor3D::Wektor2Point() const
{
    return drawNS::Point3D(tab[0],tab[1],tab[2]);
}

Wektor3D & Wektor3D::operator=(Wektor3D W)
 {

    tab[0]=W[0];
    tab[1]=W[1];
    tab[2]=W[2];
    return *this;
}


