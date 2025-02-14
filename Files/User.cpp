#include "User.h"

int User::count_id = 0;

User::User(){
    name = "";
    age = 0;
    password = "";
    email = "";
    count_id++;
    id = count_id;
}

bool User::operator==(const User&  user) {
    return name == user.name && age == user.age && password == user.password && email == user.email && id == user.id;
}

User::User(string name, int age, string password, string email){
    this->name = name;
    this->age = age;
    this->password = password;
    this->email = email;
    count_id++;
    id = count_id;
}

User::User(const User & user){
    name = user.name;
    age = user.age;
    password = user.password;
    email = user.email;
    id = user.id;
}

void User::SetName(string name){
    this->name = name;
}

string User::GetName() const{
    return name;
}

void User::SetPassword(string password){
    this->password = password;
}

string User::GetPassword() const{
    return password;
}

void User::SetEmail(string email){
    this->email = email;
}

string User::GetEmail() const{
    return email;
}

void User::SetAge(int age) {
    this->age = age;
}

int User::GetAge() const{
    return age;
}

int User::GetId() const{
    return id;
}

void User::Display() {
    cout << "*******************************\n";
    cout << "Name : " << name << "\n";
    cout << "Age : " << age << '\n';
    cout << "Id : " << id << "\n";
    cout << "Email : " << email << '\n';
    cout << "*******************************\n";
}

istream &operator>>( istream & input, User &user) {
    cout << "Enter your information in this order\n";
    cout << "Name Age Email Password\n";
    cout << "Space Separated\n";
    input >> user.name >> user.age >> user.email >> user.password;
    return input;
}

ostream &operator<<(ostream & output, const User & user) {
    output << "===========User " << user.id << " Info===========\n";
    output << "Name : " << user.name << "\n";
    output << "Age : " << user.age << '\n';
    output << "Id : " << user.id << "\n";
    output << "Email : " << user.email << '\n';
    output << "=================================================\n";
    return output;
}