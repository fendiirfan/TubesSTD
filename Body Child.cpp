#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"

void createListChild(Child &c){
    firstChild(c)=NULL;
}
void createElementChild(addressChild c,infoChild w){
    c = new aChild;
    next(c)=NULL;
    info(c)=w;
}
