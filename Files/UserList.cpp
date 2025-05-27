#include "UserList.h"

UserList::UserList() {
    capacity = 10;
    users = new User[capacity];
    usersCount = 0;
}

UserList::UserList(int capacity) {
    this->capacity = capacity;
    users = new User[capacity];
    usersCount = 0;
}

void UserList::addUser(User& user) {
    if (usersCount < capacity) {
        users[usersCount] = user;
        usersCount++;
    } else {
        // Create a new array with double capacity
        capacity *= 2;
        User* newUsers = new User[capacity];
        
        // Copy existing users
        for (int i = 0; i < usersCount; i++) {
            newUsers[i] = users[i];
        }
        
        // Add new user
        newUsers[usersCount] = user;
        usersCount++;
        
        // Delete old array and update pointer
        delete[] users;
        users = newUsers;
    }
}

User* UserList::searchUser(string name) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].GetName() == name) {
            return &users[i];
        }
    }
    return nullptr;
}

User* UserList::searchUser(int id) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].GetId() == id) {
            return &users[i];
        }
    }
    return nullptr;
}

void UserList::deleteUser(int id) {
    for (int i = 0; i < usersCount; i++) {
        if (users[i].GetId() == id) {
            // Shift all elements after the deleted user
            for (int j = i; j < usersCount - 1; j++) {
                users[j] = users[j + 1];
            }
            usersCount--;
            break;
        }
    }
}

ostream& operator<<(ostream& output, const UserList& userList) {
    for (int i = 0; i < userList.usersCount; i++) {
        output << userList.users[i] << endl;
    }
    return output;
}

UserList::~UserList() {
    delete[] users;
} 