#ifndef SYMULACJADRONA_WEKTOR3D_HH
#define SYMULACJADRONA_WEKTOR3D_HH

#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"

using drawNS::Point3D;

/*!
 * \brief Implementacja klasy Wektor3D
 * Dziedziczy po szablonie \file Wektor.hh
 */
class Wektor3D : public Wektor<double,3>{
protected:
    /*!
     * \brief ilosc utworzonych wektorow
     */
    static uint utworzone;
    /*!
     * \brief ilosc istniejacych wektrow
     */
    static uint istniejace;
public:
    /*!
     * \brief Konstruktor bezparametryczny
     */
    Wektor3D() {istniejace++; utworzone++;}
    /*!
     * \brief Destruktor bezparametryczny
     */
    ~Wektor3D() {istniejace--;}

    /*!
     * \brief Konstruktor kopiujący
     * \param w - wektor
     */
    Wektor3D(const Wektor3D & w)   {tab[0]=w[0]; tab[1]=w[1]; tab[2]=w[2]; istniejace++; utworzone++;}
    /*!
     * \brief Konstruktor parametryczny od 3 liczb
     * \param x - wspolrzedna x
     * \param y - wspolrzedna y
     * \param z - wspolrzedna z
     */
    Wektor3D(double x, double y, double z)   {tab[0]=x; tab[1]=y; tab[2]=z; utworzone++; istniejace++;}

    /*!
     * \brief  Konstruktor parametryczny od wektora z szablonu
     * \param w - wektor (szablon)
     */
    Wektor3D(Wektor<double, 3> w) {tab[0]=w[0]; tab[1]=w[1]; tab[2]=w[2]; utworzone++; istniejace++;}
    /*!
     * \brief operator przypisania
     * \param W - wektor 3D
     * \return przypisany wektor 3D
     */
    Wektor3D & operator = (const Wektor3D  W) ;
    /*!
     * \brief Konwertuje wektor3D na Point3D
     * \return wektor jako Point3D
     */
    Point3D Wektor2Point() const;
    /*!
     * \brief Zwraca ilosc istnejacych wektorow
     * \return ilosc istnejacych wektorow
     */
    static uint ZwrocIstniejace() ;
    /*!
     * \brief Zwraca ilosc utworzonych wektorow
     * \return ilosc utworzonych wektorow
     */
    static uint ZwrocUtworzone() ;
};
/*!
 * \brief Konwertuje vector Wektorow3D na vector Point3D
 * \param P - vector Wektorow3D
 * \return vector Point3D
 */
std::vector<drawNS::Point3D> Pwek2Ppoint(const std::vector<Wektor3D> &P);



#endif
