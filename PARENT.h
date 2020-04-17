#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;
#define firstParent(A) A.firstParent
#define info(P) P->info
#define next(P) P->next
#define NIL NULL
#include "RELASI.h"
#include "CHILD.h"


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
void createListParent(Parent &p);
void insertFirstParent(Parent &p,addressParent a);
void createElementParent(addressParent &p,string judul,string penulis,string publisher,string tahun,string abstrak);
addressParent findParent(Parent p,string judul);
#endif // PARENT_H_INCLUDED
