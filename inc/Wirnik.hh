#ifndef SYMULACJADRONA_WIRNIK_HH
#define SYMULACJADRONA_WIRNIK_HH

#include "Graniastoslup6.hh"
/*!
 * \brief Impementacja klasy Wirnik
 * Dziedziczy po \file Graniastoslup6.hh
 */
class Wirnik : public Graniastoslup6{
public:
    /*!
     * \brief Tworzy i rysuje wirnik
     * \param sr - srodek wirnika
     * \param api - wskaznik api sceny
     */
    void InicjalizujWirnik(const Wektor3D & sr, std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief Animuje ruch wirnika
     * \param sr - srodek wirnika
     * \param ob - nowa globalna macierz obrotu wirnika
     * \param kat - kat o jaki ma obrocic wirnik
     * Metoda wywolywana podczas animacji ruchu drona
     * Wirnik obracany jest wokol osi Y
     */
    void RuchDrona(const Wektor3D & sr,MacierzOb & ob,const double & kat);
};


#endif
