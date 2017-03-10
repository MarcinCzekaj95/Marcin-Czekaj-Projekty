#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;


class SzyfrCezara
{
    fstream plik;
    long long ile;
    string napis;
    bool CzyMoznaDeszyfrowac;
    bool CzyMoznaSzyfrowac;
public:

    SzyfrCezara(string);

    ~SzyfrCezara();

    void Cezar();
    void DeszyfracjaCezara();
    void napisz();

    void SwitchCezara();
};
