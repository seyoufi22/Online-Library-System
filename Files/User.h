#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
using namespace std;

class User{
private:
    string name;
    int age;
    int id;
    string password;
    string email;
public:
    static int count_id;
    User();
    User(string ,int ,string ,string );
    User(const User& );
    bool operator==(const User&  );
    void SetName(string );
    string GetName() const;
    void SetPassword(string );
    string GetPassword()const;
    void SetEmail(string );
    string GetEmail()const ;
    void SetAge(int );
    int GetAge() const;
    int GetId() const;
    void Display ();
    friend ostream &operator<<(ostream &, const User &);
    friend istream &operator>>( istream & , User &);
};
#endif //USER_H
