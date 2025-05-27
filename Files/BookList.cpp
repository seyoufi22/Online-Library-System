#include "BookList.h"

BookList::BookList() {
    capacity = 10;
    books = new Book[capacity];
    booksCount = 0;
}

BookList::BookList(int capacity) {
    this->capacity = capacity;
    books = new Book[capacity];
    booksCount = 0;
}

void BookList::addBook(const Book& book) {
    if (booksCount < capacity) {
        books[booksCount] = book;
        booksCount++;
    } else {
        // Create a new array with double capacity
        capacity *= 2;
        Book* newBooks = new Book[capacity];
        
        // Copy existing books
        for (int i = 0; i < booksCount; i++) {
            newBooks[i] = books[i];
        }
        
        // Add new book
        newBooks[booksCount] = book;
        booksCount++;
        
        // Delete old array and update pointer
        delete[] books;
        books = newBooks;
    }
}

Book* BookList::searchBook(string name) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getTitle() == name) {
            return &books[i];
        }
    }
    return nullptr;
}

Book* BookList::searchBook(int id) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            return &books[i];
        }
    }
    return nullptr;
}

void BookList::deleteBook(int id) {
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getId() == id) {
            // Shift all elements after the deleted book
            for (int j = i; j < booksCount - 1; j++) {
                books[j] = books[j + 1];
            }
            booksCount--;
            break;
        }
    }
}

Book BookList::getTheHighestRatedBook() {
    if (booksCount == 0) {
        return Book(); // Return empty book if list is empty
    }

    Book highestRated = books[0];
    for (int i = 1; i < booksCount; i++) {
        if (books[i].getAverageRating() > highestRated.getAverageRating()) {
            highestRated = books[i];
        }
    }
    return highestRated;
}

void BookList::getBooksForUser(const User& user) {
    bool found = false;
    for (int i = 0; i < booksCount; i++) {
        if (books[i].getAuthor() == &user) {
            cout << books[i] << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for this author." << endl;
    }
}

Book& BookList::operator[](int position) {
    if (position >= 0 && position < booksCount) {
        return books[position];
    }
    throw out_of_range("Invalid book position");
}

ostream& operator<<(ostream& output, const BookList& bookList) {
    for (int i = 0; i < bookList.booksCount; i++) {
        output << bookList.books[i] << endl;
    }
    return output;
}

BookList::~BookList() {
    delete[] books;
} 