#ifndef SYMULACJADRONA_DRON_INTERFACE_HH
#define SYMULACJADRONA_DRON_INTERFACE_HH

/*!
 * \brief Implementacja abstrakcyjnej klasy DronInterface
 */

class DronInterface{
public:
    /*!
     * \brief Animuje ruch drona
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param odleglosc - odleglosc plyniecia drona
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     */
    virtual void AnimujRuch(const Wektor3D & Kier,const double & odleglosc) =0;
    /*!
     * \brief Animuje obrot drona
     * \param os - os obrotu (OsObrotu patrz \file MacierzKw.hh )
     * \param kat - kat w stopniach o jaki ma sie obrocic dron
     */
    virtual void AnimujObrot(const enum MacierzOb::OsObrotu os, double kat) =0;
    /*!
     * \brief Animuje ruch drona pod danym katem
     * \param Kier - wektor kierunku (najlepiej jednostkowy)
     * \param kat - odleglosc plyniecia drona
     * \param odleglosc - Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     * Uwaga: Kier jest mnożony przez przez odległość dlatego najlepiej podać wekor jednostkowy
     */
    virtual void RuchZeWzoszeniem(const Wektor3D & Kier ,const double & kat,const double & odleglosc)=0;
    /*!
     * \brief Utworzenie i narysowanie drona
     * \param api - wskaźnik sceny
     */
    virtual void InicjalizujDrona (std::shared_ptr<drawNS::Draw3DAPI> api)=0;
};

#endif
