#ifndef PERECHE_H_INCLUDED
#define PERECHE_H_INCLUDED
#include <iostream>
#include "Multime_perechi.h"

using namespace std;

class Pereche
{
    int x, y;
    Pereche *next;
public:
    friend class Multime_perechi;
    Pereche();
    Pereche (const Pereche*);
    ~Pereche();
    friend istream& operator>> (istream&, Pereche*);
    friend ostream& operator<< (ostream&, const Pereche*);
    Pereche* get_next();
    void set_next (Pereche* new_Pereche);
    int get_valx();
    int get_valy();
    void set_pereche (int, int);
    void operator= (const Pereche*);
};

#endif // PERECHE_H_INCLUDED
