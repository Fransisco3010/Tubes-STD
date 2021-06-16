#include "Header_Parent.h"

void createList_Parent(List_P &L){
    First(L) = NULL;
    Last(L) = NULL;
}

addressP alokasi_Parent(infotypeP dataBaru){
    addressP P = new elm_p;
    Info(P) = dataBaru;
    Next(P) = NULL;
    Prev(P) = NULL;
    return P;
}

void tambahData_Parent(List_P &L, addressP P){
    if (First(L) == NULL){
        First(L) = P;
        Last(L) = P;
        Next(P) = First(L);
        Prev(P) = First(L);
    }else{
        Next(Last(L)) = P;
        Prev(P) = Last(L);
        Last(L) = P;
        Next(Last(L)) = First(L);
        Prev(First(L)) = Last(L);
    }
}

void hapusData_Parent(List_P &L, addressP &P, infotypeP dataX){
    addressP Q = findElement_Parent(L, dataX);
    if (First(L) == NULL){
        cout<<"Tidak Ada Data yang sudah Dimasukkan"<<endl;
    }else if (Next(Q) == First(L) && Prev(Q) == Last(L)){
        First(L) = NULL;
        Last(L) = NULL;
    }else{
        if (Q == First(L)){
            P = First(L);
            First(L) = Next(P);
            Next(Last(L)) = First(L);
            Prev(First(L)) = Last(L);
            Next(P) = NULL;
            Prev(P) = NULL;
        }else if (Q == Last(L)){
            P = Last(L);
            Last(L) = Prev(P);
            Prev(First(L)) = Last(L);
            Next(Last(L)) = First(L);
            Next(P) = NULL;
            Prev(P) = NULL;
        }else{
            Q = Prev(findElement_Parent(L, dataX));
            P = Next(Q);
            Next(Q) = Next(P);
            Prev(Next(P)) = Q;
            Next(P) = NULL;
            Prev(P) = NULL;
        }
    }
}

void printInfo_Parent(List_P L){
    addressP Q = First(L);
    while (Next(Q) != First(L)){
        cout<<Info(Q)<<endl;
        Q = Next(Q);
    }
    cout<<Info(Q)<<endl;
}

addressP findElement_Parent(List_P L, infotypeP dataX){
    addressP Q = First(L);
    while (Next(Q) != First(L) && Info(Q) != dataX){
        Q = Next(Q);
    }
    if (Info(Q) == dataX){
        return Q;
    }else{
        return NULL;
    }
}
