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
            if(pil!=1 && pil!=2 && pil!=3 ){
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
                        cout<<"Input Judul Artikel Ilmiah   :"<<endl;
                        cin>>judul;
                        cout<<"Input Penulis               :"<<endl;
                        cin>>penulis;
                        cout<<"Input Publisher             :"<<endl;
                        cin>>publisher;
                        cout<<"Input Tahun                 :"<<endl;
                        cin>>tahun;
                        cout<<"Input Abstrak               :"<<endl;
                        cin>>abstrak;
                        cout<<"Input Keyword               :"<<endl;
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

                        cout<<"Masukan Judul Artikel yang Ingin Dihapus             :";
                        cin>>judul;
                        system ("cls");
                        if(findParent(p,judul)==NULL || firstParent(p)==NULL){
                            cout<<"Judul Tidak Ditemukan atau Data Artikel Kosong"<<endl;
                        }
                        else{

                        }
                    }
                    else if(pil==3){

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
                    goto menuUtama;
                case 3 :
                    cout<<"| | ==========TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI========== | |";
                    break;
            }

    return 0;
}
