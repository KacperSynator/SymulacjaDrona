#ifndef SYMULACJADRONA_POZIOMMORZA_HH
#define SYMULACJADRONA_POZIOMMORZA_HH

#include "Płaszczyzna.hh"
/*!
 * \brief Implementacja klasy PoziomMorza
 * Dziedziczy po \file Płaszczyzna.hh
 */
class PoziomMorza : public Plaszczyzna{

public:
    /*!
    * \brief Utworzenie i narysowanie poziomu morza
    * \param api - wskaźnik sceny
    */
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) ;

};


#endif
