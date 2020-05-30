#ifndef SYMULACJADRONA_PRZESZKODAPROST_HH
#define SYMULACJADRONA_PRZESZKODAPROST_HH

#include "Przeszkoda_interface.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"

/*!
 * \brief Implementacja klasy przeszkoda prostopadlocienna
 * Dziedziczy po \file Przeszkoda_interface.hh oraz \file Prostopadloscian.hh
 */
class PrzeszkodaProst : public Przeszkoda_interface, public Prostopadloscian {
public:
    /*!
     * \brief konstruktor bezparametryczny usunięty aby korzystać z parametrycznego
     */
    PrzeszkodaProst()=delete ;
    /*!
    * \brief konstruktor parametryczny
    * \param api - api sceny
    * \param sr - srodek przeszkody
     * \param os - os do której przeszkoda jest prostopadła
    */
    PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr,const enum MacierzOb::OsObrotu os);
    /*!
      * \brief Sprawdzenie czy doszło do kolizji
      * \param wskaznik na interfejs drona
      * \return true jesli kolizja, przeciwnym przypadku false
      */
    bool CzyKolizja(DronInterface* D);
};


#endif
