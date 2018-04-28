#include <iostream>
#include "childData.h"

using namespace std;
book create_data_book(){
    book d;
    cout<<"  ID Book        : ";
    cin>>d.Book_id;
    cout<<"  Book Title     : ";
    cin.ignore();
    getline(cin, d.Book);
    cout<<"  Book Author    : ";
    getline(cin, d.Book_author);
    return d;
}

void view_data_Book(book d){
    cout<<"  ID Book           : "<<d.Book_id<<endl;
    cout<<"  Book Title        : "<<d.Book<<endl;
    cout<<"  Book Author       : "<<d.Book_author<<endl;
}

void edit_data_book(book &d){
    cout<<"  Book Title     : ";
    cin.ignore();
    getline(cin, d.Book);
    cout<<"  Book Author    : ";
    getline(cin, d.Book_author);
}
