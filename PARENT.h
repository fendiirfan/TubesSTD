#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;
#define firstParent(A) A->firstParent
#define info(P) P->info
#define next(P) P->next
#define NIL NULL

struct infoParent{
    string judul, penulis, publisher, tahun, abstrak;
};
typedef struct aParent *addressParent;
struct aParent{
    infoParent info;
    addressParent next; //next menunjukan elemen yg ditunjuk di list Parent
};

struct Parent { //membuat list parent
    addressParent firstParent;
};
void tambahartikel(Parent &P,string judul, penulis, publisher, tahun, abstrak); //procedure menambah
#endif // PARENT_H_INCLUDED
