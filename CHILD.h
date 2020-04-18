#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
using namespace std;
#define firstChild(A) A.firstChild
#define prev(P) P->prev
#include "RELASI.h"
#include "PARENT.h"


typedef struct aChild *addressChild;
struct aChild{
    string info;
    addressChild next,prev; //next menunjukan elemen yg ditunjuk di list Child
};

struct Child { //membuat list Child
    addressChild firstChild;
};

void createListChild(Child &c);
void createElementChild(addressChild &c,string w);
addressChild findChild(Child c,string keyword);
void insertLastChild(Child &c,addressChild ac);
void deleteElementRelasi(Child &p,addressChild x);
#endif // CHILD_H_INCLUDED
