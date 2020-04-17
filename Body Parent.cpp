#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"
void createListParent(Parent &p){
    firstParent(p)=NULL;
}
void createElementParent(addressParent &p,string judul,string penulis,string publisher,string tahun,string abstrak){
    p = new aParent;
    next(p)=NULL;
    info(p).judul=judul;
    info(p).penulis=penulis;
    info(p).publisher=publisher;
    info(p).tahun=tahun;
    info(p).abstrak=abstrak;
}
void insertFirstParent(Parent &p,addressParent a){
    if(firstParent(p)==NULL){
        firstParent(p)=a;
    }
    else{
        next(a)=firstParent(p);
        firstParent(p)=a;
    }
}

addressParent findParent(Parent p,string judul){
    addressParent a = firstParent(p);
    while(a!=NULL){
        if(info(a).judul==judul){
            return a;
        }
        a=next(a);
    }
    return NULL;
}

