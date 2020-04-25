#include "RELASI.h"
#include "PARENT.h"
#include "CHILD.h"
#include <string>
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

    string judul, penulis, publisher, tahun, abstrak,k;
    string keyword;

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
                        judulAb:
                        getline(cin,k);
                        cout<<"Input Judul Artikel Ilmiah  : ";
                        getline(cin,judul);
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
                        getline(cin,penulis);
                        cout<<"Input Publisher             : ";
                        getline(cin,publisher);
                        cout<<"Input Tahun                 : ";
                        getline(cin,tahun);
                        cout<<"Input Abstrak               : ";
                        getline(cin,abstrak);
                        cout<<"Input Keyword               : ";
                        getline(cin,keyword);
                        createElementParent(Ap,judul,penulis,publisher,tahun,abstrak);
                        insertFirstParent(p,Ap);
                        createElementRelasi(Ar);
                        insertLastRelasi(r,Ar);
                        if(findChild(c,keyword)==NULL || firstChild(c)==NULL){
                            createElementChild(Ac,keyword);
                            insertLastChild(c,Ac);
                        }
                        else{
                            Ac=findChild(c,keyword);
                        }
                        connect(Ar,Ap,Ac);
                    }
                    else if(pil==2){
                        HapusDaftarArtikel(r,p,c,Ac,Ar,Ap);
                    }
                    else if(pil==3){
                        HapusDaftarKeyword(r,p,c,Ac,Ar,Ap);
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
                    cout<<"| | 2. Tampilkan Salah Satu Data Keyword Yang paling Banyak Judul Artikel Ilmiah            | |"<<endl;
                    cout<<"| | 3. Tampilkan Salah Satu Data Keyword Yang paling Sedikit Judul Artikel Ilmiah           | |"<<endl;
                    cout<<"| | 4. Cari Koleksi Artikel Berdasarkan Keyword                                             | |"<<endl;
                    cout<<"| | 5. Munculkan Data Keyword                                                               | |"<<endl;
                    cout<<"| | 6. Munculkan Data Artikel Ilmiah                                                        | |"<<endl;
                    cout<<"| | 7. Munculkan Informasi Lengkap dari Suatu Judul Artikel Ilmiah                          | |"<<endl;
                    cout<<"| | 8. Menu Utama                                                                           | |"<<endl;
                    cout<<"| | ===========================================================                             | |"<<endl;
                    cout<<"Pilih Menu : ";
                    cin>>pil;
  //                system ("pause");
                    system ("cls");
                    if(pil==1){
                        tampilkanJudulArtikelBesertaKeywordnya(r,Ar);
                        system ("pause");
                        system ("cls");
                        goto menuPENGUNJUNG;
                    }
                    else if(pil==2){
                        TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTerbanyak(r,c,Ar,Ac);
                        goto menuPENGUNJUNG;
                    }
                    else if(pil==3){
                        TampilkanKeywordYangMemilikiRelasiKejudulIlmiahTersedikit(r,c,Ar,Ac);
                        goto menuPENGUNJUNG;
                    }

                    else if(pil==4){
                        CariArtikelberdasarkanKeyword(r,c,Ar);
                        goto menuPENGUNJUNG;

                    }else if(pil==5){
                        TampilknanSemuaKeyword(c,Ac);
                        goto menuPENGUNJUNG;
                    }else if(pil==6){
                        tampilkanSemuaJudulartikel(p,Ap);
                        goto menuPENGUNJUNG;
                    }else if(pil==7){

                        cout<<"Inputkan Judul : ";
                        getline(cin,judul);
                        getline(cin,judul);
                        Ap=findParent(p,judul);
                        system ("cls");
                        if(findParent(p,judul)==NULL || firstChild(c)==NULL){
                            cout<<"Data Artikel Tidak Ditemukan"<<endl;
                        }
                        else{
                            Ar=firstRelasi(r);
                        do{
                            Ar=next(Ar);
                        }while(nextP(Ar)!=Ap);
                            cout<<"Judul       : "<<info(nextP(Ar)).judul<<endl;
                            cout<<"Penulis     : "<<info(nextP(Ar)).penulis<<endl;
                            cout<<"Publisher   : "<<info(nextP(Ar)).publisher<<endl;
                            cout<<"Tahun       : "<<info(nextP(Ar)).tahun<<endl;
                            cout<<"Abstrak     : "<<info(nextP(Ar)).abstrak<<endl;
                            cout<<"Keyword     : "<<info(nextC(Ar))<<endl;
                        }
                        system ("pause");
                        system ("cls");
                        goto menuPENGUNJUNG;
                    }else if(pil==8){
                        goto menuUtama;
                    }else{
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
