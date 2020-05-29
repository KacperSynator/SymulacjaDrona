#ifndef SYMULACJADRONA_OBIEKTRYSOWALNY_HH
#define SYMULACJADRONA_OBIEKTRYSOWALNY_HH

#include "MacierzOb.hh"
#include "Wektor3D.hh"
#include <vector>

/*!
 * \brief Implementacja abstrakcyjnej klasy obiekt rysowalny
 */
class ObiektRysowalny {
protected:
    /*!
     * api obiektu rysowalnego
     */
    int apii;
    /*!
     * wskaznik api sceny
     */
    std::shared_ptr<drawNS::Draw3DAPI> apiSceny;
public:
    /*!
    * \brief Utworzenie i narysowanie obiektu rysowalnego
    * \param api - wskaźnik sceny
    */
    virtual void Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr) = 0;
    /*!
    * \brief   Rysuje obiekt rysowalny
    * \return  czy rysowanie się powiodło
     */
    virtual bool Rysuj() = 0;
    /*!
     * \brief Zmazuje narysowany obiekt
     */
    void Zmarz() {apiSceny->erase_shape(apii);}
};


#endif
