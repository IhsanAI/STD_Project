#include "parentlist.h"
#include "parentData.h"

//this parentlist.cpp is done by Alifiando

void createListGenre(ListParent &L){
    first(L) = NULL;
}

addressParent allocateGenre(genre x){
    addressParent P;
    P = new elmlistParent;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void deallocateGenre(addressParent &P){
    delete P;
}

void insertFirstGenre(ListParent &L, addressParent P){
    if(first(L) == NULL){
        first(L) = P;
        next(P) = P;
    }
    else{
        addressParent Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLastGenre(ListParent &L, addressParent P){
    if(first(L) == NULL){
        insertFirstGenre(L,P);
    }
    else{
        addressParent Q = first(L);
        while(next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void insertAfterGenre(ListParent &L, addressParent Prec, addressParent P){
    if((Prec != NULL) && (first(L) != NULL)){
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstGenre(ListParent &L, addressParent &P){
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            first(L) = NULL;
        }
        else{
            addressParent Q = first(L);
            while(next(Q) != first(L)){
                Q = next(Q);
            }
            first(L) = next(P);
            next(Q) = first(L);
        }
    }
}

void deleteLastGenre(ListParent &L, addressParent &P){
    P = first(L);
    if(P != NULL){
        if(next(P) == P){
            deleteFirstGenre(L,P);
        }
        else{
            addressParent Q = first(L);
            while(next(next(Q)) != first(L)){
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = first(L);
        }
    }
}

void deleteAfterGenre(ListParent &L, addressParent Prec, addressParent &P){
    if((Prec != NULL) && (first(L) != NULL)){
        P = next(Prec);
        next(Prec) = next(P);
    }
}

void deleteByIDGenre(ListParent &L, addressParent &P){
    if(P == first(L)){
        deleteFirstGenre(L,P);
    }
    else if(next(P) == first(L)){
        deleteLastGenre(L,P);
    }
    else{
        addressParent Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        deleteAfterGenre(L,Q,P);
    }
}

addressParent findElmGenre(ListParent L, genre x){
    if(first(L) != NULL){
        addressParent P = first(L);
        do{
            P = next(P);
          }
        while(P != first(L));
        if(info(P).Genre_id == x.Genre_id){
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

addressParent findIdGenre(ListParent L, int x){
    if(first(L) != NULL){
        addressParent P = first(L);
        do{
            P = next(P);
          }
        while(P != first(L) && x != info(P).Genre_id);
        if(info(P).Genre_id == x){
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

void printInfoGenre(ListParent L){
    if(first(L) != NULL){
        addressParent P = first(L);
        do{
            view_data_genre(info(P));
            cout<<endl;
            P = next(P);
        }while(P != first(L));
    }
}
