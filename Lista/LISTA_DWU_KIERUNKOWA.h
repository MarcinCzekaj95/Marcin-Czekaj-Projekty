#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class node
{
    node * head;
    node * tail;
    node * next;
    node * prev;
    int data;
    static int licznik;
public:
    node();

    ~node();

    void PUSH_TO_FRONT(int number);


    void PUSH_TO_BACK(int number);


    void POP_FROM_FRONT();


    void POP_FROM_BACK();


    void SIZES();


    void Write();


    void IS_EMPTY();

    void Clear_LISTS();

};

void Lista_Dwu_Kierunkowa();
