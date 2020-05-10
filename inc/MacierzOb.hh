#ifndef SYMULACJADRONA_MACIERZOB_H
#define SYMULACJADRONA_MACIERZOB_H

#include "MacierzKw.hh"

#define PI 3.14159265

/*!
 * \brief Implementacja macierzy obrotu
 * Dziedziczy po \file MacierzKw.hh
 */

class MacierzOb : public MacierzKw<double,3>
{
protected:
    /*!
     * kat w radianach
     */
    double kat;
public:
    /*!
     * \brief enum z osiami obrotu
     */
    enum OsObrotu{OX,OY,OZ};
    /*!
     * \brief Konstruktor bezparametryczny
     * tworzy macierz jednostkowa
     */
    MacierzOb();


    /*!
     * \brief Konstruktor
     * tworzy okreslona wedlug rotacji macierz obrotu
     * \param os - os obrotu (enum)
     * \param li - kat w stopniach
     */
     MacierzOb(OsObrotu os,const double & li);

     /*!\brief Ustawia kat macierzy obrotu
      * \param l - kat w stopniach
      */
     void Set_Kat(const double & l) {kat=l*PI/180;}

     /*!
      * \brief Zwraca kat w radianach
      * \return
      */
     double Get_Kat() const {return kat;}

    /*!
     * \brief Sprawdzenie czy wyznacznik jest równy 1
     * \return true/false
     */
    bool CzyPoprawna() const ;
};


#endif
