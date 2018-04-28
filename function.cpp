#include "function.h"

int CountGenre(ListParent ListGenre){
    addressParent P;
    P = first(ListGenre);
    int c = 1;
    while(next(P) != first(ListGenre)){
        P = next(P);
        c++;
    }
    return c;
};
int CountBook(ListChild ListBook){
    addressChild P;
    P = first(ListBook);
    int c = 1;
    while(P != last(ListBook)){
        P = next(P);
        c++;
    }
    return c;
};
