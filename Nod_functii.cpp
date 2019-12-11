#include <iostream>
#include "Nodul.h"

using namespace std;

Nod::Nod()
{
    next = NULL;
}

Nod::Nod (Nod *node)
{
    next = NULL;
    val = node->val;
}

Nod::~Nod()
{
    //cout << "stergere nod" << endl;
    if (this->next != NULL)
        delete this->next;
}

bool Nod::has_next()
{
    if (next != NULL)
        return 1;
    return 0;
}

Nod* Nod::get_next()
{
    return next;
}

void Nod::set_next (Nod* new_Nod)
{
    if (new_Nod == NULL)
        next = NULL;
    else
        next = new_Nod;
}

void Nod::set_val (int x)
{
    val = x;
}

int Nod::get_val()
{
    return val;
}

void Nod::operator= (const Nod *node)
{
    this->next = node->next;
    this->val = node->val;
}
