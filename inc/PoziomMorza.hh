#ifndef SYMULACJADRONA_POZIOMMORZA_HH
#define SYMULACJADRONA_POZIOMMORZA_HH

#include "Płaszczyzna.hh"
#include "Przeszkoda_interface.hh"
/*!
 * \brief Implementacja klasy PoziomMorza
 * Dziedziczy po \file Płaszczyzna.hh oraz po \file Przeszkoda_interface.hh
 */
class PoziomMorza : public Plaszczyzna, public Przeszkoda_interface{
protected:
    /*!
    * \brief Utworzenie i narysowanie poziomu morza
     * \param api - wskaźnik sceny
    */
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) ;

public:
    /*!
    * \brief konstruktor bezparametryczny usunięty aby korzystać z parametrycznego
    */
    PoziomMorza()=delete ;
    /*!
     * \brief konstruktor parametryczny
     * \param api - api sceny
     * \param sr - srodek płaszczyzny
     */
    PoziomMorza(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr);
    /*!
     * \brief Sprawdzenie czy doszło do kolizji
     * \param wskaznik na interfejs drona
     * \return true jesli kolizja, przeciwnym przypadku false
     */
    bool CzyKolizja(DronInterface* D) override ;



};


#endif
