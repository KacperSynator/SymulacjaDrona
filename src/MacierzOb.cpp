#include "../inc/MacierzOb.hh"


bool MacierzOb::CzyPoprawna() const
{
    MacierzOb MP=(*this);
    return abs(MP.Wyznacznik(Gauss) - 1) < EPSILON;
}

MacierzOb::MacierzOb(MacierzOb::OsObrotu os ,double  li)
{
    kat=li*PI/180;
    switch (os)
    {
        case OX:
            tabM[0][0]=1; tabM[0][1]=0;         tabM[0][2]=0;
            tabM[1][0]=0; tabM[1][1]=cos(kat);  tabM[1][2]=-sin(kat);
            tabM[2][0]=0; tabM[2][1]=sin(kat);  tabM[2][2]=cos(kat);

            break;

        case OY:
            tabM[0][0]=cos(kat); tabM[0][1]=0;  tabM[0][2]=-sin(kat);
            tabM[1][0]=0;        tabM[1][1]=1;  tabM[1][2]=0;
            tabM[2][0]=sin(kat); tabM[2][1]=0;  tabM[2][2]=cos(kat);

            break;

        case OZ:
            tabM[0][0]=cos(kat); tabM[0][1]=-sin(kat); tabM[0][2]=0;
            tabM[1][0]=sin(kat); tabM[1][1]=cos(kat);  tabM[1][2]=0;
            tabM[2][0]=0;        tabM[2][1]=0;         tabM[2][2]=1;
            break;

    }
}

MacierzOb::MacierzOb()
{
    kat=0;
    for (int i = 0; i < 3 ; ++i)
        for (int j = 0; j < 3; ++j)
            if(i==j)
                tabM[i][j]=1;
            else
                tabM[i][j]=0;

}

MacierzOb::MacierzOb(MacierzKw<double, 3>  M)
{
    MacierzOb tmp;
    for(int i=0;i<3;i++)
        tmp[i]=M[i];
    //if(tmp.CzyPoprawna())
        (*this)=tmp;
  //  else
     //   std::cerr<<"To nie jest macierz obrotu\n";
}




