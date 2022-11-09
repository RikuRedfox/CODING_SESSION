#include <iostream>
using namespace std;

class Book {

    public:
        string title;
        string author;
        int pages;

};

int main () {

    Book book1;
    book1.title = "Harry Potter";
    book1.author = "Unknown Author";
    book1.pages = 200;

    Book book2;
    book2.title = "Lord of the Rings";
    book2.author = "Unknown Author";
    book2.pages = 749;

    cout << book1.title;

    return 0;
}