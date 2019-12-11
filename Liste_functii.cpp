#include <iostream>
#include "Nodul.h"
#include "Liste.h"

using namespace std;

Lista::Lista()
{
    this->first = NULL;
    this->last = NULL;
}

Lista::Lista (const Lista *L)
{
    Nod *p = L->first;
    while (p != NULL)
    {
        this->add_sfarsit (p->val);
        p = p->next;
    }
}

Lista::~Lista()
{
    //cout << "sterge lista" << endl;
    if (first != NULL)
    {
        Nod *p = this->first;
        while (p != NULL)
        {
            Nod *aux = p;
            p = p->get_next();
            delete aux;
        }
    }
}

void Lista::add_inceput (int data)
{
    if (first == NULL)
    {
        first = new Nod;
        first->set_val (data);
        last = first;
    }
    else
    {
        Nod *p = new Nod;
        p->val = data;
        p->next = first;
        first = p;
    }
}

void Lista::add_sfarsit (int data)
{
    Nod *p = new Nod;
    p->val = data;
    p->next = NULL;
    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}

void Lista::add (int data)
{
    if (first == NULL)
    {
        this->add_inceput (data);
        return;
    }
    if (first->val >= data)
    {
        this->add_inceput (data);
        return;
    }
    if (last->val <= data)
    {
        this->add_sfarsit (data);
        return;
    }
    {
        Nod *q, *t;
        q = first;
        while (q != NULL && q->val < data)
        {
            t = q;
            q = q->next;
        }
        q = t;
        Nod *node = new Nod;
        node->set_val (data);
        node->next = q->next;
        q->next = node;
        if (node->get_next() == NULL)
            last = node;
    }
}

void Lista::print (ostream& out)
{
    Nod *p;
    p = first;
    while (p != NULL)
    {
        out << p->get_val() << " ";
        p = p->get_next();
    }
    out << endl;
}

int Lista::cautare (int x)
{
    Nod *p;
    p = first;
    while (p != NULL)
    {
        if (x == p->get_val() )
            return 1;
        p = p->get_next();
    }
    return 0;
}

void Lista::operator= (const Lista* L)
{
    this->first = L->first;
    this->last = L->last;
}

Lista* Lista::copiere_elemente()
{
    Lista *C = new Lista;
    Nod *p = this->first;
    while (p != NULL)
    {
        int data;
        data = p->get_val();
        C->add (data);
        p = p->get_next();
    }
    return C;
}

Nod* Lista::get_first()
{
    return first;
}

Nod* Lista::get_last()
{
    return last;
}
