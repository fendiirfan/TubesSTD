#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"

void createListRelasi(Relasi &r){
    firstRelasi(r)=NULL;
}
void createElementRelasi(addressRelasi &e){
    e = new aRelasi;
    next(e)=NULL;
    nextC(e)=NULL;
    nextP(e)=NULL;
}
void insertLastRelasi(Relasi &r,addressRelasi a){
    if(firstRelasi(r)==NULL){
        firstRelasi(r)=a;
        next(a)=a;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){
        next(firstRelasi(r))=a;
        next(a)=firstRelasi(r);
    }
    else{
        addressRelasi c = firstRelasi(r);
        do{
            c = next(c);
        }while(next(c)!=firstRelasi(r));
        next(c)=a;
        next(a)=firstRelasi(r);
    }
}

void connect(addressRelasi &ar,addressParent &p,addressChild &c){
    nextC(ar)=c;
    nextP(ar)=p;
}
addressRelasi findRelasi(Relasi r,addressChild c,addressParent p){
    if(firstRelasi(r)==NULL){
        return NULL;
    }
    else{
       addressRelasi k = firstRelasi(r);
        if(next(k)==firstRelasi(r)){
            if(nextC(k)==c && nextP(k)==p){
                return k;
            }
            return NULL;
        }
        else{
            do{
               if(nextC(k)==c && nextP(k)==p){
                    return k;
                }
                k = next(k);
            }while(k!=firstRelasi(r));
        }
    }
}
