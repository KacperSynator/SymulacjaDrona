#ifndef SYMULACJADRONA_PRZESZKODA_INTERFACE_HH
#define SYMULACJADRONA_PRZESZKODA_INTERFACE_HH

#include "Dron_interface.hh"
#include <vector>
#include <memory>

class DronInterface;

/*!
 * \brief Implementacja abstrakcujnej klasy przeszkoda
 */
class Przeszkoda_interface {

public:
    /*!
     * \brief Sprawdzenie czy doszło do kolizji
     * \param wskaznik na interfejs drona
     * \return true jesli kolizja, przeciwnym przypadku false
     */
    virtual bool CzyKolizja(DronInterface*)=0;

};



#endif
