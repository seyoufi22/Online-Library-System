#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
#include <limits>

// Helper function for input validation
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Helper function for getting valid integer input
int getValidIntInput(int min, int max) {
    int input;
    while (!(cin >> input) || input < min || input > max) {
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        clearInputBuffer();
    }
    return input;
}

// Helper function for getting valid double input
double getValidDoubleInput(double min, double max) {
    double input;
    while (!(cin >> input) || input < min || input > max) {
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        clearInputBuffer();
    }
    return input;
}

void main_menu(){
   cout <<"Select one of the following choices : " <<endl;
   cout<<"1- Books Menu"<<endl;
   cout<<"2- Users Menu"<<endl;
   cout<<"3- Exit "<<endl;
}
void user_menu(){
              cout<<" USERS MENU"<<endl;
              cout<<"1- Create a USER and add it to the list "<<endl;
              cout<<"2- Search for a user " <<endl;
              cout<<"3- Display all users "<<endl;
              cout<<"4- Back to the main "<<endl;
}
void search_user_menu(){
            cout<<"SEARCH FOR A USER"<<endl;
            cout<<"1- Search by name"<<endl;
            cout<<"2- Search by id"<<endl;
            cout<<"3- Return to users Menu"<<endl;
}
void delete_user_menu(){
cout<<"1- Delete user "<<endl;
cout<<"2- Return to users Menu"<<endl;
}
void book_menu(){
cout<<"BOOKS MENU"<<endl;
cout<<"1- Create a book and add it to the list "<<endl;
cout<<"2- Search for a book"<<endl;
cout<<"3- Display all books (with book rating)"<<endl;
cout<<"4- Get the highest rating"<<endl;
cout<<"5- Get all books of a user "<<endl;
cout<<"6- Back to the main menu"<<endl;
}
void search_book_menu(){
            cout<<"SEARCH FOR A BOOK"<<endl;
            cout<<"1- Search by name"<<endl;
            cout<<"2- Search by id"<<endl;
            cout<<"3- Return to Books Menu"<<endl;
}
void search_book_name()
{
    cout<<"1- Update author"<<endl;
    cout<<"2- Update name"<<endl;
    cout<<"3- Update Category"<<endl;
    cout<<"4- Delete Book"<<endl;
    cout<<"5- rate book"<<endl;
    cout<<"6- Get back to books menu"<<endl;
}
int main()
{
    bool b1 = true, b2 = true, b3 = true, b4 = true, b5 = true;
    bool b6 = true, b7 = true, b8 = true, b9 = true;
    int choice1, choice2, choice3, choice4, choice5;
    int choice6, choice7, choice8, choice9;
    UserList* U = nullptr;
    BookList* B = nullptr;

    try {
        while (b1) {
            main_menu();
            choice1 = getValidIntInput(1, 3);
            
            switch (choice1) {
            case 1: {
                if (!B) {
                    cout << "How many books will be added? ";
                    int NumberOfBooks = getValidIntInput(1, 1000); // Reasonable limit
                    try {
                        B = new BookList(NumberOfBooks);
                    } catch (const bad_alloc& e) {
                        cout << "Memory allocation failed. Please try again with a smaller number." << endl;
                        continue;
                    }
                }
                
                b6 = true;
                while (b6) {
                    book_menu();
                    choice6 = getValidIntInput(1, 6);
                    
                    switch (choice6) {
                    case 1: {
                        Book b1;
                        try {
                            cin >> b1;
                        } catch (const exception& e) {
                            cout << "Error reading book data: " << e.what() << endl;
                            clearInputBuffer();
                            continue;
                        }
                        
                        b8 = true;
                        while (b8) {
                            cout << "1- Assign Author" << endl;
                            cout << "2- Continue" << endl;
                            choice8 = getValidIntInput(1, 2);
                            
                            switch (choice8) {
                            case 1: {
                                if (!U) {
                                    cout << "Please initialize users first!" << endl;
                                    b8 = false;
                                    break;
                                }
                                cout << "Enter author (user) id: ";
                                int id = getValidIntInput(1, INT_MAX);
                                User* u4 = U->searchUser(id);
                                if (u4 == nullptr) {
                                    cout << "No Author Found with id = " << id << endl;
                                } else {
                                    b1.setAuthor(*u4);
                                    B->addBook(b1);
                                    b8 = false;
                                }
                                break;
                            }
                            case 2:
                                B->addBook(b1);
                                b8 = false;
                                break;
                            }
                        }
                        break;
                    }
                    case 2: {
                        b7 = true;
                        while (b7) {
                            search_book_menu();
                            choice7 = getValidIntInput(1, 3);
                            
                            switch (choice7) {
                            case 1: {
                                string ss;
                                cout << "Enter Name: ";
                                cin >> ss;
                                Book* b2 = B->searchBook(ss);
                                if (b2 == nullptr) {
                                    cout << "Name Not Found" << endl;
                                    b9 = false;
                                } else {
                                    b9 = true;
                                    cout << *b2;
                                    while (b9) {
                                        search_book_name();
                                        choice9 = getValidIntInput(1, 6);
                                        
                                        switch (choice9) {
                                        case 1: {
                                            if (!U) {
                                                cout << "Please initialize users first!" << endl;
                                                b9 = false;
                                                break;
                                            }
                                            cout << "Enter author (user) id: ";
                                            int id = getValidIntInput(1, INT_MAX);
                                            User* uu = U->searchUser(id);
                                            if (uu == nullptr) {
                                                cout << "No Author Found with id = " << id << endl;
                                            } else {
                                                Book* bb = B->searchBook(ss);
                                                bb->setAuthor(*uu);
                                                b2 = bb;
                                            }
                                            break;
                                        }
                                        case 2: {
                                            cout << "Enter new name: ";
                                            string str;
                                            cin >> str;
                                            Book* b5 = B->searchBook(ss);
                                            b5->setTitle(str);
                                            b2 = b5;
                                            break;
                                        }
                                        case 3: {
                                            cout << "Enter new Category: ";
                                            string str;
                                            cin >> str;
                                            Book* b4 = B->searchBook(ss);
                                            b4->setCategory(str);
                                            b2 = b4;
                                            break;
                                        }
                                        case 4: {
                                            B->deleteBook(b2->getId());
                                            b9 = false;
                                            break;
                                        }
                                        case 5: {
                                            cout << "Enter Rating value (0-5): ";
                                            double rate_value = getValidDoubleInput(0, 5);
                                            Book* b3 = B->searchBook(ss);
                                            b3->rateBook(rate_value);
                                            b2 = b3;
                                            break;
                                        }
                                        case 6:
                                            b9 = false;
                                            break;
                                        }
                                    }
                                }
                                break;
                            }
                            case 2: {
                                cout << "Enter ID: ";
                                int ID = getValidIntInput(1, INT_MAX);
                                Book* b3 = B->searchBook(ID);
                                if (b3 == nullptr) {
                                    cout << "ID Not Found" << endl;
                                } else {
                                    cout << *b3;
                                }
                                break;
                            }
                            case 3:
                                b7 = false;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                        cout << *B;
                        break;
                    case 4: {
                        Book b4 = B->getTheHighestRatedBook();
                        cout << b4;
                        break;
                    }
                    case 5: {
                        if (!U) {
                            cout << "Please initialize users first!" << endl;
                            break;
                        }
                        cout << "Enter ID: ";
                        int ID = getValidIntInput(1, INT_MAX);
                        User* u5 = U->searchUser(ID);
                        if (u5 == nullptr) {
                            cout << "No Author Found with id = " << ID << endl;
                        } else {
                            B->getBooksForUser(*u5);
                        }
                        break;
                    }
                    case 6:
                        b6 = false;
                        break;
                    }
                }
                break;
            }
            case 2: {
                if (!U) {
                    cout << "How many users will be added? ";
                    int NumberOfUsers = getValidIntInput(1, 1000); // Reasonable limit
                    try {
                        U = new UserList(NumberOfUsers);
                    } catch (const bad_alloc& e) {
                        cout << "Memory allocation failed. Please try again with a smaller number." << endl;
                        continue;
                    }
                }
                
                b2 = true;
                while (b2) {
                    user_menu();
                    choice2 = getValidIntInput(1, 4);
                    
                    switch (choice2) {
                    case 1: {
                        User u1;
                        try {
                            cin >> u1;
                        } catch (const exception& e) {
                            cout << "Error reading user data: " << e.what() << endl;
                            clearInputBuffer();
                            continue;
                        }
                        U->addUser(u1);
                        break;
                    }
                    case 2: {
                        b3 = true;
                        while (b3) {
                            search_user_menu();
                            choice3 = getValidIntInput(1, 3);
                            
                            switch (choice3) {
                            case 1: {
                                string s;
                                cout << "Enter Name: ";
                                cin >> s;
                                User* u2 = U->searchUser(s);
                                if (u2 == nullptr) {
                                    cout << "Name Not Found" << endl;
                                    b3 = false;
                                    b4 = false;
                                } else {
                                    cout << *u2 << endl;
                                    while (b4) {
                                        delete_user_menu();
                                        choice4 = getValidIntInput(1, 2);
                                        
                                        switch (choice4) {
                                        case 1:
                                            U->deleteUser(u2->GetId());
                                            b4 = false;
                                            break;
                                        case 2:
                                            b4 = false;
                                            break;
                                        }
                                    }
                                }
                                b4 = true;
                                break;
                            }
                            case 2: {
                                cout << "Enter ID: ";
                                int id = getValidIntInput(1, INT_MAX);
                                User* u3 = U->searchUser(id);
                                if (u3 == nullptr) {
                                    cout << "ID Not Found" << endl;
                                    b4 = false;
                                    b5 = false;
                                } else {
                                    cout << *u3;
                                    while (b5) {
                                        delete_user_menu();
                                        choice5 = getValidIntInput(1, 2);
                                        
                                        switch (choice5) {
                                        case 1:
                                            U->deleteUser(u3->GetId());
                                            b5 = false;
                                            break;
                                        case 2:
                                            b5 = false;
                                            break;
                                        }
                                    }
                                }
                                b5 = true;
                                break;
                            }
                            case 3:
                                b3 = false;
                                break;
                            }
                        }
                        break;
                    }
                    case 3:
                        cout << *U;
                        break;
                    case 4:
                        b2 = false;
                        break;
                    }
                }
                break;
            }
            case 3:
                b1 = false;
                break;
            }
        }
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    }

    // Cleanup
    delete U;
    delete B;
    return 0;
}