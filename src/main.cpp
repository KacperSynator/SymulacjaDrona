#include <iostream>
#include "../inc/Dr3D_gnuplot_api.hh"

#include "../inc/Dron.hh"
#include "../inc/Dno.hh"
#include "../inc/PoziomMorza.hh"
#include "../inc/PrzeszkodaProst.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;


/*void wait4key() {
    do {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}*/


int main()
{
    //std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
   // drawNS::Draw3DAPI *api = new APIGnuPlot3D(-10, 10, -10, 10, -10, 10, 1000); //alternatywnie zwykły wskaźnik
   // api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

    std::shared_ptr<drawNS::Draw3DAPI> api(new drawNS::APIGnuPlot3D(-10,10,-10,10,-10,10,-1));
    std::vector<std::shared_ptr<Przeszkoda_interface>> Kolekcja_Przeskod;
    std::vector<std::shared_ptr<Dron>> Kolekcja_Dronow;

    Kolekcja_Dronow.push_back(static_cast<std::shared_ptr<Dron>>(new Dron(api,Wektor3D(0,0,0),"purple")));
    Kolekcja_Dronow.push_back(static_cast<std::shared_ptr<Dron>>(new Dron(api,Wektor3D(7,-5,4),"red")));
    Kolekcja_Dronow.push_back(static_cast<std::shared_ptr<Dron>>(new Dron(api,Wektor3D(-7,5,-2),"green")));


for(const auto & elem : Kolekcja_Dronow)
        Kolekcja_Przeskod.push_back(elem);

    Kolekcja_Przeskod.push_back(static_cast<std::shared_ptr<Przeszkoda_interface>>(new Dno(api,Wektor3D(0,0,-9))));
    Kolekcja_Przeskod.push_back(static_cast<std::shared_ptr<Przeszkoda_interface>>(new PoziomMorza(api,Wektor3D(0,0,9))));

    Kolekcja_Przeskod.push_back(static_cast<std::shared_ptr<Przeszkoda_interface>>(new PrzeszkodaProst(api, Wektor3D(0, 6, 0), MacierzOb::OY)));
    Kolekcja_Przeskod.push_back(static_cast<std::shared_ptr<Przeszkoda_interface>>(new PrzeszkodaProst(api,Wektor3D(6,2,4),MacierzOb::OX)));
    Kolekcja_Przeskod.push_back(static_cast<std::shared_ptr<Przeszkoda_interface>>(new PrzeszkodaProst(api,Wektor3D(-3,-2,-4),MacierzOb::OZ)));

    api->redraw();

    for(int i=0;i<Kolekcja_Dronow.size();++i)
    {
        if(Kolekcja_Dronow[i]->Menu(Kolekcja_Przeskod))
            break;

        if(i==(Kolekcja_Dronow.size()-1))
            i=-1;
    }

}





    /*
    int a=api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(2,0,0)); //rysuje linię pomiędzy (0,0,0) a (2,0,0), zapamiętuje id kształtu w zmiennej a
    api->draw_line(drawNS::Point3D(0,0,0),drawNS::Point3D(0,0,5),"red"); //rysuje czerwoną linie pomiędzy (0,0,0) a (0,0,5)

    cout << endl << "pojawiły się 2 linie: czarna i czerwona" << endl;
    wait4key();

    api->erase_shape(a); //usuwa kształt o id a
    cout << "czarna linia zniknęła" << endl;

    wait4key();

    api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
                                               drawNS::Point3D(0,4,0),drawNS::Point3D(4,4,0),
                                               drawNS::Point3D(4,0,0),drawNS::Point3D(4,0,4)},"purple"); //rysuje fioletową łamaną
    cout << "pojawiła się fioletowa łamana" << endl;

    wait4key();
    api->change_ref_time_ms(1000);
    int b=api->draw_polygonal_chain(vector<Point3D> {drawNS::Point3D(0,0,0),
                                                     drawNS::Point3D(0,-4,0),drawNS::Point3D(-4,-4,0),
                                                     drawNS::Point3D(-4,0,0),drawNS::Point3D(-4,0,-4)},"green");
    cout << "pojawiła się zielona łamana" << endl;

    wait4key();
    api->change_shape_color(b,"yellow");//zmienia kolor
    cout << "zmiana koloru z zielonej na żółtą" << endl;

    wait4key();
    api->change_ref_time_ms(-1);//odświerzanie sceny zmienione na opcję "tylko za pomocą metody redraw()"

    api->draw_polyhedron(vector<vector<Point3D> > {{
                                                           drawNS::Point3D(0,0,0), drawNS::Point3D(0,1,0), drawNS::Point3D(1,1,0)
                                                   },{
                                                           drawNS::Point3D(0,0,3), drawNS::Point3D(0,1,3), drawNS::Point3D(1,2,4)
                                                   }},"blue");//rysuje niebieski graniastosłup
    cout << "nie pojawiła się niebieski graniastosłup" << endl;

    wait4key();

    api->redraw();//odświerzenie sceny
    cout << "dopiero teraz pojawiła się niebieski graniastosłup" << endl;

    wait4key();
    api->change_ref_time_ms(0);

    api->draw_surface(vector<vector<Point3D> > {{
                                                        drawNS::Point3D(-4,-2,-4), drawNS::Point3D(-4,0,-4), drawNS::Point3D(-4,2,-4)
                                                },{
                                                        drawNS::Point3D(-2,-2,-4), drawNS::Point3D(-2,0,-4), drawNS::Point3D(-2,2,-4)
                                                },{
                                                        drawNS::Point3D(-0,-2,-4), drawNS::Point3D(-0,0,-3), drawNS::Point3D(-0,2,-4)
                                                },{
                                                        drawNS::Point3D(2,-2,-4), drawNS::Point3D(2,0,-4), drawNS::Point3D(2,2,-4)
                                                },{
                                                        drawNS::Point3D(4,-2,-4), drawNS::Point3D(4,0,-4), drawNS::Point3D(4,2,-4)
                                                }},"grey");//rysuje szarą powierzchnie
    cout << "pojawiła się szara powierzchnia" << endl;


    wait4key();
}
*/
    //delete api;//dla zwykłych wskaźników musimy posprzątać

