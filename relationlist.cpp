#include "relationList.h"
#include "childData.h"
#include "parentData.h"

//this section is done by Ihsan

void createListRelation(ListRelation &L){
    first(L) = NULL;
}

addressRelation allocateRelation(addressParent aP, addressChild aC){
    addressRelation P = new elmlistRelation;
    parent(P) = aP;
    child(P)  = aC;
    return P;
}

void deallocateRelation(addressRelation &P){
    delete P;
}

void insertRelation(ListRelation &L, addressRelation P){
    if(first(L) == NULL){
        first(L) = P;
    }
    else{
        next(P) = first(L);
        first(L) = P;
    }
}

void deleteRelation(ListRelation &L, addressRelation &P){
    if(first(L) != NULL){
        if(P == first(L)){
            first(L) = next(first(L));
        }
        addressRelation Q = first(L);
        while(next(Q) != NULL){
            if(next(Q) == P){
                next(Q) = next(P);
                break;
            }
            Q = next(Q);
        }
    }
}

addressRelation findRelation(ListRelation L, addressParent aP, addressChild aC){
    if(first(L) != NULL){
        addressRelation P = first(L);
        while((P != NULL) && ((parent(P) == aP) && (child(P) == aC))){
            P = next(P);
        }
        if((parent(P) == aP) && (child(P) == aC)){
            return P;
        }
        else
        {
            return NULL;
        }
        }
    }

//starting from this section is done by Alifiando

void printGenreandBook(ListParent ListGenre, ListRelation ListRelasi){
    addressParent pGenre = first(ListGenre);
    if(next(pGenre)!=first(ListGenre))
        while(next(pGenre) != first(ListGenre)){
            int i;
            i=0;
            view_data_genre(info(pGenre));
            addressRelation pRelasi = first(ListRelasi);
            cout<<"Books with mentioned genre:     ";
            do {
                cout<<info(child(pRelasi)).Book<<", ";
                i++;
                pRelasi = next(pRelasi);
            } while(pRelasi != NULL);
            if(i == 0){
                cout<<"<NULL>";
            }
            cout<<endl<<endl;
            pGenre = next(pGenre);
        }
    else
    {
        int i;
        i=0;
        view_data_genre(info(pGenre));
        addressRelation pRelasi = first(ListRelasi);
        cout<<"Books with mentioned genre:     ";
        do {
            cout<<info(child(pRelasi)).Book<<", ";
            i++;
            pRelasi = next(pRelasi);
        } while(pRelasi != NULL);
        if(i == 0){
            cout<<"<NULL>";
        }
    }
}



void printBookandGenre(ListChild ListBook, ListRelation ListRelasi){
    addressChild pBook = first(ListBook);
    if(next(pBook)!=first(ListBook))
        while(pBook != NULL){
            int i;
            i=0;
            view_data_Book(info(pBook));
            addressRelation pRelasi = first(ListRelasi);
            cout<<"Genre of book:     ";
            if(pRelasi == NULL){
                cout<<"<NULL>";
            }
            else
            {
                cout<<info(parent(pRelasi)).Genre;
            }
            cout<<endl<<endl;
            pBook = next(pBook);
        }
    else
    {
        int i;
        i=0;
        view_data_Book(info(pBook));
        addressRelation pRelasi = first(ListRelasi);
        cout<<"Books with mentioned genre:     ";
        do {
            cout<<info(parent(pRelasi)).Genre<<", ";
            i++;
            pRelasi = next(pRelasi);
        } while(pRelasi != first((ListRelasi)));
        if(i == 0){
            cout<<"<NULL>";
        }
    }
}


/*void printGenreandBook(ListParent ListGenre, ListRelation listRelasi){
    addressParent pGenre = first(ListGenre);
    while(pGenre != NULL){
        view_data_genre(info(pGenre));
        bool exist = false;
        addressRelation pRelasi = first(listRelasi);
        cout<<"  Book Genre     : ";
        while(pRelasi != NULL){
            if(parent(pRelasi) == pGenre){
                exist = true;
                cout<<info(child(pRelasi)).Book<<", ";
            }
            pRelasi = next(pRelasi);
        }
        if(exist == false){
            cout<<"<Empty>";
        }
        cout<<endl<<endl;
        pGenre = next(pGenre);
    }
}*/

/*void printBookandGenre(ListChild ListBook, ListRelation listRelasi){
    addressChild pBook = first(ListBook);
    do{
        view_data_genre(info(pBook));
        bool exist = false;
        addressRelation pRelasi = first(listRelasi);
        cout<<"  List Book with Genre "<<info(pBook).Genre<<endl;
        while(pRelasi != NULL){
            if(child(pRelasi) == pBook){
                exist = true;
                cout<<"  -> "<<info(child(pRelasi)).Book<<" - "<<info(child(pRelasi)).Book_author<<endl;
            }
            pRelasi = next(pRelasi);
        }
        if(exist == false){
            cout<<"  No Book Registered with the Genre '"<<info(pBook).Genre<<"'"<<endl;
        }
        cout<<endl;
        pBook = next(pBook);
    }while(pBook != first(ListBook));
}*/
