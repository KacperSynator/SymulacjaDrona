#include "../inc/PoziomMorza.hh"

void PoziomMorza::Inicjalizuj(std::shared_ptr<drawNS::Draw3DAPI> api,const Wektor3D & sr)
{
    apiSceny=api;
    for (int i = sr[0]-10; i <= sr[0]+10; i+=2)
    {
        std::vector<drawNS::Point3D> VP;
        for (int j = sr[1]-10; j <= sr[1]+10; j += 2)
        {
              if(j%4==0)
                  VP.push_back(drawNS::Point3D(i, j, sr[2]+0.5));
              else
                 VP.push_back(drawNS::Point3D(i, j, sr[2]));
        }

        Wierzcholki.push_back(VP);
    }

    Rysuj();
    apiSceny->change_shape_color(apii,"blue");
    apiSceny->redraw();

}

PoziomMorza::PoziomMorza(std::shared_ptr<drawNS::Draw3DAPI> api, const Wektor3D &sr)
{
    Inicjalizuj(api,sr);
}
