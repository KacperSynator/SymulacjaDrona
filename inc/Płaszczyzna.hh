#ifndef SYMULACJADRONA_PLASZCZYZNA_HH
#define SYMULACJADRONA_PLASZCZYZNA_HH

#include "ObiektRysowalny.hh"

/*!
 * \brief Implementacja klasy plaszczyzna
 * Dziedziczy po \file ObiektRysowalny.hh
 */
class Plaszczyzna : public ObiektRysowalny {
protected:
    /*!
    * Vector wierzcholkow plaszczyzny (lokalne)
    */
    std::vector<std::vector<drawNS::Point3D>> Wierzcholki;
public:
    /*!
    * \brief Utworzenie i narysowanie plaszczyzny
    * \param api - wskaźnik sceny
    */
    virtual void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api) =0 ;
    /*!
    * \brief   Rysuje plaszczyzne
    * \return  czy rysowanie się powiodło
    */
    bool Rysuj() ;

};


#endif
