#include <iostream>
#include "../inc/Dr3D_gnuplot_api.hh"

#include "../inc/Dron.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;

#define KONIEC 1

/*void wait4key() {
    do {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}*/


int main() {
    //std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-5,5,-5,5,-5,5,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    drawNS::Draw3DAPI * api = new APIGnuPlot3D(-10,10,-10,10,-10,10,1000); //alternatywnie zwykły wskaźnik
    api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"



        Dron D;
        D.Inicjalizuj();

        int n=0,m,wybor, odleglosc,kat;
        char wej;
        while (n!=KONIEC)
        {
            cout<< "MENU\n 1 - Ruch\n 2 - Obrot\n 0 - kociec\n Twoj wybor: ";
            cin>> wybor;
            cout<<"\n";
            switch (wybor)
            {
                case 1:
                    {
                    cout << "Wyznacz odleglosc ruchu \n";
                    cin >> odleglosc;
                    cout << "Wybierz kierunek (awsd)\n";
                    cin >> wej;
                    m=0;
                    while (m != KONIEC)
                        switch (wej)
                        {
                            case 'a':
                                D.AnimujRuch(Bryla::Tyl,odleglosc,api);
                                m = KONIEC;
                                break;

                            case 'd':
                                D.AnimujRuch(Bryla::Przod,odleglosc,api);
                                m = KONIEC;
                                break;

                            case 's':
                                D.AnimujRuch(Bryla::Dol,odleglosc,api);
                                m = KONIEC;
                                break;

                            case 'w':
                                D.AnimujRuch(Bryla::Gora,odleglosc,api);
                                m = KONIEC;
                                break;

                            default:
                                cout << "Bledny kierunek (awsd), sprobuj ponownie\n";
                                break;
                        }

                    break;
                }

                case 2:
                    {
                    cout << "Wyznacz kat obrotu w stopniach\n";
                    cin >> kat;
                    cout << "Wybierz os obortu (xyz) x - przod; y - prawo; z - pion;\n";
                    cin >> wej;
                    m = 0;
                    while (m != KONIEC)
                        switch (wej)
                        {
                            case 'x':
                                m = KONIEC;
                                D.AnimujObrot(MacierzOb::OX, kat, api);
                                break;

                            case 'y':
                                m = KONIEC;
                                D.AnimujObrot(MacierzOb::OY, kat, api);
                                break;

                            case 'z':
                                m = KONIEC;
                                D.AnimujObrot(MacierzOb::OZ, kat, api);
                                break;

                            default:
                                cout << "Bledny wybor, sprobuj ponownie\n";
                                break;
                        }
                    break;
                }

                case 0:
                    cout<<"Koniec dzialania programu\n";
                    n=KONIEC;
                    break;

                default:
                    cout<<"Bledny wybor, sprobuj ponownie\n";


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

*/
    //delete api;//dla zwykłych wskaźników musimy posprzątać
}
