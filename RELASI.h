#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
using namespace std;
#define firstRelasi(A) A->firstRelasi
#define nextC(P) P->nextC
#define nextP(P) P->nextP

typedef struct aChild *addressRelasi;
struct aRelasi{
    addressChild nextC; //nextC menunjukan elemen yg ditunjuk di list Child
    addressParent nextP;//nextP menunjukan elemen yg ditunjuk di list Parent
    addressRelasi next;//next menunjukan elemen yg ditunjuk di list Relasi
};

struct Relasi { //membuat list Child
    addressRelasi firstRelasi;
};

void createList(Relasi &L);
void insertFirst(Relasi &L, addressRelasi P);
void insertLast(Relasi &L, addressRelasi P);
void insertAfter(addressRelasi Prec, addressRelasi P);
void deleteFirst(Relasi &L, addressRelasi &P);
void deleteLast(Relasi &L, addressRelasi &P);
void deleteAfter(addressRelasi Prec, addressRelasi &P);
addressRelasi alokasi( addressParent P, addressChild C);
void dealokasi(addressRelasi &P);
addressRelasi findElm(Relasi L, addressParent P, addressChild C);
void printInfo(Relasi L);

#endif // RELASI_H_INCLUDED
