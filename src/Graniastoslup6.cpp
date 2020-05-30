#include "../inc/Graniastoslup6.hh"

void Graniastoslup6::Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr)
{
    apiSceny=api;
    std::vector<Wektor3D> P1 = {Wektor3D(-0.5,-0.25,0),Wektor3D(-0.25,-0.25,-sqrt(3)*0.25),Wektor3D(0.25,-0.25,-sqrt(3)*0.25),Wektor3D(0.5,-0.25,0),Wektor3D(0.25,-0.25,sqrt(3)*0.25),Wektor3D(-0.25,-0.25,sqrt(3)*0.25)};
    std::vector<Wektor3D> P2 = {Wektor3D(-0.5,0.25,0),Wektor3D(-0.25,0.25,-sqrt(3)*0.25),Wektor3D(0.25,0.25,-sqrt(3)*0.25),Wektor3D(0.5,0.25,0),Wektor3D(0.25,0.25,sqrt(3)*0.25),Wektor3D(-0.25,0.25,sqrt(3)*0.25)};
    Set_Pod1(P1);
    Set_Pod2(P2);
    Rysuj();
}

bool Graniastoslup6::Rysuj()
{

    if(Pod1.size() !=6 || Pod2.size() !=6 || apiSceny== nullptr )
    {
        std::cerr << "Blad podstawy nie maja 6 wierzcholkow lub api = nullptr\n";
        return false;
    }

    apii=apiSceny->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>> { Pwek2Ppoint(WyliczGlobalne(Pod1)) ,Pwek2Ppoint(WyliczGlobalne(Pod2))}, "red");
    return true;

}
std::vector<Wektor3D> Graniastoslup6::WyliczGlobalne(std::vector<Wektor3D> &in)
{
    std::vector<Wektor3D> WP=in;
    for(long unsigned int i=0;i<in.size();i++)
        WP[i] = srodek + (orientacja * in[i]);

    return WP;
}




