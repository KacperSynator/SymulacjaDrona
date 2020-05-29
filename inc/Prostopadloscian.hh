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

    /*!
    * \brief Ustawienie podstawy pierwszej
    * \param vekP - vector wspolrzednych wierzcholkow
    */
    void Set_Pod1(const std::vector<Wektor3D> & vekP) {Pod1=vekP;}
    /*!
    * \brief Ustawienie podstawy drugiej
    * \param vekP - vector wspolrzednych wierzcholkow
    */
    void Set_Pod2(const std::vector<Wektor3D> & vekP) {Pod2=vekP;}
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


};


#endif
