#ifndef MULTIME_PERECHI_H_INCLUDED
#define MULTIME_PERECHI_H_INCLUDED
#include <iostream>
#include "Nodul.h"
#include "Liste.h"
#include "Multime.h"
#include "Pereche.h"

using namespace std;

class Pereche;

class Multime_perechi
{
    Pereche *first, *last;
public:
    Multime_perechi();
    Multime_perechi (const Multime_perechi*);
    ~Multime_perechi();
    void add (int, int);
    void add_inceput (int, int);
    void add_sfarsit (int, int);
    friend istream& operator>> (istream&, Multime_perechi*);
    friend ostream& operator<< (ostream&, const Multime_perechi*);
    Multime_perechi* Produs_cartezian (Multime *A, Multime *B);
    int cautare (int, int);
};

#endif // MULTIME_PERECHI_H_INCLUDED
