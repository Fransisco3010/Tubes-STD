#include "Header_Relasi.h"

void connect(addressP P, addressC &C){
    if (P != NULL && C != NULL ){
        Parent(C) = P;
    }
}

void disconnect(addressC &C){
    if(C != NULL){
        Parent(C) = NULL;
    }
}

void printRelasi(List_P LP, List_C LC){
    addressP P;
    addressC C;

    P = First(LP);
    cout<<endl;
    if(First(LP) == NULL){
        cout<<"Maaf Belum Ada Data yang Dimasukkan"<<endl;
    }else{
        while (Next(P) != First(LP)){
            cout<<"Kota "<<Info(P)<<" :"<<endl;
            C = First(LC);
            while (C != NULL){
                if(Parent(C) == P){
                    cout<<"Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<endl;
                }
                C = Next(C);
            }
            cout<<endl;
            P = Next(P);
        }
        cout<<"Kota "<<Info(P)<<" :"<<endl;
        C = First(LC);
        while (C != NULL){
            if (Parent(C) == P){
                cout<<"Jalan "<<Info(C).tipeJalan<<" "<<Info(C).namaJalan<<endl;
            }
            C = Next(C);
        }
    }
}
