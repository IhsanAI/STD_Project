#ifndef PARENTLIST_H_INCLUDED
#define PARENTLIST_H_INCLUDED

#include <iostream>
#include "parentData.h"

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef struct elmlistParent *addressParent;

struct elmlistParent{
    genre info;
    addressParent next;
};

struct ListParent{
    addressParent first;
};

void createListGenre(ListParent &L);
addressParent allocateGenre(genre x);
void deallocateGenre(addressParent &P);

// define insert and delete procedure
void insertFirstGenre(ListParent &L, addressParent P);
void insertLastGenre(ListParent &L, addressParent P);
void insertAfterGenre(ListParent &L, addressParent Prec, addressParent P);
void deleteFirstGenre(ListParent &L, addressParent &P);
void deleteLastGenre(ListParent &L, addressParent &P);
void deleteAfterGenre(ListParent &L, addressParent Prec, addressParent &P);
void deleteByIDGenre(ListParent &L, addressParent &P);

// define search-by-ID function and view procedure
addressParent findElmGenre(ListParent L, genre x);
void printInfoGenre(ListParent L);
addressParent findIdGenre(ListParent L, int x);

#endif // PARENTLIST_H_INCLUDED
