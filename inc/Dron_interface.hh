#ifndef SYMULACJADRONA_DRON_INTERFACE_HH
#define SYMULACJADRONA_DRON_INTERFACE_HH

#include "Wirnik.hh"
#include "Przeszkoda_interface.hh"

class Przeszkoda_interface;

/*!
 * \brief Implementacja abstrakcyjnej klasy DronInterface
 */

class DronInterface{
protected:
    /*!
     * \brief Utworzenie i narysowanie drona
     * \param api - wskaźnik sceny
     */
    virtual void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)=0;
public:
    /*!
     * \brief Animuje ruch drona
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param odleglosc - odleglosc plyniecia drona
     * \param kp - kolekcja przeszkod
     */
    virtual bool AnimujRuch(const Wektor3D & Kier,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)=0;
    /*!
     * \brief Animuje obrot drona
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic dron
     * \param kp - kolekcja przeszkod
     */
    virtual bool AnimujObrot(const enum MacierzOb::OsObrotu os, double kat, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)=0;
    /*!
     * \brief Animuje ruch drona pod danym katem
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param kat - odleglosc plyniecia drona
     * \param odleglosc - Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     * \param kp - kolekcja przeszkod
     */
    virtual void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & kat,const double & odleglosc, std::vector<std::shared_ptr<Przeszkoda_interface>> &kp)=0;

    /*!
     * \brief Menu sterowania dronem
     * Daję możliwość obrotu drona i ruchu pod zadanym katem
     * \param kp - kolekcja przeszkod
     */
    virtual bool Menu(std::vector<std::shared_ptr<Przeszkoda_interface>> &kp) = 0;

    /*!
     * \brief Zwaraca aktualna pozycje dorna
     * \return Wektor pozycji
     */
    virtual Wektor3D ZwrocPozycje() = 0;
    /*!
     * \brief Zwraca aktualna orientacje drona
     * \return Macierz orientacji
     */
    virtual MacierzOb ZwrocOrientacje() = 0;
    /*!
     * \brief Zwraca dlugość połowy przekątnej drona
     * \return dlugosc przekatnej
     */
    virtual  double ZwrocDlugosc() = 0;
    /*!
     * \brief zwraca wektor lokalny wierzcholka i-1
     * \param i - index wierzchołka +1 (dodatnie Pod1, ujemne Pod2)
     * \return wierzcholek lokalny
     */
    virtual Wektor3D ZwrocWierzcholek(int i)=0;
};

#endif
