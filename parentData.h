#ifndef PARENTDATA_H_INCLUDED
#define PARENTDATA_H_INCLUDED
#include <iostream>
using namespace std;

struct genre{
    int Genre_id;
    string Genre;

};

genre create_data_genre();
void view_data_genre(genre d);
void edit_data_genre(genre &d);

#endif // PARENTDATA_H_INCLUDED
