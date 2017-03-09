#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

using namespace std;




class SzyfVinegre
{
    fstream plik;
    string Jawny;
    string Klucz;
    bool CzyMoznaSzyfrowac;
    bool CzyMoznaDeszyfrowac;
public:
    SzyfVinegre(string,string);

    ~SzyfVinegre();

    void Szyfruj();

    void Deszyfruj();

    void PodajNapis();

    void PodajKlucz();

    void SwitchVinegre();
};
