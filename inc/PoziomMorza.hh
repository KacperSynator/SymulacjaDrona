#ifndef SYMULACJADRONA_POZIOMMORZA_HH
#define SYMULACJADRONA_POZIOMMORZA_HH

#include "Płaszczyzna.hh"
/*!
 * \brief Implementacja klasy PoziomMorza
 * Dziedziczy po \file Płaszczyzna.hh
 */
class PoziomMorza : public Plaszczyzna{
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


};


#endif
