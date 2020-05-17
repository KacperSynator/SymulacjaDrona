#include "../inc/Płaszczyzna.hh"


bool Plaszczyzna::Rysuj()
{
    if( apiSceny == nullptr )
    {
        std::cerr << "api = nullptr\n";
        return false;
    }

    apii=apiSceny->draw_surface(Wierzcholki, "blue");
    return true;
}






