#include <iostream>
#include "Nodul.h"
#include "Liste.h"
#include "Multime.h"
#include "Pereche.h"
#include "Multime_perechi.h"

using namespace std;

///Tema 8
///Multimi finite de numere intregi reprezentate prin liste inlantuite

int main()
{
    Lista *L1 = new Lista;
    Multime *M1 = new Multime (L1);
    Lista *L2 = new Lista;
    Multime *M2 = new Multime (L2);
    cin >> M1 >> M2;
    cout << endl;
    cout << "Prima multime: " << M1 << endl;
    cout << "A 2-a multime: " << M2 << endl;
    //-------------------------------------
    Multime *reuniune;
    reuniune = *M1 + M2;
    cout << "reuniune " << reuniune;
    Multime *intersectie;
    intersectie = *M1 * M2;
    cout << "intersectie " << intersectie;
    Multime *diferenta;
    diferenta = *M1 - M2;
    cout << "diferenta " << diferenta << endl;
    delete intersectie;
    delete diferenta;
    delete reuniune;
    //---------------------------------------
    Multime_perechi *M = new Multime_perechi;
    cin >> M;
    cout << "Multime perechi:" << endl << M;
    delete M;
    Multime_perechi *PC = new Multime_perechi;
    PC = PC->Produs_cartezian (M1, M2);
    cout << "Produs cartezian: " << endl << PC;
    delete PC;
    delete M1;
    delete M2;
    return 0;
}
