#include "parentData.h"

genre create_data_genre(){
    genre d;
    cout<<"  ID Genre    : ";
    cin>>d.Genre_id;
    cout<<"  Book Genre  : ";
    cin.ignore();
    getline(cin, d.Genre);
    return d;
}

void view_data_genre(genre d){
    cout<<"  Book Genre  : "<<d.Genre<<endl;
    cout<<"  ID Genre    : "<<d.Genre_id<<endl;
}

void edit_data_genre(genre &d){
    cout<<"  Book Genre     : ";
    cin.ignore();
    getline(cin, d.Genre);
}
