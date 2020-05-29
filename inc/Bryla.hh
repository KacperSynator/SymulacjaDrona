#ifndef SYMULACJADRONA_BRYLA_H
#define SYMULACJADRONA_BRYLA_H


#include "ObiektRysowalny.hh"


/*!
 * \brief Implementacja abstrakcyjnej klasy bryła
 * Dziedziczy po \file ObiektRysowalny.hh
 */

class Bryla : public ObiektRysowalny
{
protected:
    /*!
     * macierz orientacji bryly
     */
    MacierzOb orientacja;
    /*!
     * srodek bryly (na razie taki)
     */
    Wektor3D srodek=Wektor3D(0,0,0);


public:
    /*!
     * \brief Ruch bryly
     * \param kierunek - wektor kierunku (najlepiej jednostkowy)
     * \param odleglosc - odleglosc przesuniecia bryly
     * Uwaga: kierunek jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     */
    void Ruch(const Wektor3D & kierunek,const double odleglosc);
    /*!
     * \brief Obrot bryly
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic bryla
     */
    void Obrot(const enum MacierzOb::OsObrotu os, double kat) ;
    /*!
     * \brief Utworzenie i narysowanie bryly
     * \param api - wskaźnik sceny
     */
    virtual void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr) override = 0;
    /*!
    * \brief  Rysuje bryle
    * \return czy rysowanie się powiodło
    */
    virtual bool Rysuj() override = 0;


};


#endif
