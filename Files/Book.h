
#ifndef BOOK_H
#define BOOK_H
#include "User.h"
class Book
{
private:
    int id;
    int numRates;
    double sumRates, averageRating;
    string title;
    string isbn;
    string category;
    User *author;
public:
    static int count;
    Book();
    Book(string , string , string);
    Book(const Book& book);
    void setTitle(string );
    string getTitle() const ;
    void setIsbn(string );
    string getIsbn() const;
    int getId() const;
    void setCategory(string );
    string getCategory()const;
    void setAuthor(User & );
    User * getAuthor() const;
    bool rateBook(double );
    double getAverageRating () const;
    bool operator==(const Book&);
    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>( istream &, Book &);
};
#endif
