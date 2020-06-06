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
              {
                  Ruch(kierunek*(-1),odleglosc/1000);
                  return true;
              }
        Zmarz();
        Rysuj();
        apiSceny->change_shape_color(apii,kolor);
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
        Zmarz();
        Rysuj();
        apiSceny->change_shape_color(apii,kolor);
        apiSceny->redraw();
    }
    return false;
}

void Dron::RuchZeWzoszeniem(const Wektor3D &Kier,const double & kat,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    AnimujObrot(MacierzOb::OX,kat,kp);
    if(!AnimujRuch(Kier,odleglosc,kp))
    AnimujObrot(MacierzOb::OX,-kat, kp);
}

void Dron::InicjalizujDrona(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)
{
    apiSceny=api;
    Inicjalizuj(api,sr);
    pozWL=Wektor3D(-0.75,-2.125,0);
    wirnikL.InicjalizujWirnik(srodek+pozWL,api);
    pozWP=Wektor3D(0.75,-2.125,0);
    wirnikP.InicjalizujWirnik(srodek+pozWP,api);
    apiSceny->redraw();
}

bool Dron::Menu(std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)
{
    using std::cout;
    using std::cin;
    int n = 0, m, wybor, odleglosc, kat;
    char wej;
    while (n != KONIEC)
    {
        cout <<"Kolor drona: "<< kolor<< "\n" << "MENU\n 1 - Ruch\n 2 - Obrot\n 3 - Zmiana drona\n 0 - koniec\n Twoj wybor: ";
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
                std::cout<<"\nUtworzono: " << Wektor3D::ZwrocUtworzone()<< " wektorow\n" << "Istnieje: " << Wektor3D::ZwrocIstniejace() << " wektorow\n\n";
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
                std::cout<<"Utworzono: " << Wektor3D::ZwrocUtworzone()<< " wektorow\n" << "Istnieje: " << Wektor3D::ZwrocIstniejace() << " wektorow\n";
                break;
            }
            case 3:
                cout<< "Zmiana drona\n";
                return false;
                break;


            case 0:
                cout << "Koniec dzialania programu\n";
                n = KONIEC;
                break;

            default:
                cout << "Bledny wybor, sprobuj ponownie\n";
                break;


        }
    }
    return true;
}

bool Dron::CzyKolizja(DronInterface* D)
{
    if(D == this)
        return false;

    double promien=D->ZwrocDlugosc();

    Wektor3D P1=Pod1[0];
    Wektor3D P2=Pod2[2];

    P1=orientacja*(srodek+P1+(Wektor3D(1,1,1)*promien));
    P2=orientacja*(srodek+P2-(Wektor3D(1,1,1)*promien));

    if(D->ZwrocPozycje()[0]<=std::max(P1[0],P2[0]) && D->ZwrocPozycje()[0]>=std::min(P1[0],P2[0]) && //prawo lewo
       D->ZwrocPozycje()[1]<=std::max(P1[1],P2[1]) && D->ZwrocPozycje()[1]>=std::min(P1[1],P2[1]) && //przod tyl
       D->ZwrocPozycje()[2]<=std::max(P1[2],P2[2]) && D->ZwrocPozycje()[2]>=std::min(P1[2],P2[2]))  //gora dol
    {
        std::cout<<"KOLIZJA z dronem: "<<kolor<<"\n";
        /*
        std::cout << D->ZwrocPozycje()<<"\n";
        std::cout << P1[0]<<"\n";
        std::cout << P2[0] <<"\n";

        std::cout << P1[1] <<"\n";
        std::cout << P2[1] <<"\n";

        std::cout << P1[2] <<"\n";
        std::cout << P2[2] <<"\n";
         */
        return true;
    }

    return false;

}

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr, const std::string k )
{
    kolor=k;
    InicjalizujDrona(api,sr);
    apiSceny->change_shape_color(apii,kolor);

}

