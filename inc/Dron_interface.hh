#ifndef SYMULACJADRONA_DRON_INTERFACE_HH
#define SYMULACJADRONA_DRON_INTERFACE_HH

#include "Wirnik.hh"

/*!
 * \brief Implementacja abstrakcyjnej klasy DronInterface
 */

class DronInterface{
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
     * \brief Animuje ruch drona
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param odleglosc - odleglosc plyniecia drona
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     */
    virtual void AnimujRuch(const Wektor3D & Kier,const double & odleglosc) =0;
    /*!
     * \brief Animuje obrot drona
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic dron
     */
    virtual void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat) =0;
    /*!
     * \brief Animuje ruch drona pod danym katem
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param kat - odleglosc plyniecia drona
     * \param odleglosc - Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     */
    virtual void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & kat,const double & odleglosc)=0;
    /*!
     * \brief Utworzenie i narysowanie drona
     * \param api - wskaźnik sceny
     */
    virtual void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)=0;

    /*!
     * \brief Zwaraca aktualna pozycje dorna
     * \return Wektor pozycji
     */
    virtual Wektor3D ZwrocPozycje() = 0;
};

#endif
