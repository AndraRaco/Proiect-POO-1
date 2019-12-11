#ifndef NODUL_H_INCLUDED
#define NODUL_H_INCLUDED
#include "Liste.h"

class Lista;

class Nod
{
    int val;
    Nod* next;
public:
    friend class Lista;
    Nod();
    Nod (Nod*);
    ~Nod();
    bool has_next();
    Nod* get_next();
    void set_next (Nod* new_Nod);
    int get_val();
    void set_val (int val);
    void operator= (const Nod*);
};

#endif // NODUL_H_INCLUDED
