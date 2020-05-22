#ifndef SYMULACJADRONA_DRON_HH
#define SYMULACJADRONA_DRON_HH

#include "Prostopadloscian.hh"
#include "Dron_interface.hh"
#include "Wirnik.hh"

#define KONIEC 1

using std::cout;
using std::cin;

/*!
 * \brief Implementacja klasy Dron
 * Dziedziczy po \file Prostopadloscian.hh oraz po \file DronInterface.hh
 */
class Dron : public Prostopadloscian, public DronInterface {
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
public:
    /*!
     * \brief konstruktor bezparametryczny
     */
    Dron() {};

    /*!
    * \brief Animuje ruch drona
    * \param Kier - wektor kierunku (najlepiej jednostkowy)
    * \param odleglosc - odleglosc plyniecia drona
    * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
    */
    void AnimujRuch(const Wektor3D & kierunek,const double & odleglosc);
    /*!
     * \brief Animuje obrot drona
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic dron
     */
    void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat);
    /*!
    * \brief Animuje ruch drona pod danym katem
    * \param Kier - wektor kierunku (najlepiej jednostkowy)
    * \param kat - kat w stopniach o jaki ma sie obrocic dron
    * \param odleglosc - odleglosc plyniecia drona
    * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
    */
    void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & kat,const double & odleglosc);
    /*!
     * \brief Utworzenie i narysowanie drona
     * \param api - wskaźnik sceny
     */
    void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief Menu sterowania dronem
     * Daję możliwość obrotu drona i ruchu pod zadanym katem
     */
    void Menu();
};


#endif
