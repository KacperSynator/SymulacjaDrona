#ifndef SYMULACJADRONA_WEKTOR3D_HH
#define SYMULACJADRONA_WEKTOR3D_HH

#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"

using drawNS::Point3D;

class Wektor3D : public Wektor<double,3>{
public:
    Wektor3D() {}
    Wektor3D(double x, double y, double z)   {tab[0]=x; tab[1]=y; tab[2]=z;}
    Wektor3D(Wektor<double, 3> w) {tab[0]=w[0]; tab[1]=w[1]; tab[2]=w[2];}

    Wektor3D & operator = (const Wektor3D  W) ;
    Point3D Wektor2Point() const;

};

#endif
