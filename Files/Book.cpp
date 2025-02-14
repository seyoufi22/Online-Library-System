#include "Book.h"

int Book::count = 1;

Book::Book() {
    title = isbn = category = "";
    id = count++;
    numRates = 0;
    averageRating = sumRates = 0.0;
    author = new User;
}

Book::Book(string title, string isbn, string category) {
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    numRates = 0;
    averageRating = sumRates = 0.0;
}

Book::Book(const Book &book) {
    title = book.title;
    isbn = book.isbn;
    id = book.id;
    category = book.category;
    author = book.author;
    averageRating = book.averageRating;
}

void Book::setTitle(string title) {
    this->title = title;
}

string Book::getTitle() const {
    return title;
}

void Book::setIsbn(string isbn) {
    this->isbn = isbn;
}

string Book::getIsbn() const {
    return isbn;
}

int Book::getId()const {
    return id;
}

void Book::setCategory(string category) {
    this->category = category;
}

string Book::getCategory() const {
    return category;
}

void Book::setAuthor(User &author) {
    this->author = &author;
}

User * Book::getAuthor() const {
    return author;
}

double Book::getAverageRating() const {
    return averageRating;
}

bool Book::rateBook(double rating) {
    if (rating > 5) {
        cout << "Please Enter rate from 1 to 5\n";
        return false;
    }
    numRates++;
    sumRates += rating;
    averageRating = sumRates / numRates;
    return true;
}

bool Book::operator==(const Book &book) {
    return (title == book.title && isbn == book.isbn && id == book.id && category == book.category && averageRating == book.averageRating && author == book.author);
}

istream & operator>>(istream & input, Book & book) {
    cout << "Enter the book information in this order\n";
    cout << "Title isbn categora (space separated)\n";
    input >> book.title >> book.isbn >> book.category;
    return input;
}

ostream &operator<<(ostream & output, const Book & book) {
    output << "===========Book " << book.id << " Info===========\n";
    output << "Title : " << book.title << "\n";
    output << "Isbn : " << book.isbn << '\n';
    output << "Id : " << book.id << "\n";
    output << "Category : " << book.category << '\n';
    output << "Avg rating : " << book.averageRating << '\n';
    if (book.author.GetName() != "") {
        cout << book.author;
    }
    output << "=================================================\n";
    return output;
}
