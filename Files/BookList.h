#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"

class BookList {
private:
    Book* books;
    int capacity;
    int booksCount;

public:
    BookList();
    BookList(int capacity);
    void addBook(const Book& book);
    Book* searchBook(string name);
    Book* searchBook(int id);
    void deleteBook(int id);
    Book getTheHighestRatedBook();
    void getBooksForUser(const User& user);
    Book& operator[](int position);
    friend ostream& operator<<(ostream& output, const BookList& bookList);
    ~BookList();
};

#endif // BOOKLIST_H 