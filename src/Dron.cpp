#include "../inc/Dron.hh"
void Dron::AnimujRuch(const Wektor3D & kierunek,const double & odleglosc)
{
    for (int i = 0; i < 1000; i++)
    {
        Ruch(kierunek, odleglosc/1000);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
}

void Dron::AnimujObrot(const MacierzOb::OsObrotu os, double kat)
{
    for(int i=0;i<1000;i++)
    {
        Obrot(os,kat/1000);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
}

void Dron::RuchZeWzoszeniem(const Wektor3D &Kier,const double & h,const double & odleglosc)
{
    double kat=180*atan(h/odleglosc)/PI;
    AnimujObrot(MacierzOb::OX,kat);
    AnimujRuch(Kier,sqrt(h*h + odleglosc*odleglosc));
    AnimujObrot(MacierzOb::OX,-kat);
}

void Dron::InicjalizujDrona()
{
    Inicjalizuj();
    wirnikL.Set_apiSceny(Get_apiSceny());
    wirnikP.Set_apiSceny(Get_apiSceny());
    pozWL=Wektor3D(-0.75,-2.125,0);
    wirnikL.InicjalizujWirnik(pozWL);
    pozWP=Wektor3D(0.75,-2.125,0);
    wirnikP.InicjalizujWirnik(pozWP);
    apiSceny->redraw();
}

void Dron::Menu() {
    int n = 0, m, wybor, odleglosc, kat, h;
    char wej;
    while (n != KONIEC) {
        cout << "MENU\n 1 - Ruch\n 2 - Obrot\n 0 - koniec\n Twoj wybor: ";
        cin >> wybor;
        cout << "\n";
        switch (wybor) {
            case 1: {
                cout << "Czy dron ma\n  s - opadać\n  w - wznosić się\n  d - tylko plynac na wprost\n";
                cin >> wej;
                m = 0;
                while (m != KONIEC)
                    switch (wej) {
                        case 'w':
                            m = KONIEC;
                            cout << "Podaj odległość na jaką ma płynąć dron w poziomie\n";
                            cin >> odleglosc;
                            cout << "Podaj wysokość o jaką dron ma się wznieść\n";
                            cin >> h;
                            RuchZeWzoszeniem(Wektor3D(0, 1, 0), h, odleglosc);
                            break;

                        case 's':
                            m = KONIEC;
                            m = KONIEC;
                            cout << "Podaj odległość na jaką ma płynąć dron w poziomie\n";
                            cin >> odleglosc;
                            cout << "Podaj wysokość o jaką dron ma opaść \n";
                            cin >> h;
                            RuchZeWzoszeniem(Wektor3D(0, 1, 0), -h, odleglosc);
                            break;

                        case 'd':
                            m = KONIEC;
                            cout << "Podaj odległość na jaką ma płynąć dron\n";
                            cin >> odleglosc;
                            AnimujRuch(Wektor3D(0, 1, 0), odleglosc);
                            break;

                        default:
                            cout << "Bledny wybor, sprobuj ponownie\n";
                            break;

                    }
                break;
            }

            case 2: {
                cout << "Wyznacz kat obrotu w stopniach\n";
                cin >> kat;
                cout << "Wybierz os obortu (xyz) x - prawo; y - przod; z - pion;\n";
                cin >> wej;
                m = 0;
                while (m != KONIEC)
                    switch (wej) {
                        case 'x':
                            m = KONIEC;
                            AnimujObrot(MacierzOb::OX, kat);
                            break;

                        case 'y':
                            m = KONIEC;
                            AnimujObrot(MacierzOb::OY, kat);
                            break;

                        case 'z':
                            m = KONIEC;
                            AnimujObrot(MacierzOb::OZ, kat);
                            break;

                        default:
                            cout << "Bledny wybor, sprobuj ponownie\n";
                            break;
                    }
                break;
            }

            case 0:
                cout << "Koniec dzialania programu\n";
                n = KONIEC;
                break;

            default:
                cout << "Bledny wybor, sprobuj ponownie\n";


        }
    }
}