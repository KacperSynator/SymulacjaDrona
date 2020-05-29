#ifndef SYMULACJADRONA_DRON_HH
#define SYMULACJADRONA_DRON_HH

#include "Prostopadloscian.hh"
#include "Dron_interface.hh"
#include "Przeszkoda_interface.hh"

#define KONIEC 1

using std::cout;
using std::cin;
/*!
 * \brief Implementacja klasy Dron
 * Dziedziczy po \file Prostopadloscian.hh oraz po \file DronInterface.hh oraz \file Przeszkoda_interface.hh
 */
class Dron : public Prostopadloscian, public DronInterface, public Przeszkoda_interface  {
protected:
    /*!
     * wskaznik na interjejs drona
     */
    std::shared_ptr<Dron> D;
    /*!
    * wskaznik na kolekcje przeszkod
    */
    std::shared_ptr<std::vector<std::shared_ptr<Przeszkoda_interface>>> P;
public:
    /*!
     * \brief konstruktor bezparametryczny
     */
    Dron() {};
    Dron(std::shared_ptr<drawNS::Draw3DAPI> api,const std::vector<std::shared_ptr<Przeszkoda_interface>> &kp,const Wektor3D & sr);
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
    void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) override ;
    /*!
     * \brief Menu sterowania dronem
     * Daję możliwość obrotu drona i ruchu pod zadanym katem
     */
    void Menu();
    /*!
    * \brief Sprawdzenie czy doszło do kolizji
    * \param wskaznik na interfejs drona
    * \return true jesli kolizja, przeciwnym przypadku false
    */
    bool CzyKolizja(std::shared_ptr<DronInterface>);

    Wektor3D ZwrocPozycje() {return srodek;}
};


#endif
