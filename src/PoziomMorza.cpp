#include "../inc/PoziomMorza.hh"

void PoziomMorza::Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
    apiSceny=api;
    for (int i = -10; i <= 10; i+=2)
    {
        std::vector<drawNS::Point3D> VP;
        for (int j = -10; j <= 10; j += 2)
        {
              if(j%4==0)
                  VP.push_back(drawNS::Point3D(i, j, 9.5));
              else
                 VP.push_back(drawNS::Point3D(i, j, 9));
        }

        Wierzcholki.push_back(VP);
    }

    Rysuj();
    apiSceny->change_shape_color(apii,"blue");
    apiSceny->redraw();

}
