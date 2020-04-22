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
//IS. -
//FS. TERDEFINISI LIST
void insertLastRelasi(Relasi &r,addressRelasi a);
//IS. TERDEFINISI LIST RELASI MUNGKIN KOSONG DAN ADDRERELASI
//FS. ELEMENT ADDRESRELASI TELAH DIMASUKAN DIAKHIR LIST
void printSemuaParentBesertaKeyword(Parent p);
//IS.
//FS.
void createElementRelasi(addressRelasi &r);
//IS. -
//FS. tERDEFINISI ELEMENT
void connect(addressRelasi &ar,addressParent p,addressChild c);
//IS. TERDEFINISI ADDRESS RELASI TIDAK KOSONG DAN addressChild DAN addressParent
//FS. MENGHUBUNGKAN ANATARA ADDRESS CHILD DAN PARENT DENGAN MENGGUNAKAN ADDRES RELASI
addressRelasi findRelasi(Relasi r,addressChild c,addressParent p);
//IS.
//FS.
void deleteElementRelasi(Relasi &r,addressRelasi x);
//IS. TERDEFINISI LIST RELASI TIDAK KOSONG DAN ADDRESPARENT
//FS. ADDRES DI DALAM LIST YG DITUNJUK OLEH ADDRESRELASI TELAH DI HAPUS DALAM LIST
void pembersihanChild(Child &C,addressChild c,Relasi r);
//IS.
//FS.

#endif // RELASI_H_INCLUDED
