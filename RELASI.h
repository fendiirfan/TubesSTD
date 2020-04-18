#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
using namespace std;
#define firstRelasi(A) A.firstRelasi
#define nextC(P) P->nextC
#define nextP(P) P->nextP
#include "PARENT.h"
#include "CHILD.h"

typedef struct aRelasi *addressRelasi;
struct aRelasi{
    addressChild nextC; //nextC menunjukan elemen yg ditunjuk di list Child
    addressParent nextP;//nextP menunjukan elemen yg ditunjuk di list Parent
    addressRelasi next;//next menunjukan elemen yg ditunjuk di list Relasi
};

struct Relasi { //membuat list Child
    addressRelasi firstRelasi;
};

void createListRelasi(Relasi &r);
void insertLastRelasi(Relasi &r,addressRelasi a);
void printSemuaParentBesertaKeyword(Parent p);
void createElementRelasi(addressRelasi &r);
void connect(addressRelasi &ar,addressParent &p,addressChild &c);
addressRelasi findRelasi(Relasi r,addressChild c,addressParent p);
void deleteElementRelasi(Relasi &p,addressRelasi x);

#endif // RELASI_H_INCLUDED
