#ifndef SYMULACJADRONA_DRON_HH
#define SYMULACJADRONA_DRON_HH

#include "Prostopadloscian.hh"
#include "Dron_interface.hh"
#include "Przeszkoda_interface.hh"

#define KONIEC 1


/*!
 * \brief Implementacja klasy Dron
 * Dziedziczy po \file Prostopadloscian.hh oraz po \file DronInterface.hh oraz \file Przeszkoda_interface.hh
 */
class Dron : public Prostopadloscian, public DronInterface, public Przeszkoda_interface  {
protected:
    /*!
     * Wirnik prawy drona (\file Wirnik.hh )
     */
    Wirnik wirnikP;
    /*!
     * Pozycja wirnika prawego wzgledem srodka drona
     */
    Wektor3D pozWP;
    /*!
     * Wirnik lewy drona (\file Wirnik.hh )
     */
    Wirnik wirnikL;
    /*!
     * Pozycja wirnika lewego wzgledem srodka drona
    */
    Wektor3D pozWL;
    /*!
    * \brief Utworzenie i narysowanie drona
    * \param api - wskaźnik sceny
    */
    void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) override ;
public:
    /*!
     * \brief konstruktor bezparametryczny usunięty aby korzystać z parametrycznego
     */
    Dron() =delete;
    /*!
    * \brief konstruktor parametryczny
    * \param api - api sceny
    * \param sr - srodek drona
    */
    Dron(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr);
    /*!
    * \brief Animuje ruch drona
    * \param Kier - wektor kierunku (najlepiej jednostkowy)
    * \param odleglosc - odleglosc plyniecia drona
     * \param kp - kolekcja przeszkod
    * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
    */
    bool AnimujRuch(const Wektor3D & kierunek,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp) ;
    /*!
     * \brief Animuje obrot drona
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic dron
     * \param kp - kolekcja przeszkod
     * \return prawda - kolizja, fałsz - bez kolizji
     */
    bool AnimujObrot(const enum MacierzOb::OsObrotu os, double kat, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp) ;
    /*!
    * \brief Animuje ruch drona pod danym katem
    * \param Kier - wektor kierunku (najlepiej jednostkowy)
    * \param kat - kat w stopniach o jaki ma sie obrocic dron
    * \param odleglosc - odleglosc plyniecia drona
     * \param kp - kolekcja przeszkod
     *\return prawda - kolizja, fałsz - bez kolizji
    * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
    */
    void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & kat,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp) ;

    /*!
     * \brief Menu sterowania dronem
     * \param kp - kolekcja przeszkod
     * Daję możliwość obrotu drona i ruchu pod zadanym katem
     */
    void Menu(std::vector<std::shared_ptr<Przeszkoda_interface>> &kp) ;
    /*!
    * \brief Sprawdzenie czy doszło do kolizji
    * \param wskaznik na interfejs drona
    * \return true jesli kolizja, przeciwnym przypadku false
    */
    bool CzyKolizja(DronInterface*) override ;

    Wektor3D ZwrocPozycje() override {return srodek;}

    Wektor3D ZwrocWierzcholek(int i) override {if(i<-5 || i>5 || i==0) std::cout<<"poza zakresem\n";
                                                if(i>0) return Pod1[i-1]; else return Pod2[-i-1];};

    MacierzOb ZwrocOrientacje() override {return orientacja;}

    double ZwrocDlugosc() override {return Pod1[0].dlugosc();}


};


#endif
