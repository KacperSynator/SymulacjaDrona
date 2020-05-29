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
    std::vector<Wektor3D> Pod11=std::vector<Wektor3D>(6) ;
    std::vector<Wektor3D> Pod22=std::vector<Wektor3D>(6) ;

    for(long unsigned int i=0;i<Pod1.size();i++)
        Pod11[i] = srodek + (orientacja * Pod1[i]);


    for(long unsigned int i=0;i<Pod2.size();i++)
        Pod22[i] = srodek + (orientacja * Pod2[i]);

    if(Pod1.size() !=6 || Pod2.size() !=6 || apiSceny== nullptr )
    {
        std::cerr << "Blad podstawy nie maja 6 wierzcholkow lub api = nullptr\n";
        return false;
    }

    apii=apiSceny->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>> { Pwek2Ppoint(Pod11) ,Pwek2Ppoint(Pod22)}, "red");
    return true;

}




