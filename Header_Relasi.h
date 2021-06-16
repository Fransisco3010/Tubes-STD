#ifndef HEADER_ADMIN_H_INCLUDED
#define HEADER_ADMIN_H_INCLUDED

#include "Header_Parent.h"
#include "Header_Child.h"

void connect(addressP P, addressC &C);
void disconnect(addressC &C);
void printRelasi(List_P LP, List_C LC);

#endif // HEADER_ADMIN_H_INCLUDED
