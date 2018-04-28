#include <iostream>
#include <cstdlib>
#include "parentlist.h"
#include "childlist.h"
#include "relationlist.h"

using namespace std;

int main()
{
    ListParent ListGenre;
    ListChild ListBook;
    ListRelation ListRelasi;

    book b;
    genre g;

    addressParent aP;
    addressChild aC;
    addressRelation aR;

    int menu;

    createListGenre(ListGenre);
    createListBook(ListBook);
    createListRelation(ListRelasi);

    g.Genre_id = 100;
    g.Genre = "Sci-Fi";
    aP = allocateGenre(g);
    insertLastGenre(ListGenre,aP);
    b.Book_id = 1;
    b.Book = "Star Wars";
    b.Book_author = "George Lucas";
    aC = allocateBook(b);
    insertLastBook(ListBook,aC);
    g.Genre_id = 1;
    g.Genre = "Horror";
    aP = allocateGenre(g);
    insertFirstGenre(ListGenre,aP);
    b.Book_id = 2;
    b.Book = "The Shining";
    b.Book_author = "Stephen King";
    aC = allocateBook(b);
    insertFirstBook(ListBook,aC);

    while(true){
        cout<<endl;
        cout<<"                    STD Project 2018              "<<endl;
        cout<<""<<endl;
        cout<<"   M.Ihsan Amien I.           - 1301153628        "<<endl;
        cout<<"   Alifiando Destara Yusuf    - 1301153621        "<<endl;
        cout<<""<<endl;
        cout<<"   IF-39-INT                       "<<endl;
        cout<<"                   Book Genre & Title                 "<<endl;
        cout<<""<<endl;
        cout<<"  1.  Input Genre"<<endl;
        cout<<"  2.  Input Book Title"<<endl;
        cout<<"  3.  Edit Genre"<<endl;
        cout<<"  4.  Edit Book"<<endl;
        cout<<"  5.  Delete Genre"<<endl;
        cout<<"  6.  Delete Book"<<endl;
        cout<<"  7.  Make Connection Genre and Book"<<endl;
        cout<<"  8.  Break Connection Genre and Book"<<endl;
        cout<<"  9.  Check Connection Genre and Book"<<endl;
        cout<<"  10. List Genre"<<endl;
        cout<<"  11. List Book"<<endl;
        cout<<"  12. List Genre and Book"<<endl;
        cout<<"  13. List Book and Genre"<<endl;
        cout<<"  14. Find Book by ID"<<endl;
        cout<<"  15. Find Genre by ID"<<endl;
        cout<<"  *-------------------------------------------------*  "<<endl;
        cout<<"   0.  Exit Program"<<endl;
        cout<<"  *-------------------------------------------------*  "<<endl;
        cout<<endl;
        cout<<"  Choose Menu (integer): ";
        cin>>menu;
        if(cin.fail()){
            cin.clear();
            cout<<"  Input not integer. Press 'Enter' to continue...";
            cin.sync();
            cin.get();
        }else{
            switch(menu){
                case 0:
                    return 0;
                break;
                case 1:
                    g = create_data_genre();
                    if(findElmGenre(ListGenre,g) == NULL){
                        aP = allocateGenre(g);
                        insertLastGenre(ListGenre, aP);
                        cout<<"  Genre Successfully  inputed! Press 'Enter' to Continue...";
                    }
                    else{
                        cout<<"  ID Duplicate";
                    }
                    cin.sync();
                    cin.get();
                break;
                case 2:
                    b = create_data_book();
                    if(findElmBook(ListBook,b) == NULL){
                        aC = allocateBook(b);
                        insertLastBook(ListBook, aC);
                        cout<<"  Book Successfully  inputed! Press 'Enter' to Continue...";
                    }
                    else{
                        cout<<"  ID Duplicate";
                    }
                    cin.sync();
                    cin.get();
                break;
                case 3:
                    cout<<"  Input Genre ID  : ";
                    cin>>g.Genre_id;
                    aP = findElmGenre(ListGenre,g);
                    if(aP == NULL){
                        cout<<"  ID not found! press 'Enter' to continue...";
                    }
                    else{
                        g = info(aP);
                        edit_data_genre(info(aP));
                        cout<<"  Genre successfully edited! press 'Enter' to continue...";
                    }
                    cin.sync();
                    cin.get();
                break;
                case 4:
                    cout<<"  Input ID Book  : ";
                    cin>>b.Book_id;
                    aC = findElmBook(ListBook,b);
                    if(aC == NULL){
                        cout<<"  ID not found! press 'Enter' to continue...";
                    }
                    else{
                        edit_data_book(info(aC));
                        cout<<"  Book successfully edited! press 'Enter' to continue...";
                    }
                    cin.sync();
                    cin.get();
                break;
                case 5:
                    cout<<"  Input Genre ID: ";
                    cin>>g.Genre_id;
                    aP = findElmGenre(ListGenre,g);
                    if(aP == NULL){
                        cout<<"  ID not found! press 'Enter' to continue...";
                    }
                    else{
                        deleteByIDGenre(ListGenre,aP);
                        cout<<"  Genre of '"<<info(aP).Genre<<"' Delete Success press 'Enter' to continue...";
                        aR = first(ListRelasi);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(parent(aR) == aP){
                                deleteRelation(ListRelasi,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        deallocateGenre(aP);
                    }
                    cin.sync();
                    cin.get();
                break;
                case 6:
                    cout<<"  Input Book ID: ";
                    cin>>b.Book_id;
                    aC = findElmBook(ListBook,b);
                    if(aC == NULL){
                        cout<<"  ID not found! press 'Enter' to continue...";
                    }
                    else{
                        deleteByIDBook(ListBook,aC);
                        cout<<"  Book '"<<info(aC).Book<<"' Delete Success press 'Enter' to continue..";
                        aR = first(ListRelasi);
                        while(aR != NULL){
                            addressRelation aR_temp = NULL;
                            if(child(aR) == aC){
                                deleteRelation(ListRelasi,aR);
                                aR_temp = aR;
                            }
                            aR = next(aR);
                            if(aR_temp != NULL){
                                deallocateRelation(aR_temp);
                            }
                        }
                        deallocateBook(aC);
                    }
                    cin.sync();
                    cin.get();
                break;
                case 7:
                    int ge,bo;
                    cout<<"  Input Genre ID  : ";
                    cin>>g.Genre_id;
                    cout<<"  Input Book ID : ";
                    cin>>b.Book_id;
                    aP = findElmGenre(ListGenre, g);
                    aC = findElmBook(ListBook, b);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(ListRelasi,aP,aC);
                        if(aR == NULL){
                            aR = allocateRelation(aP,aC);
                            insertRelation(ListRelasi, aR);
                        }
                        cout<<"  Genre '"<<info(aP).Genre<<"' is connected to Book '"<<info(aC).Book<<"'.";
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  Book ID and Genre ID not found!";
                    }
                    else if(aC == NULL){
                        cout<<"  Book ID not found!";
                    }
                    else if(aP == NULL){
                        cout<<"  Genre ID not found!";
                    }
                    cout<<" press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                case 8:
                    cout<<"  Input Book ID  : ";
                    cin>>b.Book_id;
                    cout<<"  Input Genre ID : ";
                    cin>>g.Genre_id;
                    aP = findElmGenre(ListGenre, g);
                    aC = findElmBook(ListBook, b);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(ListRelasi,aP,aC);
                        if(aR != NULL){
                            deleteRelation(ListRelasi,aR);
                            cout<<"  Genre relation '"<<info(aP).Genre<<"' with Book '"<<info(aC).Book<<"' has been broken.";
                        }
                        else{
                            cout<<"  Genre relation '"<<info(aP).Genre<<"' with Book '"<<info(aC).Book<<"' has been broken.";
                        }
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  Genre ID and Book ID not found!";
                    }
                    else if(aC == NULL){
                        cout<<"  Book ID not found!";
                    }
                    else if(aP == NULL){
                        cout<<"  Genre ID not found!";
                    }
                    cout<<" press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                case 9:
                    cout<<"  Input Book ID  : ";
                    cin>>b.Book_id;
                    cout<<"  Input Genre ID : ";
                    cin>>g.Genre_id;
                    aP = findElmGenre(ListGenre, g);
                    aC = findElmBook(ListBook, b);
                    if((aC != NULL) && (aP != NULL)){
                        aR = findRelation(ListRelasi,aP,aC);
                        if(aR != NULL){
                            cout<<"  Book '"<<info(aC).Book<<"' is related to '"<<info(aP).Genre<<"' genre.";
                        }
                        else{
                            cout<<"  Book '"<<info(aC).Book<<"' is not related to '"<<info(aP).Genre<<"' genre.";
                        }
                    }
                    else if((aC == NULL) && (aP == NULL)){
                        cout<<"  Genre ID and Book ID not found!";
                    }
                    else if(aC == NULL){
                        cout<<"  Book ID not found!";
                    }
                    else if(aP == NULL){
                        cout<<"  Genre ID not found!";
                    }
                    cout<<" press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                case 10:
                    cout<<endl;
                    cout<<"  ---------------  Genre list  ---------------"<<endl;
                    printInfoGenre(ListGenre);
                    cout<<"  press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                case 11:
                    cout<<endl;
                    cout<<"  ---------------  Book list  ---------------"<<endl;
                    printInfoBook(ListBook);
                    cout<<"  press 'Enter' to continue..";
                    cin.sync();
                    cin.get();

                break;
                case 12:
                    cout<<endl;
                    cout<<"  ----------  Genre and Book list  ----------"<<endl;
                    printGenreandBook(ListGenre, ListRelasi);
                    cout<<"  press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                case 13:
                    cout<<endl;
                    cout<<"  ----------  Book and Genre list  ----------"<<endl;
                    printBookandGenre(ListBook, ListRelasi);
                    cout<<"  press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;
                /*case 14:
                    int i;
                    addressChild b;
                    cout<<endl;
                    cout<<"Book id:    ";
                    cin>>i;
                    b = findElmBook(ListBook,book);
                    cout<<info(b).Book;
                    if (b != NULL)
                    {
                        cout<<endl<<info(b).Book;
                    }
                    else
                    {
                        cout<<"not found";
                    }
                    cout<<"  press 'Enter' to continue..";
                    cin.sync();
                    cin.get();
                break;*/
}
}
}
}

