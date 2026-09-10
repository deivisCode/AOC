#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

struct rotacion {
    char dir;
    int clicks;
};

int main() {

    std::filesystem::path ruta("../input.txt");
    std::fstream fstream;
    std::string texto;
    rotacion rot;
    signed int novo = 50;
    signed int pases = 0;
    signed int d_0;

    fstream.open(ruta, std::ios::in);
    if (!fstream.is_open())
    { std::print("Non se abriu"); }

    while (std::getline(fstream, texto))
    {
        rot.dir = texto[0];
        rot.clicks = std::stoi(std::addressof(texto[1]));

        if ( rot.dir == 'L' )
        {
            d_0 =  (novo != 0) * novo + (novo == 0) * 100;
            std::print("N: {}, d_0: {}, pases: {}\n", novo, d_0, pases);
            novo = (novo + (100 - (rot.clicks % 100))) % 100;
            if (rot.clicks >= d_0) {
                pases = pases + 1 + ((rot.clicks - d_0) / 100);
            }
        }
        else if ( rot.dir == 'R')
        {
            d_0 = (100 - novo);
            std::print("N: {}, d_0: {}, pases: {}\n", novo, d_0, pases);
            novo = (novo + rot.clicks) % 100;
            if (rot.clicks >= d_0) {
                pases = pases + 1 + ((rot.clicks - d_0) / 100);
            }
        }
    }

    fstream.close();

    // :FACER: EXECÚTASE BEN ÁS VECES, SOAMENTE!!
    std::print("RESULTADO: {}", pases);

    return 0;

}
