#ifndef CHILDLIST_H_INCLUDED
#define CHILDLIST_H_INCLUDED

#include <iostream>
#include "childData.h"

#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmlistChild *addressChild;

struct elmlistChild{
    book info;
    addressChild next;
    addressChild prev;
};

struct ListChild{
    addressChild first;
    addressChild last;
};

void createListBook(ListChild &L);
addressChild allocateBook(book x);
void deallocateBook(addressChild &P);

// define insert and delete procedure
void insertFirstBook(ListChild &L, addressChild P);
void insertLastBook(ListChild &L, addressChild P);
void insertAfterBook(ListChild &L, addressChild Prec, addressChild P);
void deleteFirstBook(ListChild &L, addressChild &P);
void deleteLastBook(ListChild &L, addressChild &P);
void deleteAfterBook(ListChild &L, addressChild Prec, addressChild &P);
void deleteByIDBook(ListChild &L, addressChild &P);
// define search-by-ID function and view procedure
addressChild findElmBook(ListChild L, book x);
addressChild findIdBook(ListChild L, int x);
void printInfoBook(ListChild L);


#endif // CHILDLIST_H_INCLUDED
