#include "../inc/Prostopadloscian.hh"

bool Prostopadloscian::Rysuj()
{

    if(Pod1.size() !=4 || Pod2.size() !=4 || apiSceny == nullptr )
    {
        std::cerr << "Blad podstawy nie maja 4 wierzcholkow lub api = nullptr\n";
        return false;
    }

    apii=apiSceny->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>> { Pwek2Ppoint(WyliczGlobalne(Pod1)) ,Pwek2Ppoint(WyliczGlobalne(Pod2))}, "purple");
    return true;


}
void Prostopadloscian:: Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)
{
    srodek=sr;
    apiSceny=api;
    Pod1 = {Wektor3D(1.5,2,0.5),Wektor3D(-1.5,2,0.5),Wektor3D(-1.5,-2,0.5),Wektor3D(1.5,-2,0.5)};
    Pod2 = {Wektor3D(1.5,2,-0.5),Wektor3D(-1.5,2,-0.5),Wektor3D(-1.5,-2,-0.5),Wektor3D(1.5,-2,-0.5)};
    Rysuj();
}

std::vector<Wektor3D> Prostopadloscian::WyliczGlobalne(std::vector<Wektor3D> &in)
{
    std::vector<Wektor3D> WP=in;
    for(long unsigned int i=0;i<in.size();i++)
        WP[i] = srodek + (orientacja * in[i]);

    return WP;
}





