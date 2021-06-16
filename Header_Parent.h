#ifndef HEADER_PARENT_H_INCLUDED
#define HEADER_PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define First(L) L.First
#define Last(L) L.Last
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Info(P) P->Info

typedef string infotypeP;
typedef struct elm_p *addressP;

struct elm_p{
    addressP Next;
    addressP Prev;
    infotypeP Info;
};

struct List_P{
    addressP First;
    addressP Last;
};

void createList_Parent(List_P &L);
addressP alokasi_Parent(infotypeP dataBaru);
void tambahData_Parent(List_P &L, addressP P);
void hapusData_Parent(List_P &L, addressP &P, infotypeP dataX);
void printInfo_Parent(List_P L);
addressP findElement_Parent(List_P L, infotypeP dataX);

#endif // HEADER_PARENT_H_INCLUDED
