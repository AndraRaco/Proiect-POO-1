#include <iostream>
#include "Nodul.h"
#include "Liste.h"
#include "Multime.h"

using namespace std;

Multime::Multime()
{
    List = NULL;
}

Multime::Multime (Lista *L)
{
    List = L;
}

Multime::Multime (const Multime *M)
{
    List = M->List->copiere_elemente();
}

Multime::~Multime()
{
    //cout << "sterge multimea" << endl;
    if (List != NULL)
        delete List;
}

void Multime::eliminare_dublicate()
{
    Lista *L = new Lista; //lista intermediara in care voi pune val o singura data
    Nod *p;
    p = this->List->first;
    while (p != NULL)
    {
        int data = p->get_val();
        if (L->cautare (data) == 0)
            L->add (data);
        p = p->get_next();
    }
    delete this->List;
    this->List = L;
}

ostream& operator<< (ostream &out, const Multime* M)
{
    M->List->print (out);
    return out;
}

istream& operator>> (istream& in, Multime *M)
{
    cout << "Cate elemente are multimea:";
    int n;
    in >> n;
    cout << "elem. mult:";
    int data;
    for (int i = 1; i <= n; i++)
    {
        in >> data;
        M->List->add (data);
    }
    M->eliminare_dublicate();
    return in;
}

void Multime::operator= (const Multime *M)
{
    this->List = M->List;
}

Multime* Multime::operator+ (const Multime* A)
{
    Lista *LC = this->List->copiere_elemente();
    Multime *C = new Multime (LC);
    Nod *p;
    p = A->List->first;
    while (p != NULL)
    {
        C->List->add (p->get_val() );
        p = p->get_next();
    }
    C->eliminare_dublicate();
    return C;
}

Multime* Multime::operator- (const Multime *A)
{
    Lista *LC = new Lista;
    Multime *C = new Multime (LC);
    Nod *p = this->List->first;
    while (p != NULL)
    {
        int data = p->get_val();
        if (A->List->cautare (data) == 0)
            C->List->add (data);
        p = p->get_next();
    }
    return C;
}

Multime* Multime::operator* (const Multime *A)
{
    Lista *LC = new Lista;
    Multime *C = new Multime (LC);
    Nod *p = this->List->first;
    while (p != NULL)
    {
        int data = p->get_val();
        if (A->List->cautare (data) == 1)
            C->List->add (data);
        p = p->get_next();
    }
    return C;
}

Lista* Multime::get_List()
{
    return List;
}
