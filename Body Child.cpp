#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"

void createListChild(Child &c){
    firstChild(c)=NULL;
}
void createElementChild(addressChild &c,string w){
    c = new aChild;
    next(c)=NULL;
    prev(c)=NULL;
    info(c)=w;
}
addressChild findChild(Child c,string keyword){
    if(firstChild(c)==NULL){
        return NULL;
    }
    else{
        addressChild a = firstChild(c);
        while(a!=NULL){
            if(info(a)==keyword){
                return a;
            }
            a=next(a);
        }
        return NULL;
    }
}
void insertLastChild(Child &c,addressChild ac){
    if(firstChild(c)==NULL){
        firstChild(c)=ac;
        prev(firstChild(c))=NULL;
    }
    else{
        addressChild a = firstChild(c);
        while(next(a)!=NULL){
            a=next(a);
        }
        next(a)=ac;
        prev(ac)=a;
    }

}
void deleteElementChild(Child &c,addressChild x){
    if(next(firstChild(c))==NULL){
        firstChild(c)=NULL;
    }
    else if(next(x)==NULL){
        next(prev(x))=NULL;
        prev(x)=NULL;
        next(x)=NULL;
    }
    else if(x==firstChild(c)){
        firstChild(c)=next(x);
        prev(firstChild(c))=NULL;
        next(x)=NULL;
    }
    else{
        next(prev(x))=next(x);
        prev(next(x))=prev(x);
        next(x)=NULL;
        prev(x)=NULL;
    }
    delete x;
}
void pembersihanChild(Child &C,addressChild c,Relasi r){
    if(firstRelasi(r)!=NULL){
        addressRelasi q = firstRelasi(r);
        int i=0;
        do{
            if(nextC(q)==c){
                i++;
            }
            q=next(q);
        }while(q!=firstRelasi(r));
        if(i==1){
            deleteElementChild(C,c);
        }
    }
}
void tampilkanSemuaJudulartikel(Parent p,addressParent Ap){
    if(firstParent(p)==NULL){
        cout<<"DAFTAR JUDUL KOSONG"<<endl;
    }
    else{
        Ap = firstParent(p);
        while(Ap!=NULL){
            cout<<"- "<<info(Ap).judul<<endl;
            Ap=next(Ap);
        }
    }
    system ("pause");
    system ("cls");
}
