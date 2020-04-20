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
            cout<<"magefirah"<<endl;
        next(firstRelasi(r))=a;
        next(a)=firstRelasi(r);
    }
    else{
        cout<<"sukmawati"<<endl;
        addressRelasi c = firstRelasi(r);
        do{
            c = next(c);
        }while(next(c)!=firstRelasi(r));
        next(c)=a;
        next(a)=firstRelasi(r);
    }
}

void connect(addressRelasi &ar,addressParent p,addressChild c){
    nextC(ar)=c;
    nextP(ar)=p;
}
//addressRelasi findRelasi(Relasi r,addressChild c,addressParent p){
//    if(firstRelasi(r)==NULL){
//        return NULL;
//    }
//    else{
//       addressRelasi k = firstRelasi(r);
//        if(next(k)==firstRelasi(r)){
//            if(nextC(k)==c && nextP(k)==p){
//                return k;
//            }
//            return NULL;
//        }
//        else{
//            do{
//               if(nextC(k)==c && nextP(k)==p){
//                    return k;
//                }
//                k = next(k);
//            }while(k!=firstRelasi(r));
//        }
//    }
//}
void deleteElementRelasi(Relasi &p,addressRelasi x){
    if(next(firstRelasi(p))=firstRelasi(p)){
        firstRelasi(p)=NULL;
    }
    else if(x==firstRelasi(p)){
        addressRelasi r = firstRelasi(p);
        do{
            r=next(r);
        }while(next(r)!=firstRelasi(p));
        firstRelasi(p)=next(x);
        next(r)=firstRelasi(p);
        next(x)=NULL;
    }
    else if(next(x)==firstRelasi(p)){
        addressRelasi s = firstRelasi(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=firstRelasi(p);
        next(x)=NULL;
    }
    else{
        addressRelasi s = firstRelasi(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=next(x);
        next(x)=NULL;
    }
    delete x;
}
