#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"
using namespace std;
#include <stdlib.h>

int main()
{
    addressChild Ac;
    addressParent Ap;
    addressRelasi Ar;
    Child c;
    Parent p;
    Relasi r;

    createListParent(p);
    createListRelasi(r);
    createListChild(c);

            cout<<"| | ========================PERPUSTAKAAN========================== | |"<<endl;
            cout<<"| | ========================SELAMAT DATANG======================== | |"<<endl;
            cout<<endl;
            menuUtama:
            int pil;
            cout<<"| | ========================= MENU UTAMA ========================= | |"<<endl;
            cout<<"| | 1. Login Sebagai Pegawai Perpustakaan                          | |"<<endl;
            cout<<"| | 2. Login Sebagai Pengunjung Perpustaka                         | |"<<endl;
            cout<<"| | 3. Logout                                                      | |"<<endl;
            cout<<"| | ============================================================== | |"<<endl;
            cout<<"Pilih Menu : ";
            cin>>pil;
            if(pil!=1 && pil!=2 && pil!=3){
                system ("cls");
                cout<<"| | =======================Mohon Pilih Menu yang valid!!!======================= | |"<<endl;
                system ("pause");
                system ("cls");
                goto menuUtama;
            }
     //       system ("pause");
            system ("cls");
            switch (pil){
                case 1 :
                    menuPEGAWAI:
                    cout<<"| | =======================MENU PEGAWAI =======================                             | |"<<endl;
                    cout<<"| | 1. Tambah Daftar Artikel Ilmiah                                                         | |"<<endl;
                    cout<<"| | 2. Hapus Daftar Artikel Ilmiah                                                          | |"<<endl;
                    cout<<"| | 3. Hapus Daftar Suatu Keyword Beserta Judul Artikel Dengan Keyword Tersebut             | |"<<endl;
                    cout<<"| | 4. Menu Utama                                                                           | |"<<endl;
                    cout<<"| | ===========================================================                             | |"<<endl;
                    cout<<"Pilih Menu : ";
                    cin>>pil;
  //                  system ("pause");
                    system ("cls");
                    if(pil==1){
                        string judul, penulis, publisher, tahun, abstrak;
                        string keyword;
                        judulAb:
                        cout<<"Input Judul Artikel Ilmiah   : ";
                        cin>>judul;
                        if(findParent(p,judul)!=NULL){
                            system("cls");
                            cout<<"Judul Artikel Telah Terdaftar"<<endl;
                            ulangi:
                            cout<<"1. Ulangi Inputan Judul\n2. Kembali Ke Menu Pegawai\nInput : ";
                            cin>>pil;
                            system("cls");
                            if(pil==1){
                                goto judulAb;
                            }
                            else if(pil==2){
                                goto menuPEGAWAI;
                            }
                            else{
                                cout<<"Input Harus Valid!!!";
                                goto ulangi;
                            }


                        }
                        cout<<"Input Penulis               : ";
                        cin>>penulis;
                        cout<<"Input Publisher             : ";
                        cin>>publisher;
                        cout<<"Input Tahun                 : ";
                        cin>>tahun;
                        cout<<"Input Abstrak               : ";
                        cin>>abstrak;
                        cout<<"Input Keyword               : ";
                        cin>>keyword;
                        createElementParent(Ap,judul,penulis,publisher,tahun,abstrak);
                        insertFirstParent(p,Ap);
                        createElementRelasi(Ar);
                        insertLastRelasi(r,Ar);
                        if(findChild(c,keyword)==NULL || firstChild(c)==NULL){

                            createElementChild(Ac,keyword);
                            insertLastChild(c,Ac);
                            cout<<"irfan"<<endl;
                        }
                        else{

                            Ac=findChild(c,keyword);
                            cout<<"fendi"<<endl;
                        }

                        connect(Ar,Ap,Ac);
                        cout<<info(nextC(Ar))<<" "<<info(nextP(Ar)).judul<<endl;

                    }
                    else if(pil==2){
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
                                cout<<info(Ap).judul<<endl;
                                addressRelasi g = firstRelasi(r);
                                do{
                                    if(nextP(g)==Ap){
                                        Ac=nextC(g);
                                        cout<<info(Ac)<<endl;
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
                    else if(pil==3){
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
                            addressRelasi t= firstRelasi(r);
                            Ac= findChild(c,keyword);
                            cout<<"fendassa "<<info(Ac)<<endl;
                            do{
                                cout<<"amalia"<<endl;
                                if(nextC(t)==Ac){
                                    cout<<"fendi"<<endl;
                                    deleteElementParent(p,nextP(t));
                                    Ar= t;
                                    t=next(t);
                                    deleteElementRelasi(r,Ar);
                                }
                                else{
                                        cout<<"amalia sd"<<endl;
                                    t = next(t);
                                }

                            }while(t!=firstRelasi(r));
                            deleteElementChild(c,Ac);
                        }
                        system("pause");
                        system ("cls");

                    }
                    else if(pil==4){
                        goto menuUtama;
                    }
                    else{
                        cout<<"| | =======================Mohon Pilih Menu yang valid!!!======================= | |"<<endl;
                        system ("pause");
                        system ("cls");
                        goto menuPEGAWAI;
                    }
                    system ("pause");
                    system ("cls");
                    cout<<"| | =======================BERHASIL======================= | |"<<endl;
                    system ("pause");
                    system ("cls");
                    goto menuPEGAWAI;

                case 2 :
                    menuPENGUNJUNG:
                    cout<<"| | =======================MENU PENGUNJUNG =======================                          | |"<<endl;
                    cout<<"| | 1. Tampilkan Semua Daftar Judul Artikel Ilmia Beserta Keywordnya                        | |"<<endl;
                    cout<<"| | 2. Tampilkan Data Keyword Yang paling Banyak Judul Artikel Ilmiah                       | |"<<endl;
                    cout<<"| | 3. Tampilkan Data Keyword Yang paling Sedikit Judul Artikel Ilmiah                      | |"<<endl;
                    cout<<"| | 4. Cari Koleksi Artikel Berdasarkan Keyword                                             | |"<<endl;
                    cout<<"| | 5. Munculkan Data Keyword                                                               | |"<<endl;
                    cout<<"| | 6. Munculkan Data Artikel Ilmiah                                                        | |"<<endl;
                    cout<<"| | 7. Menu Utama                                                                           | |"<<endl;
                    cout<<"| | ===========================================================                             | |"<<endl;
                    cout<<"Pilih Menu : ";
                    cin>>pil;
  //                system ("pause");
                    system ("cls");
                    if(pil==1){
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
                        system ("pause");
                        system ("cls");
                        goto menuPENGUNJUNG;
                    }
                    else if(pil==2){
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
                        goto menuPENGUNJUNG;
                    }
                    else if(pil==3){
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
                        goto menuPENGUNJUNG;
                    }

                    else if(pil==4){
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
                        goto menuPENGUNJUNG;

                    }else if(pil==5){
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
                        goto menuPENGUNJUNG;
                    }else if(pil==6){
                        if(firstChild(c)==NULL){
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
                        goto menuPENGUNJUNG;
                    }else if(pil==7){
                        goto menuUtama;
                    }
                    else{
                        cout<<"| | =======================Mohon Pilih Menu yang valid!!!======================= | |"<<endl;
                        system ("pause");
                        system ("cls");
                        goto menuPENGUNJUNG;
                    }
                case 3 :
                    cout<<"| | ==========TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI========== | |";
                    break;
            }

    return 0;
}
