#include "../inc/Prostopadloscian.hh"

bool Prostopadloscian::Rysuj()
{
    std::vector<Wektor3D> Pod11=std::vector<Wektor3D>(4) ;
    std::vector<Wektor3D> Pod22=std::vector<Wektor3D>(4) ;

    for(int i=0;i<Pod1.size();i++)
        Pod11[i] = srodek + (orientacja * Pod1[i]);


    for(int i=0;i<Pod2.size();i++)
        Pod22[i] = srodek + (orientacja * Pod2[i]);

    if(Pod1.size() !=4 || Pod2.size() !=4 || apiSceny == nullptr )
    {
        std::cerr << "Blad podstawy nie maja 4 wierzcholkow lub api = nullptr\n";
        return false;
    }

    apii=apiSceny->draw_polyhedron(std::vector<std::vector<drawNS::Point3D>> { Pwek2Ppoint(Pod11) ,Pwek2Ppoint(Pod22)}, "purple");
    return true;


}
void Prostopadloscian:: Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    apiSceny=api;
    std::vector<Wektor3D> P1 = {Wektor3D(1.5,2,0.5),Wektor3D(-1.5,2,0.5),Wektor3D(-1.5,-2,0.5),Wektor3D(1.5,-2,0.5)};
    std::vector<Wektor3D> P2 = {Wektor3D(1.5,2,-0.5),Wektor3D(-1.5,2,-0.5),Wektor3D(-1.5,-2,-0.5),Wektor3D(1.5,-2,-0.5)};
    Set_Pod1(P1);
    Set_Pod2(P2);
    Rysuj();
}





