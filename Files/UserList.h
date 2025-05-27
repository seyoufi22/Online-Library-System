#ifndef USERLIST_H
#define USERLIST_H

#include "User.h"

class UserList {
private:
    User* users;
    int capacity;
    int usersCount;

public:
    UserList();
    UserList(int capacity);
    void addUser(User& user);
    User* searchUser(string name);
    User* searchUser(int id);
    void deleteUser(int id);
    friend ostream& operator<<(ostream& output, const UserList& userList);
    ~UserList();
};

#endif // USERLIST_H 