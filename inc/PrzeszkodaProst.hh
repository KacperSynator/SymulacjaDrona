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
    PrzeszkodaProst(std::shared_ptr<drawNS::Draw3DAPI> api, std::vector<std::shared_ptr<Przeszkoda_interface>> kp,const Wektor3D & sr);
    /*!
      * \brief Sprawdzenie czy doszło do kolizji
      * \param wskaznik na interfejs drona
      * \return true jesli kolizja, przeciwnym przypadku false
      */
    bool CzyKolizja(std::shared_ptr<DronInterface>);
};


#endif
