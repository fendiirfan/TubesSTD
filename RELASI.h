#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
using namespace std;
#define firstRelasi(A) A.firstRelasi
#define nextC(P) P->nextC
#define nextP(P) P->nextP
#define prev(P) P->prev
#include "PARENT.h"
#include "CHILD.h"
#include <stdlib.h>

typedef struct aRelasi *addressRelasi;
struct aRelasi{
    addressChild nextC; //nextC menunjukan elemen yg ditunjuk di list Child
    addressParent nextP;//nextP menunjukan elemen yg ditunjuk di list Parent
    addressRelasi next,prev;//next atau prev menunjukan elemen yg ditunjuk di list Relasi
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
void deleteElementRelasi(Relasi &r,addressRelasi x);
//IS. TERDEFINISI LIST RELASI TIDAK KOSONG DAN ADDRESPARENT
//FS. ADDRES DI DALAM LIST YG DITUNJUK OLEH ADDRESRELASI TELAH DI HAPUS DALAM LIST
void pembersihanChild(Child &C,addressChild c,Relasi r);
//IS.
//FS.
void HapusDaftarArtikel(Relasi &r, Parent &p, Child &c, addressChild Ac, addressRelasi Ar, addressParent Ap);
void HapusDaftarKeyword(Relasi &r, Parent &p, Child &c, addressChild Ac, addressRelasi Ar, addressParent Ap);
void tampilkanJudulArtikelBesertaKeywordnya(Relasi r,addressRelasi Ar);
void TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTerbanyak(Relasi r,Child c,addressRelasi Ar,addressChild Ac);
void TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTersedikit(Relasi r,Child c,addressRelasi Ar,addressChild Ac);
void CariArtikelberdasarkanKeyword(Relasi r,Child c,addressRelasi Ar);
void TampilknanSemuaKeyword(Child c,addressChild Ac);
#endif // RELASI_H_INCLUDED
