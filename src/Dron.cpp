#include "../inc/Dron.hh"
bool Dron::AnimujRuch(const Wektor3D & kierunek,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    for (int i = 0; i < 1000; i++)
    {
        Ruch(kierunek, odleglosc/1000);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        for(auto elem : kp)
            if(elem->CzyKolizja(this))
                return true;
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
    return false;
}

bool Dron::AnimujObrot(const MacierzOb::OsObrotu os, double kat, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    for(int i=0;i<300;i++)
    {
        Obrot(os,kat/300);
        wirnikL.RuchDrona(srodek+orientacja*pozWL,orientacja,i);
        wirnikP.RuchDrona(srodek+orientacja*pozWP,orientacja,i);
        for(auto elem : kp)
            if(elem->CzyKolizja(this))
                return true;
        Zmarz();
        Rysuj();
        apiSceny->redraw();
    }
    return false;
}

void Dron::RuchZeWzoszeniem(const Wektor3D &Kier,const double & kat,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    if(!AnimujObrot(MacierzOb::OX,kat,kp))
    if(!AnimujRuch(Kier,odleglosc,kp))
    AnimujObrot(MacierzOb::OX,-kat, kp);
}

void Dron::InicjalizujDrona(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)
{
    apiSceny=api;
    Inicjalizuj(api,sr);
    pozWL=Wektor3D(-0.75,-2.125,0);
    wirnikL.InicjalizujWirnik(pozWL,api);
    pozWP=Wektor3D(0.75,-2.125,0);
    wirnikP.InicjalizujWirnik(pozWP,api);
    apiSceny->redraw();
}

void Dron::Menu(std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    using std::cout;
    using std::cin;
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
                RuchZeWzoszeniem(Wektor3D(0, 1, 0), kat, odleglosc, kp);
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
                            AnimujObrot(MacierzOb::OX, kat, kp);
                            break;

                        case 'y':
                            m = KONIEC;
                            AnimujObrot(MacierzOb::OY, kat, kp);
                            break;

                        case 'z':
                            m = KONIEC;
                            AnimujObrot(MacierzOb::OZ, kat, kp);
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

bool Dron::CzyKolizja(DronInterface*)
{
    /*for(auto elem : kolekcja_przeskod)
        if(elem->CzyKolizja(D))
            return true;

     return false;*/
}

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr)
{
    InicjalizujDrona(api,sr);
}

