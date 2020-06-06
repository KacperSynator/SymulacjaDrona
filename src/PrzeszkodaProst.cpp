#include "../inc/PrzeszkodaProst.hh"

bool PrzeszkodaProst::CzyKolizja(DronInterface * D)
{
 /*
    std::vector<Wektor3D> WP1=Pod1;
    std::vector<Wektor3D> WP2=Pod2;

    for(long unsigned int i=0;i<Pod1.size();i++)
        WP1[i]=srodek+Pod1[i]+D->ZwrocWierzcholek(i+1);

    for(long unsigned int i=0;i<Pod2.size();i++)
        WP2[i]=srodek+Pod2[i]+D->ZwrocWierzcholek(-i-1);
    */
    double promien=D->ZwrocDlugosc()-0.5;

    Wektor3D P1=Pod1[0];
    Wektor3D P2=Pod2[2];

    P1=srodek+P1+(Wektor3D(1,1,1)*promien);
    P2=srodek+P2-(Wektor3D(1,1,1)*promien);

    if(D->ZwrocPozycje()[0]<=std::max(P1[0],P2[0]) && D->ZwrocPozycje()[0]>=std::min(P1[0],P2[0]) && //prawo lewo
       D->ZwrocPozycje()[1]<=std::max(P1[1],P2[1]) && D->ZwrocPozycje()[1]>=std::min(P1[1],P2[1]) && //przod tyl
       D->ZwrocPozycje()[2]<=std::max(P1[2],P2[2]) && D->ZwrocPozycje()[2]>=std::min(P1[2],P2[2]))  //gora dol
    {
        std::cout<<"KOLIZJA z przeszkoda\n";
       /* std::cout << D->ZwrocPozycje()<<"\n";
        std::cout << P1[0]<<"\n";
        std::cout << P2[0] <<"\n";

        std::cout << P1[1] <<"\n";
        std::cout << P2[1] <<"\n";

        std::cout << P1[2] <<"\n";
        std::cout << P2[2] <<"\n"; */
        return true;
    }


    /*
     std::cout << D->ZwrocPozycje()<<"\n";
     std::cout << std::max(WP1[0][0],WP2[2][0])<<"\n";
     std::cout << std::min(WP1[0][0],WP2[2][0])<<"\n";

     std::cout << std::max(WP1[1][1],WP2[3][1])  <<"\n";
     std::cout << std::min(WP1[1][1],WP2[3][1]) <<"\n";

     std::cout << std::max(WP1[0][2],WP2[2][2]) <<"\n";
     std::cout << std::min(WP1[0][2],WP2[2][2]) <<"\n";

    if(D->ZwrocPozycje()[0]<=std::max(WP1[0][0],WP2[2][0]) && D->ZwrocPozycje()[0]>=std::min(WP1[0][0],WP2[2][0]) && //prawo lewo
       D->ZwrocPozycje()[1]<=std::max(WP1[1][1],WP2[3][1]) && D->ZwrocPozycje()[1]>=std::min(WP1[1][1],WP2[3][1]) && //przod tyl
       D->ZwrocPozycje()[2]<=std::max(WP1[0][2],WP2[2][2]) && D->ZwrocPozycje()[2]>=std::min(WP1[0][2],WP2[2][2]))  //gora dol
    {
        std::cout << "KOLZIJA\n";
       /* std::cout << D->ZwrocPozycje()<<"\n";
        std::cout << WP1[0][0]<<"\n";
        std::cout << WP1[1][0] <<"\n";

        std::cout << WP1[1][1] <<"\n";
        std::cout << WP1[2][1] <<"\n";

        std::cout << WP1[0][2] <<"\n";
        std::cout << WP2[0][2] <<"\n";
        return true;
    }
    */

    return false;
}

PrzeszkodaProst::PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr,enum MacierzOb::OsObrotu os)
{

    Inicjalizuj(api,sr);
    switch (os)
    {
        case MacierzOb::OX:{
            Pod1 = {Wektor3D(0.5, 2, 1.5), Wektor3D(-0.5, 2, 1.5), Wektor3D(-0.5, -2, 1.5),Wektor3D(0.5, -2, 1.5)};
            Pod2 = {Wektor3D(0.5, 2, -1.5), Wektor3D(-0.5, 2, -1.5), Wektor3D(-0.5, -2, -1.5),Wektor3D(0.5, -2, -1.5)};
            break;
        }

        case MacierzOb::OY:{
            Pod1 = {Wektor3D(1.5, 0.5, 2), Wektor3D(-1.5, 0.5, 2), Wektor3D(-1.5, -0.5, 2),Wektor3D(1.5, -0.5, 2)};
            Pod2 = {Wektor3D(1.5, 0.5, -2), Wektor3D(-1.5, 0.5, -2), Wektor3D(-1.5, -0.5, -2),Wektor3D(1.5, -0.5, -2)};
            break;
        }

        case MacierzOb::OZ: {
            Pod1 = {Wektor3D(1.5,2,0.5),Wektor3D(-1.5,2,0.5),Wektor3D(-1.5,-2,0.5),Wektor3D(1.5,-2,0.5)};
            Pod2 = {Wektor3D(1.5,2,-0.5),Wektor3D(-1.5,2,-0.5),Wektor3D(-1.5,-2,-0.5),Wektor3D(1.5,-2,-0.5)};
            break;
        }
    }
    Zmarz();
    Rysuj();
    apiSceny->change_shape_color(apii,"black");
}
