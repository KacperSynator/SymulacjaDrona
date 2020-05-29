#include "../inc/Dron.hh"
void Dron::AnimujRuch(const Wektor3D & kierunek,const double & odleglosc)
{
    for (int i = 0; i < 1000; i++)
    {
        Ruch(kierunek, odleglosc/1000);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        CzyKolizja(D);
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
}

void Dron::AnimujObrot(const MacierzOb::OsObrotu os, double kat)
{
    for(int i=0;i<300;i++)
    {
        Obrot(os,kat/300);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
}

void Dron::RuchZeWzoszeniem(const Wektor3D &Kier,const double & kat,const double & odleglosc)
{
    if(kat!=0)
    AnimujObrot(MacierzOb::OX,kat);
    AnimujRuch(Kier,odleglosc);
    if(kat!=0)
    AnimujObrot(MacierzOb::OX,-kat);
}

void Dron::InicjalizujDrona(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)
{
    D = (std::shared_ptr<Dron>)this;
    apiSceny=api;
    Inicjalizuj(api,sr);
    pozWL=Wektor3D(-0.75,-2.125,0);
    wirnikL.InicjalizujWirnik(pozWL,api);
    pozWP=Wektor3D(0.75,-2.125,0);
    wirnikP.InicjalizujWirnik(pozWP,api);
    apiSceny->redraw();
}

void Dron::Menu()
{
    int n = 0, m, wybor, odleglosc, kat;
    char wej;
    while (n != KONIEC)
    {
        cout << "MENU\n 1 - Ruch\n 2 - Obrot\n 0 - koniec\n Twoj wybor: ";
        cin >> wybor;
        cout << "\n";
        switch (wybor)
        {
            case 1: {
                cout << "Podaj kat pod jakim ma plynac (w stopniach)\n";
                cin >> kat;
                cout << "Podaj odległość na jaką ma płynąć dron\n";
                cin >> odleglosc;
                RuchZeWzoszeniem(Wektor3D(0, 1, 0), kat, odleglosc);
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
                break;


        }
    }
}

bool Dron::CzyKolizja(std::shared_ptr<DronInterface>)
{
    for(auto elem : kolekcja_przeskod)
        if(elem->CzyKolizja(D))
            return true;

     return false;
}

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> api,const std::vector<std::shared_ptr<Przeszkoda_interface>> &kp,const Wektor3D & sr)
{
    kolekcja_przeskod=kp;
    InicjalizujDrona(api,sr);
}

