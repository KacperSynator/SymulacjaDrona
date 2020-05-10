#ifndef WEKTOR_H
#define WEKTOR_H

#include <iostream>
#include <math.h>


#define EPSILON 0.000000000000000000001

template<class TYP,int ROZMIAR>
class Wektor {
protected:

    TYP tab[ROZMIAR];

public:
    Wektor()
    {
        for(int i=0;i<ROZMIAR;i++)
            tab[i]=0;
    }

    Wektor(TYP * tab1)
    {
        for(int i=0;i<ROZMIAR;i++)
            tab[i]=tab1[i];
    }



    Wektor<TYP,ROZMIAR> operator + (const Wektor<TYP,ROZMIAR> & W2) const
    {
        Wektor<TYP,ROZMIAR> WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=this->tab[i]+W2.tab[i];

        return WP;
    }


    Wektor<TYP,ROZMIAR>  operator - (const Wektor<TYP,ROZMIAR> & W2) const
    {
        Wektor<TYP,ROZMIAR> WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=this->tab[i]-W2.tab[i];

        return WP;
    }


    TYP operator * (const Wektor<TYP,ROZMIAR> & W2) const // SKALARNY
    {
        TYP wynik;
        wynik=0;
        for(int i=0;i<ROZMIAR;i++)

            wynik  = wynik + (*this)[i] * W2[i];

        return wynik;
    }


    Wektor<TYP,ROZMIAR>  operator * (TYP li) const
    {
        Wektor<TYP,ROZMIAR> WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=this->tab[i]*li;

        return WP;
    }

    Wektor<TYP,ROZMIAR>  operator / (TYP li) const
    {
        if(li==0)
        {
            std::cout<<"Dzielenie przez zero"<<std::endl;
            exit(1);
        }
        Wektor<TYP,ROZMIAR> WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=this->tab[i]/li;

        return WP;
    }



    bool operator == (const Wektor<TYP,ROZMIAR> & W2) const
    {
        for(int i=0;i<ROZMIAR;i++)
            if(abs((*this)[i]-W2[i]) >= EPSILON) {
                return false;
            }

        return true;
    }

    bool operator != (const Wektor<TYP,ROZMIAR> & W2) const
    {
        return !((*this)==W2);
    }

    double dlugosc() const
    {
        double wynik;
        wynik=*this * *this;
        return sqrt(wynik);
    }

    const TYP & operator[] (int index) const
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        return tab[index];
    }

    TYP & operator[] (int index)
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        return tab[index];
    }


};
/**************************************/


template<class TYP,int ROZMIAR>
std::ostream & operator <<(std::ostream & strm, const Wektor<TYP,ROZMIAR> & W)
{
    strm<<'(';
    int i;
    for (i = 0; i < ROZMIAR-1; ++i)
        strm<<W[i]<<',';

    strm<<W[i]<<')';
    return strm;
}



template<class TYP,int ROZMIAR>
std::istream & operator >>(std::istream & strm, Wektor<TYP,ROZMIAR> & W)
{

    for (int i = 0; i < ROZMIAR; i++)
        strm >> W[i];

    return strm;
}



template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (TYP l1, Wektor<TYP,ROZMIAR> W2)
{
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=l1*W2[i];

    return WP;
}

#endif
