#include "User.h"
#include "Book.h"

int main() {
    Book b;
    User s;
    s.SetName("Ahmed");
    b.setAuthor(s);
    cout << b;
    return 0;
}
