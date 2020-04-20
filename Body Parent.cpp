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
        next(a)=NULL;
    }
    else{
        next(a)=firstParent(p);
        firstParent(p)=a;
    }
}

addressParent findParent(Parent p,string judul){
    if(firstParent(p)==NULL){
        return NULL;
    }
    else{
        addressParent a = firstParent(p);
        while(a!=NULL){
            if(info(a).judul==judul){
                return a;
            }
            a=next(a);
        }
        return NULL;
    }
}
void deleteElementParent(Parent &p,addressParent x){
    cout<<"cek1"<<endl;
    if(next(firstParent(p))==NULL){
            cout<<"cek2"<<endl;
        firstParent(p)=NULL;
    }
    else if(x==firstParent(p)){
        cout<<"ceksu"<<endl;
        firstParent(p)=next(x);
        next(x)=NULL;
    }
    else if(next(x)==NULL){
        cout<<"cek3"<<endl;
        addressParent s = firstParent(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=NULL;
    }
    else{
        cout<<"cek4"<<endl;
        addressParent s = firstParent(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=next(x);
        next(x)=NULL;
    }
    delete x;
}


