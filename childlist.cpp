#include "childlist.h"
#include "childData.h"

//this section of childlist.cpp is done by Ihsan

void createListBook(ListChild &L){
    first(L) = NULL;
    last(L)  = NULL;
}

addressChild allocateBook(book x){
    addressChild P;
    P = new elmlistChild;
    info(P) = x;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}

void deallocateBook(addressChild &P){
    delete P;
}

void insertFirstBook(ListChild &L, addressChild P){
    if((first(L) == NULL) && (last(L) == NULL)){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastBook(ListChild &L, addressChild P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstBook(L,P);
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfterBook(ListChild &L, addressChild Prec, addressChild P){
    if((first(L) == NULL) && (last(L) == NULL)){
        insertFirstBook(L,P);
    }
    else{
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}

void deleteFirstBook(ListChild &L, addressChild &P){
    if(first(L) != NULL){
        P = first(L);
        if(first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void deleteLastBook(ListChild &L, addressChild &P){
    if(last(L) != NULL){
        P = last(L);
        if(first(L) == last(L)){
            deleteFirstBook(L,P);
        }
        else{
            last(L) = prev(P);
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfterBook(ListChild &L, addressChild Prec, addressChild &P){
    if((Prec != NULL) && next(Prec) != NULL){
        P = next(Prec);
        next(Prec) = next(P);
        prev(next(P)) = Prec;
        next(P) = NULL;
        prev(P) = NULL;
    }
}

void deleteByIDBook(ListChild &L, addressChild &P){
    if(P == first(L)){
        deleteFirstBook(L,P);
    }
    else if(P == last(L)){
        deleteLastBook(L,P);
    }
    else{
        addressChild Q = prev(P);
        deleteAfterBook(L,Q,P);
    }
}
// find elm done by Alifiando
addressChild findElmBook(ListChild L, book x){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressChild P = first(L);
        while(P != NULL){
            if(info(P).Book_id == x.Book_id){
                return P;
            }
            P = next(P);
        }
    }
    else{
        return NULL;
    }
}

addressChild findIdBook(ListChild L, int x){
    if(first(L) != NULL){
        addressChild P = first(L);
        while(P != NULL && x != info(P).Book_id);
        {
            P = next(P);
        }
        if(info(P).Book_id == x){
                return P;
        }
        else{
        return NULL;
        }
    }
    else{
        return NULL;
    }
}

void printInfoBook(ListChild L){
    if((first(L) != NULL) && (last(L) != NULL)){
        addressChild P = first(L);
        while(P != NULL){
            view_data_Book(info(P));
            cout<<endl;
            P = next(P);
        }
    }
}
