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


std::vector<drawNS::Point3D> Pwek2Ppoint(const std::vector<Wektor3D> &P)
{
    std::vector<drawNS::Point3D> tmp;
    for(long unsigned int i=0;i<P.size();i++)
    {
        tmp.emplace_back(0,0,0);
        tmp[i] = P[i].Wektor2Point();
    }

    return tmp;
}
