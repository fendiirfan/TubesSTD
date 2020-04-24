#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"

void createListRelasi(Relasi &r){
    firstRelasi(r)=NULL;
}
void createElementRelasi(addressRelasi &e){
    e = new aRelasi;
    next(e)=prev(e)=NULL;
    nextC(e)=NULL;
    nextP(e)=NULL;
}
void insertLastRelasi(Relasi &r,addressRelasi a){
    if(firstRelasi(r)==NULL){
        firstRelasi(r)=a;
        next(a)=a;
        prev(a)=NULL;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){
        next(firstRelasi(r))=a;
        prev(a)=firstRelasi(r);
        next(a)=firstRelasi(r);
    }
    else{

        addressRelasi c = firstRelasi(r);
        do{
            c = next(c);
        }while(next(c)!=firstRelasi(r));
        next(c)=a;
        prev(a)=c;
        next(a)=firstRelasi(r);
    }
}

void connect(addressRelasi &ar,addressParent p,addressChild c){
    nextC(ar)=c;
    nextP(ar)=p;
}
void deleteElementRelasi(Relasi &p,addressRelasi x){
    if(next(firstRelasi(p))==firstRelasi(p)){
        firstRelasi(p)=NULL;
    }
    else if(x==firstRelasi(p)){
        addressRelasi r = firstRelasi(p);
        do{
            r=next(r);
        }while(next(r)!=firstRelasi(p));

        firstRelasi(p)=next(x);
        prev(firstRelasi(p))=NULL;
        prev(x)=NULL;
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
        prev(x)=NULL;
    }
    else{
        addressRelasi s = firstRelasi(p);
        while(next(s)!=x){
            s=next(s);
        }
        next(s)=next(x);
        prev(next(x))=s;
        next(x)=NULL;
        prev(x)=NULL;
    }
    delete x;
}

void HapusDaftarArtikel(Relasi &r, Parent &p, Child &c, addressChild Ac, addressRelasi Ar, addressParent Ap){
    string judul;
    cout<<"Masukan Judul Artikel yang Ingin Dihapus             : ";
    cin>>judul;
    system ("cls");
    if(findParent(p,judul)==NULL || firstParent(p)==NULL || firstChild(c)==NULL || firstRelasi(r)==NULL){
        cout<<"Judul Tidak Ditemukan atau Data Artikel Kosong"<<endl;
    }
    else{
        if(next(firstParent(p))==NULL){
            addressChild a = firstChild(c);
            firstChild(c)=NULL;
            delete a;
            addressParent u = firstParent(p);
            firstParent(p)=NULL;
            delete u;
            addressRelasi w = firstRelasi(r);
            firstRelasi(r)=NULL;
            delete w;

        }
        else{
            Ap=findParent(p,judul);
            addressRelasi g = firstRelasi(r);
            do{
                if(nextP(g)==Ap){
                    Ac=nextC(g);
                    Ar=g;
                }
                g=next(g);
            }while(Ac!=nextC(Ar) && g!=firstRelasi(r));
            pembersihanChild(c,Ac,r);
            deleteElementRelasi(r,Ar);
            deleteElementParent(p,Ap);
        }
    }
}
void HapusDaftarKeyword(Relasi &r, Parent &p, Child &c, addressChild Ac, addressRelasi Ar, addressParent Ap){
    system ("cls");
    cout<<"Masukan Keywordnya : ";
    string keyword;
    cin>>keyword;

    if(firstRelasi(r)==NULL || findChild(c,keyword)==NULL){
        cout<<"Judul Tidak Ditemukan atau Data Artikel Kosong"<<endl;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){

        deleteElementRelasi(r,firstRelasi(r));
        deleteElementChild(c,firstChild(c));
        deleteElementParent(p,firstParent(p));
    }
    else{
        Ar = firstRelasi(r);
        Ac = findChild(c,keyword);
    do{
        Ar=next(Ar);
    }while(next(Ar)!=firstRelasi(r));
    while(Ar!=NULL){
        if(nextC(Ar)==Ac){
            deleteElementParent(p,nextP(Ar));
            addressRelasi w = Ar;
            Ar=prev(Ar);
            deleteElementRelasi(r,w);
        }
        else{
            Ar=prev(Ar);
        }
    }
    deleteElementChild(c,Ac);
    system("pause");
    system ("cls");

    }
}
void tampilkanJudulArtikelBesertaKeywordnya(Relasi r,addressRelasi Ar){
    if(firstRelasi(r)==NULL){
        cout<<"Daftar Kosong"<<endl;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){
        cout<<info(nextP(firstRelasi(r))).judul<<"->"<<info(nextC(firstRelasi(r)))<<endl;
    }
    else{
        Ar=firstRelasi(r);
    do{
        cout<<"Judul : "<<info(nextP(Ar)).judul<<"  ->  Keyword: "<<info(nextC(Ar))<<endl;
            Ar=next(Ar);
        }while(Ar!=firstRelasi(r));
    }

}

void TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTerbanyak(Relasi r,Child c,addressRelasi Ar,addressChild Ac){
    system ("cls");
    if(firstRelasi(r)==NULL){
        cout<<"List Keyword Kosong atau Keyword tidak Ditemukan"<<endl;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){
        cout<<"Keyword Terbanyak Adalah : "<<info(firstChild(c))<<endl;
    }
    else{
        int jum =0;
        int i;
        addressChild max;
        Ar=firstRelasi(r);
        do{
            if(nextC(Ar)==firstChild(c)){
                    jum++;
            }
            Ar=next(Ar);
        }while(Ar!=firstRelasi(r));
        max = firstChild(c);

        Ac = next(firstChild(c));

        while(Ac!=NULL){
            i=0;
            Ar = firstRelasi(r);
            do{
                if(nextC(Ar)==Ac){
                    i++;
                }
                Ar=next(Ar);
            }while(Ar!=firstRelasi(r));
            if(i>jum){
                jum=i;
                max = Ac;
            }
            Ac=next(Ac);
        }
        cout<<"Keyword Terbanyak Adalah : "<<info(max)<<endl;
    }

    system ("pause");
    system ("cls");
}

void TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTersedikit(Relasi r,Child c,addressRelasi Ar,addressChild Ac){
    system ("cls");
    if(firstRelasi(r)==NULL){
        cout<<"List Keyword Kosong atau Keyword tidak Ditemukan"<<endl;
    }
    else if(next(firstRelasi(r))==firstRelasi(r)){
        cout<<"Keyword Terbanyak Adalah : "<<info(firstChild(c))<<endl;
    }
    else{
        int jum =0;
        int i;
        addressChild min;
        Ar=firstRelasi(r);
        do{
            if(nextC(Ar)==firstChild(c)){
                    jum++;
            }
            Ar=next(Ar);
        }while(Ar!=firstRelasi(r));
        min = firstChild(c);

        Ac = next(firstChild(c));

        while(Ac!=NULL){
            i=0;
            Ar = firstRelasi(r);
            do{
                if(nextC(Ar)==Ac){
                    i++;
                }
                Ar=next(Ar);
            }while(Ar!=firstRelasi(r));
            if(i<jum){
                jum=i;
                min = Ac;
            }
            Ac=next(Ac);
        }
        cout<<"Keyword Tersedikit Adalah : "<<info(min)<<endl;
    }

    system ("pause");
    system ("cls");
}

void CariArtikelberdasarkanKeyword(Relasi r,Child c,addressRelasi Ar){
    string keyword;
    cout<<"Input Keyword : ";
    cin>>keyword;
    if(firstChild(c)==NULL || findChild(c,keyword)==NULL){
        cout<<"List Keyword Kosong atau Keyword tidak Ditemukan"<<endl;
    }
    else{
        addressChild op = findChild(c,keyword);
        cout<<endl;
        Ar=firstRelasi(r);
        do{
            if(nextC(Ar)==op){
                cout<<"- "<<info(nextP(Ar)).judul<<endl;
            }
            Ar=next(Ar);
        }while(Ar!=firstRelasi(r));
    }
    system ("pause");
    system ("cls");
}
void TampilknanSemuaKeyword(Child c,addressChild Ac){
    if(firstChild(c)==NULL){
        cout<<"DAFTAR KEYWORD KOSONG"<<endl;
    }
    else{
        Ac=firstChild(c);
        while(Ac!=NULL){
            cout<<"- "<<info(Ac)<<endl;
            Ac=next(Ac);
        }
    }
    system ("pause");
    system ("cls");
}
