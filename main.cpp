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

    cout<<"| | =============================PERPUSTAKAAN========================== | |"<<endl;
            cout<<"| | ========================SELAMAT DATANG======================== | |"<<endl;
            cout<<endl;
            menu:
            int pil;
            cout<<"| | =========================MENU PILIHAN========================= | |"<<endl;
            cout<<"| | 1. Login Sebagai Pengunjung Perpustakaan                       | |"<<endl;
            cout<<"| | 2. Login Sebagai Pegawai Perpustaka                            | |"<<endl;
            cout<<"| | 3. Logout                                                      | |"<<endl;
            cout<<"| | ============================================================== | |"<<endl;
            cout<<"Pilih Menu : ";
            cin>>pil;
     //       system ("pause");
            system ("cls");

            switch (pil){
                case 1 :
                    case1:
                    cout<<"| | =======================MENU TAMBAH DATA======================= | |"<<endl;
                    cout<<"| | 1. Tambah Daftar Artikel Ilmiah                                | |"<<endl;
                    cout<<"| | 2. Hapus Daftar Artikel Ilmiah                                 | |"<<endl;
                    cout<<"| | 3. Hapus Daftar Suatu Keyword                                    | |"<<endl;
                    cout<<"| | ============================================================== | |"<<endl;
                    cout<<"Pilih Menu : ";
                    cin>>pil;
  //                  system ("pause");
                    system ("cls");
                    if(pil==1){
                        string judul, penulis, publisher, tahun, abstrak;
                        cout<<"Input Nama Artikel Ilmiah   :"<<endl;
                        cin>>judul;
                        cout<<"Input Penulis               :"<<endl;
                        cin>>penulis;
                        cout<<"Input Publisher             :"<<endl;
                        cin>>publisher;
                        cout<<"Input Tahun                 :"<<endl;
                        cin>>tahun;
                        cout<<"Input Abstrak               :"<<endl;
                        cin>>abstrak;

                    }
                    else if(pil==2){

                    }
                    else if(pil==3){

                    }
                    else{
                        cout<<"| | =======================Mohon Pilih Menu yang valid!!!======================= | |"<<endl;
                        system ("pause");
                        system ("cls");
                        goto case1;
                    }
                    goto menu;

                case 2 :
                    goto menu;
                case 3 :
                    cout<<"| | ==========TERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI========== | |";
                    break;
            }

    return 0;
}
