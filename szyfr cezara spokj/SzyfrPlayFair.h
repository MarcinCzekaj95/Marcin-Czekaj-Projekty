#include <iostream>
#include <windows.h>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class SzyfrPlayFair
{
    string napis,napisPoprawny,tekst;
    bool czyMoznaSzyfrowac,czyMoznaDeszyfrowac;
    char tablica[5][5];
    int licznik,licznik2,liczbaElementow;
    char litera;
public:
    SzyfrPlayFair(string);

    ~SzyfrPlayFair();

    void Szyfruj();

    void Deszyfruj();

    void SwitchPlayFaira();

    void PodajNapis();

};
