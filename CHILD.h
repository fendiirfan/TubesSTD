#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;
#define firstChild(A) A->firstChild
#define prev(P) P->prev
#include "RELASI.h"
#include "PARENT.h"

typedef string infoChild;
typedef struct aChild *addressChild;
struct aChild{
    infoChild info;
    addressChild next,prev; //next menunjukan elemen yg ditunjuk di list Child
};

struct Child { //membuat list Child
    addressChild firstChild;
};
#endif // CHILD_H_INCLUDED
