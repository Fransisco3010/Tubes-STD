#include <iostream>
#include "Header_Parent.h"
#include "Header_Child.h"
#include "Header_Relasi.h"

using namespace std;

List_P Kota;
List_C Jalan;
infotypeP namaKota;
string tipeJalan;
string namaJalan;
string Parent;
addressP P;
addressC C;
addressC T;
addressP simpanDataP;
addressC simpanDataC;
string Status1;
string Status2;

int main(){
    createList_Parent(Kota);
    createList_Child(Jalan);
    cout<<"SELAMAT DATANG DI PROGRAM KOTA DAN JALAN"<<endl;
    cout<<"1. Menambah Data"<<endl<<"2. Menentukan Relasi"<<endl<<"3. Menghapus Data"<<endl
        <<"4. Menampilkan Data"<<endl<<"5. Tutup Program"<<endl;
    cout<<"Silahkan Memilih Apa yang Ingin Dilakukan (Harus Angka) : ";
    cin>>Status1;
    while (Status1 != "5"){
        if (Status1 == "1"){
            cout<<endl;
            cout<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
            cout<<"Silahkan Memilih Data yang Akan Ditambahkan (Harus Angka) : ";
            cin>>Status2;
            while (Status2 != "3"){
                if (Status2 == "1"){
                    cout<<endl<<"Masukkan Nama Kota yang ingin ditambahkan (Jika terdiri dari 2 kata gunakan '_') : ";
                    cin>>namaKota;
                    tambahData_Parent(Kota, alokasi_Parent(namaKota));
                    cout<<"Data Berhasil Ditambahkan !"<<endl;
                    Status2 = "Ulang";
                }else if (Status2 == "2"){
                    cout<<endl<<"Masukkan Tipe Jalan yang ingin ditambahkan (Jika terdiri dari 2 kata gunakan '_') : ";
                    cin>>tipeJalan;
                    cout<<"Masukkan Nama Jalan yang ingin ditambahkan (Jika terdiri dari 2 kata gunakan '_') : ";
                    cin>>namaJalan;
                    tambahData_Child(Jalan, alokasi_Child(tipeJalan, namaJalan));
                    cout<<"Data Berhasil Ditambahkan !"<<endl;
                    Status2 = "Ulang";
                }else if (Status2 == "Ulang"){
                    cout<<endl<<"Apa ada lagi Data yang ingin Ditambahkan ?"<<endl;
                    cout<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Data yang Akan Ditambahkan (Harus Angka) : ";
                    cin>>Status2;
                }else{
                    cout<<endl<<"Maaf, Pilihan Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                    cout<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Data yang Akan Ditambahkan (Harus Angka) : ";
                    cin>>Status2;
                }
            }
            Status1 = "Ulang";
        }else if(Status1 == "2"){
            cout<<endl<<"1. Menghubungkan Kota dengan Jalan Tertentu"<<endl
                <<"2. Memutuskan Hubungan Kota dengan Jalan Tertentu"<<endl<<"3. Selesai"<<endl;
            cout<<"Silahkan Memilih Tindakan yang akan dilakukan (Harus Angka) : ";
            cin>>Status2;
            while (Status2 != "3"){
                if (Status2 == "1"){
                    if(First(Kota) != NULL){
                        cout<<endl<<"Daftar Kota :"<<endl;
                        printInfo_Parent(Kota);
                        cout<<endl<<"Daftar Jalan :"<<endl;
                        printInfo_Child(Jalan);
                        cout<<endl<<"Masukkan Nama Kota yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Kota) : ";
                        cin>>namaKota;
                        cout<<"Masukkan Tipe Jalan yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                        cin>>tipeJalan;
                        cout<<"Masukkan Nama Jalan yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                        cin>>namaJalan;
                        P = findElement_Parent(Kota, namaKota);
                        C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        while (P == NULL || C == NULL){
                            cout<<endl<<"Maaf, Data Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<"Daftar Kota :"<<endl;
                            printInfo_Parent(Kota);
                            cout<<endl<<"Daftar Jalan :"<<endl;
                            printInfo_Child(Jalan);
                            cout<<endl<<"Masukkan Nama Kota yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Kota) : ";
                            cin>>namaKota;
                            cout<<"Masukkan Tipe Jalan yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                            cin>>tipeJalan;
                            cout<<"Masukkan Nama Jalan yang ingin dihubungkan (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                            cin>>namaJalan;
                            P = findElement_Parent(Kota, namaKota);
                            C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        }
                        connect(P, C);
                        cout<<"Jalan "<<tipeJalan<<" "<<namaJalan<<" berhasil dihubungkan dengan Kota "<<namaKota<<" !"<<endl;
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if (Status2 == "2"){
                    if (First(Jalan) != NULL){
                        cout<<endl<<"Daftar Hubungan :"<<endl;
                        printInfo_ChildParent(Jalan);
                        cout<<"Masukkan Tipe Jalan yang ingin Memutus Hubungan (Harus sesuai dengan penulisan pada Daftar Hubungan) : ";
                        cin>>tipeJalan;
                        cout<<"Masukkan Nama Jalan yang ingin Memutus Hubungan (Harus sesuai dengan penulisan pada Daftar Hubungan) : ";
                        cin>>namaJalan;
                        C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        while (C == NULL){
                            cout<<endl<<"Maaf, Data Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<"Daftar Hubungan :"<<endl;
                            printInfo_ChildParent(Jalan);
                            cout<<"Masukkan Tipe Jalan yang ingin Memutus Hubungan (Harus sesuai dengan penulisan pada Daftar Hubungan) : ";
                            cin>>tipeJalan;
                            cout<<"Masukkan Nama Jalan yang ingin Memutus Hubungan (Harus sesuai dengan penulisan pada Daftar Hubungan) : ";
                            cin>>namaJalan;
                            C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        }
                        if (Parent(C) != NULL){
                            P = Parent(C);
                            disconnect(C);
                            cout<<"Jalan "<<tipeJalan<<" "<<namaJalan<<" berhasil memutuskan hubungan dengan Kota "<<Info(P)<<" !"<<endl;
                            Status2 = "Ulang";
                        }else{
                            cout<<"Jalan Ini Belum Dihubungkan dengan Kota manapun"<<endl;
                            Status2 = "Ulang";
                        }
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if(Status2 == "Ulang"){
                    cout<<endl<<"Apa ada lagi yang ingin dilakukan ?"<<endl;
                    cout<<"1. Menghubungkan Kota dengan Jalan Tertentu"<<endl
                        <<"2. Memutuskan Hubungan Kota dengan Jalan Tertentu"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Tindakan yang akan dilakukan (Harus Angka) : ";
                    cin>>Status2;
                }else{
                    cout<<endl<<"Maaf, Pilihan Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                    cout<<"1. Menghubungkan Kota dengan Jalan Tertentu"<<endl
                        <<"2. Memutuskan Hubungan Kota dengan Jalan Tertentu"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Tindakan yang akan dilakukan (Harus Angka) : ";
                    cin>>Status2;
                }
            }
            Status1 = "Ulang";
        }else if(Status1 == "3"){
            cout<<endl<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
            cout<<"Silahkan Memilih Data yang akan dihapus (Harus Angka) : ";
            cin>>Status2;
            while (Status2 != "3"){
                if (Status2 == "1"){
                    if(First(Kota) != NULL){
                        cout<<endl<<"Daftar Kota :"<<endl;
                        printInfo_Parent(Kota);
                        cout<<endl<<"Masukkan Nama Kota yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Kota) : ";
                        cin>>namaKota;
                        P = findElement_Parent(Kota, namaKota);
                        while (P == NULL){
                            cout<<endl<<"Maaf, Data tidak ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<"Daftar Kota :"<<endl;
                            printInfo_Parent(Kota);
                            cout<<endl<<"Masukkan Nama Kota yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Kota): ";
                            cin>>namaKota;
                            P = findElement_Parent(Kota, namaKota);
                        }
                        hapusData_Parent(Kota, simpanDataP, namaKota);
                        C = First(Jalan);
                        while (C != NULL){
                            if(Parent(C) != NULL){
                                if(Info(Parent(C)) == namaKota){
                                    disconnect(C);
                                }
                            }
                            C = Next(C);
                        }
                        cout<<"Data Berhasil Dihapus !"<<endl;
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if (Status2 == "2"){
                    if(First(Jalan) != NULL){
                        cout<<endl<<"Daftar Jalan :"<<endl;
                        printInfo_Child(Jalan);
                        cout<<endl<<"Masukkan Tipe Jalan yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                        cin>>tipeJalan;
                        cout<<"Masukkan Nama Jalan yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                        cin>>namaJalan;
                        C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        while (C == NULL){
                            cout<<"Maaf, Data tidak ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<endl<<"Daftar Jalan :"<<endl;
                            printInfo_Child(Jalan);
                            cout<<endl<<"Masukkan Tipe Jalan yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                            cin>>tipeJalan;
                            cout<<"Masukkan Nama Jalan yang akan Dihapus (Harus sesuai dengan penulisan pada Daftar Jalan) : ";
                            cin>>namaJalan;
                            C = findElement_Child(Jalan, namaJalan, tipeJalan);
                        }
                        hapusData_Child(Jalan, simpanDataC, namaJalan, tipeJalan);
                        cout<<"Data Berhasil Dihapus !"<<endl;
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }if(Status2 == "Ulang"){
                    cout<<endl<<"Apa ada data yang ingin dihapus lagi?";
                    cout<<endl<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Data yang akan dihapus (Harus Angka) : ";
                    cin>>Status2;
                }else{
                    cout<<endl<<"Maaf, Pilihan Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                    cout<<"1. Data Kota"<<endl<<"2. Data Jalan"<<endl<<"3. Selesai"<<endl;
                    cout<<"Silahkan Memilih Data yang akan dihapus (Harus Angka) : ";
                    cin>>Status2;
                }
            }
            Status1 = "Ulang";
        }else if (Status1 == "4"){
            cout<<endl<<"1. Menampilkan Data Keseluruhan"<<endl<<"2. Menampilkan Kota yang Memiliki Jalan Tertentu"<<endl
                <<"3. Menampilkan data Jalan pada Kota Tertentu"<<endl<<"4. Menampilkan data Jalan dengan tipe Tertentu"<<endl
                <<"5. Selesai"<<endl;
            cout<<"Masukkan pilihan anda (Harus Angka) : ";
            cin>>Status2;
            while(Status2 != "5"){
                if (Status2 == "1"){
                    printRelasi(Kota, Jalan);
                    Status2 = "Ulang";
                }else if(Status2 == "2"){
                    if(First(Jalan) != NULL){
                        cout<<endl<<"Masukkan Nama Jalan yang ingin Dicari : ";
                        cin>>namaJalan;
                        C = findElement_NamaJalan(Jalan, namaJalan);
                        while (C == NULL){
                            cout<<"Maaf, Nama Jalan tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<"Masukkan Nama Jalan yang ingin Dicari : ";
                            cin>>namaJalan;
                            C = findElement_NamaJalan(Jalan, namaJalan);
                        }
                        if (Parent(C) == NULL){
                            cout<<"Tidak ada Kota yang memiliki nama Jalan tersebut"<<endl;
                            Status2 = "Ulang";
                        }else{
                            while (C != NULL){
                                if(Info(C).namaJalan == namaJalan){
                                    cout<<endl<<"Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<" Terdapat di Kota "<<Info(Parent(C))<<endl;
                                }
                                C = Next(C);
                            }
                        }
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if(Status2 == "3"){
                    if (First(Kota) != NULL){
                        cout<<endl<<"Daftar Kota :"<<endl;
                        printInfo_Parent(Kota);
                        cout<<endl<<"Masukkan Nama Kota yang ingin Ditampilkan (Harus sesuai dengan penulisan pada Daftar Kota) : ";
                        cin>>namaKota;
                        P = findElement_Parent(Kota, namaKota);
                        while (P == NULL){
                            cout<<"Maaf, Nama Kota tidak ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<endl<<"Daftar Kota :"<<endl;
                            printInfo_Parent(Kota);
                            cout<<"Masukkan Nama Kota yang ingin Ditampilkan (Harus sesuai dengan penulisan pada Daftar Kota) : ";
                            cin>>namaKota;
                            P = findElement_Parent(Kota, namaKota);
                        }
                        cout<<endl<<"Nama Kota : "<<Info(P)<<endl<<"Daftar Jalan : "<<endl;
                        C = First(Jalan);
                        while (C != NULL){
                            if (Parent(C) == P){
                                cout<<"Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<endl;
                            }
                            C = Next(C);
                        }
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if(Status2 == "4"){
                    if (First(Jalan) != NULL){
                        cout<<endl<<"Masukkan Tipe Jalan yang Dicari : ";
                        cin>>tipeJalan;
                        C = findElement_TipeJalan(Jalan, tipeJalan);
                        while (C == NULL){
                            cout<<"Maaf, Tipe Jalan tidak ditemukan. Silahkan Coba Lagi !"<<endl;
                            cout<<"Masukkan Tipe Jalan yang Dicari : ";
                            cin>>tipeJalan;
                            C = findElement_TipeJalan(Jalan, tipeJalan);
                        }
                        C = First(Jalan);
                        cout<<endl<<"Berikut Ini Daftar Jalan "<<tipeJalan<<" : "<<endl;
                        while (C != NULL){
                            if(Parent(C) == NULL && Info(C).tipeJalan == tipeJalan){
                                cout<<"Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<endl;
                            }else if (Parent(C) != NULL && Info(C).tipeJalan == tipeJalan){
                                cout<<"Pada Kota "<<Info(Parent(C))<<" Terdapat Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<endl;
                            }
                        C = Next(C);
                        }
                        Status2 = "Ulang";
                    }else{
                        cout<<endl<<"Maaf, belum ada Data yang telah Dimasukkan"<<endl;
                        Status2 = "Ulang";
                    }
                }else if(Status2 == "Ulang"){
                    cout<<endl<<"Apa ada yang ingin ditampilkan lagi?"<<endl;
                    cout<<"1. Menampilkan Data Keseluruhan"<<endl<<"2. Menampilkan Kota yang Memiliki Jalan Tertentu"<<endl
                        <<"3. Menampilkan data Jalan pada Kota Tertentu"<<endl<<"4. Menampilkan data Jalan dengan tipe Tertentu"<<endl
                        <<"5. Selesai"<<endl;
                    cout<<"Masukkan pilihan anda (Harus Angka) : ";
                    cin>>Status2;
                }else{
                    cout<<endl<<"Maaf, Pilihan Tidak Ditemukan. Silahkan Coba Lagi !"<<endl;
                    cout<<"1. Menampilkan Data Keseluruhan"<<endl<<"2. Menampilkan Kota yang Memiliki Jalan Tertentu"<<endl
                        <<"3. Menampilkan data Jalan pada Kota Tertentu"<<endl<<"4. Menampilkan data Jalan dengan tipe Tertentu"<<endl
                        <<"5. Selesai"<<endl;
                    cout<<"Masukkan pilihan anda (Harus Angka) : ";
                    cin>>Status2;
                }
            }
            Status1 = "Ulang";
        }else if(Status1 == "Ulang"){
            cout<<endl<<"Apa ada yang ingin dilakukan lagi?"<<endl;
            cout<<"1. Menambah Data"<<endl<<"2. Menentukan Relasi"<<endl<<"3. Menghapus Data"<<endl
                <<"4. Menampilkan Data"<<endl<<"5. Tutup Program"<<endl;
            cout<<"Silahkan Memilih Apa yang Ingin Dilakukan (Harus Angka) : ";
            cin>>Status1;
        }else{
            cout<<endl<<"Maaf, Pilihan Tidak Ditemukan. Silahkan Coba Lagi!"<<endl;
            cout<<"1. Menambah Data"<<endl<<"2. Menentukan Relasi"<<endl<<"3. Menghapus Data"<<endl
                <<"4. Menampilkan Data"<<endl<<"5. Tutup Program"<<endl;
            cout<<"Silahkan Memilih Apa yang Ingin Dilakukan (Harus Angka) : ";
            cin>>Status1;
        }
    }
}
