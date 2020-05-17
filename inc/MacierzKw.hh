#ifndef URL_MACIERZKW_H
#define URL_MACIERZKW_H

#include "Wektor.hh"

/*****************************
***INTERPRETACJA WIERSZOWA****
******************************/
template<class TYP,int ROZMIAR>
class MacierzKw {
protected:
    Wektor<TYP,ROZMIAR> tabM[ROZMIAR];

    TYP Wyznacznik2x2(int wiersz,int kolumna) // wiersz/kolumna wykreślona
    {
        TYP M2x2[4];
        int k = 0;
        for (int i = 0; i < ROZMIAR; i++)
        {
            if (i == wiersz && i != ROZMIAR - 1) i++;
            for (int j = 0; j < ROZMIAR; j++)
                if (i != wiersz && j != kolumna)
                {
                    M2x2[k] = tabM[i][j];
                    k++;
                }
        }
        return M2x2[0]*M2x2[3]-M2x2[1]*M2x2[2];
    }

public:
    enum MetodaWyznacznik{Laplace, Gauss};

   MacierzKw()
    {
        for (int i = 0; i < ROZMIAR; ++i)
            for (int j = 0; j < ROZMIAR; ++j)
                tabM[i][j] = 0;
    }

    MacierzKw(Wektor<TYP,ROZMIAR>  *w)
    {
        for(int i=0;i<ROZMIAR;i++)
            tabM[i]=w[i];
    }


    const MacierzKw<TYP,ROZMIAR>  transpozycja() const
    {
        MacierzKw MKP;
        for(int i=0;i<ROZMIAR;i++)
            for (int j = 0; j < ROZMIAR; j++)
                MKP[j][i]=(*this)[i][j];

        return MKP;
    }


    Wektor<TYP,ROZMIAR>  operator * (const Wektor<TYP,ROZMIAR>  & W) const
    {
        Wektor<TYP,ROZMIAR> WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=(*this)[i]*W;

        return WP;
    }

    MacierzKw<TYP,ROZMIAR>  operator * ( MacierzKw<TYP,ROZMIAR>  & W) const
    {
        MacierzKw<TYP,ROZMIAR> MKP;
        for(int i=0;i<ROZMIAR;i++)
            for(int j=0;j<ROZMIAR;j++)
                MKP[i][j]=(*this)[i]*W.ZwrocKolumne(j);

        return MKP;
    }

    MacierzKw<TYP,ROZMIAR> operator + (const MacierzKw<TYP,ROZMIAR>  & W) const
    {
        MacierzKw MKP;
        for(int i=0;i<ROZMIAR;i++)
            MKP[i]=(*this)[i]+W[i];

        return MKP;
    }
    MacierzKw<TYP,ROZMIAR>  operator - (const MacierzKw<TYP,ROZMIAR>  & W) const
    {
        MacierzKw MKP;
        for(int i=0;i<ROZMIAR;i++)
            MKP[i]=(*this)[i]-W[i];

        return MKP;
    }
    MacierzKw<TYP,ROZMIAR>  operator * (double l) const
    {
        MacierzKw MKP;
        for(int i=0;i<ROZMIAR;i++)
            MKP[i]=(*this)[i]*l;

        return MKP;
    }
    MacierzKw<TYP,ROZMIAR>  operator / (double l) const
    {
        if(l==0)
        {
            std::cout<<"Dzielenie przez zero"<<std::endl;
            exit(1);
        }
        MacierzKw MKP;
        for(int i=0;i<ROZMIAR;i++)
            MKP[i]=(*this)[i]/l;

        return MKP;
    }

    TYP Wyznacznik(const MetodaWyznacznik Metoda)
    {
        TYP wynik;
        wynik=0;
        switch (Metoda)
        {
            case Laplace:
               /* for (int i = 0; i < ROZMIAR; i++)
                {
                    if (i % 2 == 1)
                        wynik = wynik - tabM[0][i] * Wyznacznik2x2(0, i);
                    else
                        wynik = wynik + tabM[0][i] * Wyznacznik2x2(0, i);
                }*/
                break;

            case Gauss:
                MacierzKw MP=tabM;
                for (int i = 0; i <ROZMIAR-1 ; ++i)
                {

                    if(MP[i][i]==0)
                    {
                        bool czyZera=true;
                        for (int k = 0; k < ROZMIAR; k++)
                        {
                            if (MP[i][k] != 0)
                            {
                                Wektor<TYP,ROZMIAR> WP = MP[i];
                                MP[i] = MP[k];
                                Wektor<TYP,ROZMIAR> _WP;
                                MP[k] = _WP-WP;
                                czyZera = false;
                                break;
                            }
                        }
                        if (czyZera)
                            return wynik;
                    }
                    for (int j = i+1; j <ROZMIAR ; ++j)
                    {
                        TYP l;
                        l = MP[j][i]/MP[i][i];
                        MP[j]=MP[j]-l*MP[i];
                    }
                }
                wynik=1;
                for (int i = 0; i <ROZMIAR ; ++i)
                {
                    wynik=wynik * MP[i][i];
                }
                break;

        }
        return wynik;
    }


    /*******************************/
    const MacierzKw<TYP,ROZMIAR>  Odwrotnosc() // z Gaussa
    {
        MacierzKw<TYP,ROZMIAR> MP, I;

        MP=*this;
        for (int i = 0; i < ROZMIAR; ++i)
            I[i][i]=1;

        std::cout<<I<<std::endl;
        if(MP.Wyznacznik(MacierzKw<TYP,ROZMIAR>::Gauss)==0)
        {
            std::cout << "Macierz nie jest odwracalna" << std::endl;
            exit (1);
        }
        else
            for (int i = 0; i <ROZMIAR-1 ; ++i)
            {
                if(MP[i][i]==0)
                {
                    for (int k = 0; k < ROZMIAR; k++)
                    {
                        if (MP[i][k] != 0)
                        {
                            Wektor<TYP,ROZMIAR> WP = MP[i];
                            Wektor<TYP,ROZMIAR> WPI = I[i];
                            MP[i] = MP[k];
                            I[i]=I[k];
                            MP[k] = WP;
                            I[k]=WPI;
                            break;
                        }
                    }

                }
                for (int j = i+1; j <ROZMIAR ; ++j)
                {
                    TYP l;
                    l = MP[j][i]/MP[i][i];
                    MP[j]=MP[j]-l*MP[i];
                    I[j]=I[j]-l*I[i];
                }
            }
        for (int i = ROZMIAR-1; i >0 ; --i)
        {
            if(MP[i][i]==0)
            {
                for (int k = 0; k < ROZMIAR; k++)
                {
                    if (MP[i][k] != 0)
                    {
                        Wektor<TYP,ROZMIAR> WP = MP[i];
                        Wektor<TYP,ROZMIAR> lp=I[i];
                        MP[i] = MP[k];
                        I[i]=I[k];
                        MP[k] = WP;
                        I[k]=lp;
                        break;
                    }
                }

            }
            for (int j =i-1; j >=0 ; --j)
            {
                TYP l;
                l = MP[j][i]/MP[i][i];
                MP[j]=MP[j]-l*MP[i];
                I[j]=I[j]-l*I[i];
            }
        }
        for(int i=0;i<ROZMIAR;i++)
        {
            I[i]=I[i]/MP[i][i];
        }
        return I;
    }

        /*********************************/
        /*
        MacierzKw MKP;
        double wyznacznik=Wyznacznik(Laplace);
        if(wyznacznik==0)
        {
            std::cout<<"Macierz nie jest odwracalna"<<std::endl;
            exit(1);
        }
        for(int i=0;i<ROZMIAR;i++)
            for(int j=0;j<ROZMIAR;j++)
            {
                if((i+j)%2==0)
                    MKP[i][j]=Wyznacznik2x2(i,j);
                else
                    MKP[i][j]=-Wyznacznik2x2(i,j);
            }
        MKP=MKP.transpozycja();
        return MKP/wyznacznik;
    }
         */
    /*******************************/
    bool operator == (const MacierzKw<TYP,ROZMIAR>  & W2) const
    {
        for(int i=0;i<ROZMIAR;i++)
            if((*this)[i]!=W2[i])
                return false;

        return true;
    }
    bool operator != (const MacierzKw<TYP,ROZMIAR>  & W2) const
    {
        return !(W2==(*this));
    }

    const Wektor<TYP,ROZMIAR>   ZwrocKolumne(int index)
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        Wektor <TYP,ROZMIAR>WP;
        for(int i=0;i<ROZMIAR;i++)
            WP[i]=tabM[i][index];

        return WP;
    }
    void ZmienKolumne(int index, Wektor<TYP,ROZMIAR>  nowa)
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        for(int i=0;i<ROZMIAR;i++)
            tabM[i][index]=nowa[i];

    }

    const Wektor<TYP,ROZMIAR>  & operator[] (int index) const
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        return tabM[index];
    }

    Wektor<TYP,ROZMIAR>  & operator[] (int index)
    {
        if (index < 0 || index >= ROZMIAR) {
            std::cerr << "poza zakresem" << std::endl;
            exit(1);
        }
        return tabM[index];
    }
};
/**************************************/

template<class TYP,int ROZMIAR>
const MacierzKw<TYP,ROZMIAR> operator * (double l1,const MacierzKw<TYP,ROZMIAR>  W2)
{
    MacierzKw<TYP,ROZMIAR>  MKP;
    for (int i = 0; i < ROZMIAR; i++)
        MKP[i] = W2[i] * l1;

    return MKP;
}



template<class TYP,int ROZMIAR>
std::ostream & operator << (std::ostream & strm,const MacierzKw<TYP,ROZMIAR>  & MK)
{
    for (int i = 0; i < ROZMIAR; ++i)
        strm << MK[i] << std::endl;

    return strm;
}

template<class TYP,int ROZMIAR>
std::istream & operator >> (std::istream & strm, MacierzKw<TYP,ROZMIAR>  & MK)
{
    for (int i = 0; i < ROZMIAR; ++i)
        strm >> MK[i];

    return strm;
}


#endif
