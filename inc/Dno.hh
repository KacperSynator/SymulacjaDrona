#ifndef SYMULACJADRONA_DNO_HH
#define SYMULACJADRONA_DNO_HH

#include "Płaszczyzna.hh"
/*!
 * \brief Implementacja klasy Dno
 * Dziedziczy po \file Płaszczyzna.hh
 */
class Dno : public Plaszczyzna  {
protected:
    /*!
    * \brief Utworzenie i narysowanie plaszczyzny dna
    * \param api - wskaźnik sceny
    */
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) ;

public:
    /*!
    * \brief konstruktor bezparametryczny usunięty aby korzystać z parametrycznego
    */
    Dno()=delete ;
    /*!
    * \brief konstruktor parametryczny
    * \param api - api sceny
    * \param sr - srodek płaszczyzny
    */
    Dno(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D & sr);

};


#endif
