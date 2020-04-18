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
void deleteElementRelasi(Child &p,addressChild x){
    if(x=firstChild(p)){
        firstChild(p)=NULL;
    }
    else{
        next(prev(x))=next(x);
        prev(next(x))=prev(x);
        next(x)=prev(x)=NULL;
    }
    delete x;
}
