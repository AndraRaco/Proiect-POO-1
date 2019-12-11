#include <iostream>
#include "Nodul.h"
#include "Liste.h"
#include "Multime.h"
#include "Pereche.h"

using namespace std;

Pereche::Pereche()
{
    next = NULL;
}

Pereche::Pereche (const Pereche *P)
{
    next = P->next;
    x = P->x;
    y = P->y;
}

Pereche::~Pereche()
{
    //cout << "sterge pereche" << endl;
    if (this->next != NULL)
        delete this->next;
}

istream& operator>> (istream& in, Pereche* p)
{
    in >> p->x;
    in >> p->y;
    return in;
}

ostream& operator<< (ostream& out, const Pereche* p)
{
    out << p->x << " " << p->y;
    return out;
}

Pereche* Pereche::get_next()
{
    return this->next;
}

void Pereche::set_next (Pereche *new_Pereche)
{
    if (new_Pereche == NULL)
        next = NULL;
    else
        next = new_Pereche;
}

int Pereche::get_valx()
{
    return x;
}

int Pereche::get_valy()
{
    return y;
}

void Pereche::set_pereche (int valx, int valy)
{
    x = valx;
    y = valy;
}

void Pereche::operator= (const Pereche *per)
{
    this->next = per->next;
    this->x = per->x;
    this->y = per->y;
}
