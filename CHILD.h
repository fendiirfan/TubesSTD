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
//IS. -
//FS. TERDEFINISI LIST CHILD
void createElementChild(addressChild &c,string w);
//IS. -
//FS. TERDEFINISI ELEMENT DENGAN INFO W
addressChild findChild(Child c,string keyword);
//IS. TERDEFINISI LIST CHILD DAN KEYWORD YANG INGIN DICARI, LIST CHILD MUNGKIN KOSONG
//FS. TERDEFINISI ADDRESCHILD JIKA KETEMU DAN NULL JIKA TIDAK KETEMU ATAU KOSONG
void insertLastChild(Child &c,addressChild ac);
//IS. TERDEFINISI LIST CHILD MUNGKIN KOSONG, DAN ADDRESSCHILD YANG MENUNJUK KE ELEMEN YANG INI DIHAPUS
//FS. ELEMEN YANG DITUNJUK OLEH ADDRESSCHILD TELAH TERHAPUS
void deleteElementChild(Child &c,addressChild x);
//IS. TERDEFINISI LIST CHILD , LIST TIDAK KOSONG, DAN ADDRESS CHILD TERDEFINISI DI CHILD_H_INCLUDED
//FS. ELEMEN YANG DITUNJUK OLEH ADDRESCHILD TELAH DIHAPUS DARI LIST

#endif // CHILD_H_INCLUDED
