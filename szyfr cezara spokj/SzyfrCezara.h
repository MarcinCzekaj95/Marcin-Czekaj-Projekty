#include <iostream>
#include <windows.h>
#include <string>

using namespace std;


class SzyfrCezara
{
    long long ile;
    string napis;
    bool CzyMoznaDeszyfrowac;
public:

    SzyfrCezara(string);

    ~SzyfrCezara();

    void Cezar();
    void DeszyfracjaCezara();
    void napisz();

    void SwitchCezara();
};
