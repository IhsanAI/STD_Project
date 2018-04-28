#ifndef CHILDDATA_H_INCLUDED
#define CHILDDATA_H_INCLUDED

using namespace std;

struct book{
    int Book_id;
    string Book_author;
    string Book;
};

book create_data_book();
void view_data_Book(book d);
void edit_data_book(book &d);


#endif // CHILDDATA_H_INCLUDED
