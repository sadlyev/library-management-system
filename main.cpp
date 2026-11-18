#include <iostream>
using namespace std;

class Book {
        public: 
        int book_id;
        string book_name, author_name;
};

Book library[50] = {{1, "Asilbek", "sadiyev"}};

int main() {

    int command = 0;

    cout << "Admin Module: 1" << endl << "Student Module: 2" <<  endl << "Please Enter Module number to continue: ";
    cin >> command;

    switch (command) {
        case 1: 
        cout  << "You are in Admin module" << endl;
        break;
        case 2: 
        cout << "You are in Student module" << endl;
        break;
        default : 
        cout  << "command not found";
    }

return 0;
}