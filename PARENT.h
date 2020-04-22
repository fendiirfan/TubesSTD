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
//IS. -
//FS. TERDEFINISI LIST
void insertFirstParent(Parent &p,addressParent a);
//IS. TERDEFINISI LIST MUNGKIN KOSONG DAN ADDRES PARENT_H_INCLUDED
//FS. ADDRES PARENT DIMASUKAN DIAWAL LIST
void createElementParent(addressParent &p,string judul,string penulis,string publisher,string tahun,string abstrak);
//IS. -
//FS. TERDEFINISI ELEMENT DENGAN INFO BERISI JUDUL...
addressParent findParent(Parent p,string judul);
//IS. TERDEFINISI LIST PARENT MUNGKIN KOSONG DAN SEBUAT JUDUL
//FS. TERDEFINISI ADDRES PARENT YANG BERADA DI LIST PARENT DENGAN STRING JUDUL DAN JIKA TIDAK DITEMUKAN ATAU KOOSNG RETURN NULL
void deleteElementParent(Parent &p,addressParent x);
//IS. TERDEFINISI LIST PARENT TIDAK KOOSNG DAN ADDRES PARENT YANG INGIN DIHAPUS
//FS. ELEMEN ADDRESPARENT TERHAPUS DI LIST
void tampilkanSemuaJudulartikel(Parent p,addressParent Ap);
#endif // PARENT_H_INCLUDED


