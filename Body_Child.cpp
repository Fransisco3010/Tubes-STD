#include "Header_Child.h"

void createList_Child(List_C &L){
    First(L) = NULL;
}

addressC alokasi_Child(string tipeJalan, string namaJalan){
    addressC P = new elm_c;
    Info(P).tipeJalan = tipeJalan;
    Info(P).namaJalan = namaJalan;
    Next(P) = NULL;
}

void tambahData_Child(List_C &L, addressC P){
    if (First(L) == NULL){
        First(L) = P;
    }else{
        addressC Q = First(L);
        while (Next(Q) != NULL){
            Q = Next(Q);
        }
        Next(Q) = P;
    }
}

void hapusData_Child(List_C &L, addressC &P, string namaJalan, string tipeJalan){
    P = findElement_NamaJalan(L, namaJalan);
    if(First(L) == NULL){
        cout<<"Tidak Ada Data yang sudah Dimasukkan"<<endl;
    }else if (P == NULL){
        First(L) = NULL;
    }else{
        P = findElement_NamaJalan(L, namaJalan);
        while (Info(P).tipeJalan != tipeJalan){
            P = Next(P);
        }
        if(Info(P).tipeJalan == tipeJalan){
            addressC R = First(L);
            Parent(P) = NULL;
            if (P == First(L)){
                First(L) = Next(First(L));
                Next(P) = NULL;
            }else if (Next(P) == NULL){
                while(Next(R) != P){
                    R = Next(R);
                }
                Next(R) = NULL;
            }else{
                while (Next(R) != P){
                    R = Next(R);
                }
                Next(R) = Next(P);
                Next(P) = NULL;
            }
        }
    }
}

void printInfo_Child(List_C L){
    addressC P = First(L);
    while (P != NULL){
        cout<<"Jalan "<<Info(P).tipeJalan<<" "<<Info(P).namaJalan<<endl;
        P = Next(P);
    }
}

void printInfo_ChildParent(List_C L){
    addressC P = First(L);
    while (P != NULL){
        if(Parent(P) != NULL){
            cout<<"Jalan "<<Info(P).tipeJalan<<" "<<Info(P).namaJalan
                <<" Terhubung dengan Kota "<<Info(Parent(P))<<endl;
        }else{
            cout<<"Jalan "<<Info(P).tipeJalan<<" "<<Info(P).namaJalan
                <<" Belum Terhubung"<<endl;
        }
        P = Next(P);
    }
    cout<<endl;
}

addressC findElement_NamaJalan(List_C L, string dataX){
    addressC P = First(L);
    while (Next(P) != NULL && Info(P).namaJalan != dataX){
        P = Next(P);
    }
    if (Info(P).namaJalan == dataX){
        return P;
    }else{
        return NULL;
    }
}

addressC findElement_TipeJalan(List_C L, string dataX){
    addressC P = First(L);
    while (Next(P) != NULL && Info(P).tipeJalan != dataX){
        P = Next(P);
    }
    if (Info(P).tipeJalan == dataX){
        return P;
    }else{
        return NULL;
    }
}

addressC findElement_Child(List_C L, string namaJalan, string tipeJalan){
    addressC P = First(L);
    int Status = 0;
    if (Info(P).namaJalan == namaJalan && Info(P).tipeJalan == tipeJalan){
        Status = 1;
    }else{
        while (Next(P) != NULL && Status == 0){
            if(Info(P).namaJalan == namaJalan && Info(P).tipeJalan == tipeJalan){
                Status = 1;
            }else{
                P = Next(P);
            }
        }
    }
    if (Info(P).namaJalan == namaJalan && Info(P).tipeJalan == tipeJalan){
        return P;
    }else{
        return NULL;
    }
}
