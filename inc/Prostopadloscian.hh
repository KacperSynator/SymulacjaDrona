#ifndef SYMULACJADRONA_PROSTOPADLOSCIAN_HH
#define SYMULACJADRONA_PROSTOPADLOSCIAN_HH

#include "Bryla.hh"

/*!
 * \brief Implementacja klasy Prostopadloscian
 * Dziedziczy po \file Bryla.hh
 */
class Prostopadloscian : public Bryla {
protected:
    /*!
     * Vector wierzcholkow pierwszej podstawy (lokalne)
     */
    std::vector<Wektor3D> Pod1;
    /*!
    * Vector wierzcholkow drugiej podstawy (lokalne)
    */
    std::vector<Wektor3D> Pod2;

public:

    /*!
     * \brief Tworzy i rysuje prostopadloscian
     * \param api - wskaznik api sceny
     */
    void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) ;
    /*!
     * \brief  - Rysuje prostopadloscian
     * \return - czy rysowanie się powiodło
     * Metoda wylicza globalne wierzcholki
     * Uwaga: nie dziala jesli nie wywolano wczesniej metody Inicjalizuj
     */
    bool Rysuj() override ;

    std::vector<Wektor3D> WyliczGlobalne(std::vector<Wektor3D> &in) override;


};


#endif
