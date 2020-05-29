#ifndef SYMULACJADRONA_PRZESZKODA_INTERFACE_HH
#define SYMULACJADRONA_PRZESZKODA_INTERFACE_HH

#include "Dron_interface.hh"
#include <vector>
#include <memory>

/*!
 * \brief Implementacja abstrakcujnej klasy przeszkoda
 */
class Przeszkoda_interface {
protected:
/*!
 * kontener zawierajacy wszystkie przeszkody
 */
std::vector<std::shared_ptr<Przeszkoda_interface>> kolekcja_przeskod;
static uint utworzone;
static uint istniejace;
public:
    /*!
     * \brief Sprawdzenie czy doszło do kolizji
     * \param wskaznik na interfejs drona
     * \return true jesli kolizja, przeciwnym przypadku false
     */
    virtual bool CzyKolizja(std::shared_ptr<DronInterface>)=0;

};


#endif
