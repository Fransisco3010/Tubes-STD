#ifndef HEADER_CHILD_H_INCLUDED
#define HEADER_CHILD_H_INCLUDED

#include <iostream>
#include "Header_Parent.h"

using namespace std;

#define First(L) L.First
#define Next(P) P->Next
#define Info(P) P->Info
#define Parent(P) P->Parent

struct infotypeC{
    string namaJalan;
    string tipeJalan;
};

typedef struct elm_c *addressC;

struct elm_c{
    addressC Next;
    infotypeC Info;
    addressP Parent;
};

struct List_C{
    addressC First;
};

void createList_Child(List_C &L);
addressC alokasi_Child(string dataX, string dataY);
void tambahData_Child(List_C &L, addressC P);
void hapusData_Child(List_C &L, addressC &P, string namaJalan, string tipeJalan);
void printInfo_Child(List_C L);
void printInfo_ChildParent(List_C L);
addressC findElement_NamaJalan(List_C L, string dataX);
addressC findElement_TipeJalan(List_C L, string dataX);
addressC findElement_Child(List_C L, string namaJalan, string tipeJalan);

#endif // HEADER_CHILD_H_INCLUDED
