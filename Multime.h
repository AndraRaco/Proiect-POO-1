#ifndef MULTIME_H_INCLUDED
#define MULTIME_H_INCLUDED
#include "Nodul.h"
#include "Liste.h"
#include <iostream>

using namespace std;

class Lista;

class Multime
{
    Lista *List;
public:
    friend class Lista;
    friend class Nod;
    Multime();
    Multime (Lista*);
    Multime (const Multime*) ;
    ~Multime();
    void eliminare_dublicate();
    friend istream& operator>> (istream&, Multime*);
    friend ostream& operator<< (ostream&, const Multime*);
    void operator= (const Multime *A);
    Multime* operator+ (const Multime*);
    Multime* operator* (const Multime*);
    Multime* operator- (const Multime*);
    Lista* get_List();
};


#endif // MULTIME_H_INCLUDED
