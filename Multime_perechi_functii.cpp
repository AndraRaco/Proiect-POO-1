#include <iostream>
#include "Nodul.h"
#include "Liste.h"
#include "Multime.h"
#include "Pereche.h"
#include "Multime_perechi.h"

using namespace std;

Multime_perechi::Multime_perechi()
{
    this->first = NULL;
    this->last = NULL;
}

Multime_perechi::Multime_perechi (const Multime_perechi *M)
{
    Pereche *p = M->first;
    while (p != NULL)
    {
        this->add (p->x, p->y);
        p = p->next;
    }
}

Multime_perechi::~Multime_perechi()
{
    //cout << "sterge multime perechi" << endl;
    if (first != NULL)
    {
        Pereche *p = this->first;
        while (p != NULL)
        {
            Pereche *aux = p;
            p = p->get_next();
            delete aux;
        }
    }
}

void Multime_perechi::add_inceput (int valx, int valy)
{
    if (first == NULL)
    {
        first = new Pereche;
        first->set_pereche (valx, valy);
        last = first;
    }
    else
    {
        Pereche *p = new Pereche;
        p->x = valx;
        p->y = valy;
        p->next = first;
        first = p;
    }
}

void Multime_perechi::add_sfarsit (int valx, int valy)
{
    Pereche *p = new Pereche;
    p->x = valx;
    p->y = valy;
    p->next = NULL;
    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}

void Multime_perechi::add (int valx, int valy)
{
    if (first == NULL)
    {
        this->add_inceput (valx, valy);
        return;
    }
    if (first->x >= valx && first->y >= valy)
    {
        this->add_inceput (valx, valy);
        return;
    }
    if (last->x <= valx && last->y <= valy )
    {
        this->add_sfarsit (valx, valy);
        return;
    }
    Pereche *q, *t;
    q = first;
    while (q != NULL && q->x < valx)
    {
        t = q;
        q = q->next;
    }
    while (q != NULL && q->x == valx && q->y <= valy)
    {
        t = q;
        q = q->next;
    }
    q = t;
    Pereche *node = new Pereche;
    node->set_pereche (valx, valy);
    node->next = q->next;
    q->next = node;
    if (node->get_next() == NULL)
        last = node;
}

istream& operator>> (istream& in, Multime_perechi* M)
{
    int n, i;
    cout << "Numarul de perechi " << endl;
    in >> n;
    cout << "Perechile " << endl;
    for (i = 1; i <= n; i++)
    {
        int x, y;
        in >> x >> y;
        M->add (x, y);
    }
    return in;
}

ostream& operator<< (ostream& out, const Multime_perechi* M)
{
    Pereche *p;
    p = M->first;
    while (p != NULL)
    {
        out << p->get_valx() << " " << p->get_valy() << endl;
        p = p->get_next();
    }
    out << endl;
    return out;
}

int Multime_perechi::cautare (int valx, int valy)
{
    Pereche *p;
    p = this->first;
    while (p != NULL)
    {
        if ((p->get_valx() == valx && p->get_valy() == valy) || (p->get_valx() == valy && p->get_valy() == valx) )
            return 1;
        p = p->get_next();
    }
    return 0;
}

Multime_perechi* Multime_perechi::Produs_cartezian (Multime *A, Multime *B)
{
    Nod *a, *b;
    a = A->get_List()->get_first();
    while (a != NULL)
    {
        b = B->get_List()->get_first();
        while (b != NULL)
        {
            int valx, valy;
            valx = a->get_val();
            valy = b->get_val();
            /*if (this->cautare (valx, valy) == 0)
                add (valx, valy);  */
            if (this->cautare (valx, valy) == 0)
            {
                if (valx < valy)
                    add (valx, valy);
                else
                    add (valy, valx);
            }
            b = b->get_next();
        }
        a = a->get_next();
    }
    return this;
}
