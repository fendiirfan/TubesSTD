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
    if(next(firstRelasi(p))==firstRelasi(p)){
        cout<<"as1"<<endl;
        firstRelasi(p)=NULL;
    }
    else if(x==firstRelasi(p)){
        addressRelasi r = firstRelasi(p);
    cout<<"as2"<<endl;
        do{
            r=next(r);
        }while(next(r)!=firstRelasi(p));
        firstRelasi(p)=next(x);
        next(r)=firstRelasi(p);
        next(x)=NULL;
    }
    else if(next(x)==firstRelasi(p)){
            cout<<"as3"<<endl;
        addressRelasi s = firstRelasi(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=firstRelasi(p);
        next(x)=NULL;
    }
    else{
        cout<<"as4"<<endl;
        addressRelasi s = firstRelasi(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=next(x);
        next(x)=NULL;
    }
    delete x;
}
