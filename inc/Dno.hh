#ifndef SYMULACJADRONA_DNO_HH
#define SYMULACJADRONA_DNO_HH

#include "Płaszczyzna.hh"
/*!
 * \brief Implementacja klasy Dno
 * Dziedziczy po \file Płaszczyzna.hh
 */
class Dno : public Plaszczyzna  {
public:
    /*!
    * \brief Utworzenie i narysowanie plaszczyzny dna
    * \param api - wskaźnik sceny
    */
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) ;

};


#endif
