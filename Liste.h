#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED
#include "Nodul.h"
#include "Multime.h"
#include <iostream>

using namespace std;

class Nod;

class Lista
{
    Nod *first;
    Nod *last;
public:
    friend class Multime;
    Lista();
    ~Lista();
    Lista (const Lista*);
    void add (int);
    void add_inceput (int);
    void add_sfarsit (int);
    void print (ostream&);
    int cautare (int);
    void operator= (const Lista*);
    Lista* copiere_elemente();
    Nod* get_first();
    Nod* get_last();
    void ordonare();
};

#endif // LISTE_H_INCLUDED
