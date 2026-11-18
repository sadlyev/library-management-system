#include <iostream>
using namespace std;

// just books class
struct Book {
    int book_id;
    string book_name, author_name, book_category;
};

// for displaying data
struct Date {
    int year;
    int month;
    int day;
};

// class for borrowed books
class Borrowed_book {
    int book_id;
    bool is_taken;
    Date return_date;
};

// array for storing borrowed books
Borrowed_book borrowed[50];

// array for showing full list of books
Book library[50] = {
    {1, "Book", "Sadiyev", "Drama"},
    {2, "Book-2", "Yanvarov", "Fantasy"}
};

// to show admin panel
void displayAdminPanel();
// to show student panel
void displayStudentPanel();
// to show books
void showBooks();  
// to delete a book
void deleteBook();

// main panel that gets called up
void displayMainPanel() {

    int command = 0;

    cout << endl << endl << "Admin Module: 1" << endl << "Student Module: 2" <<  endl << "Please Enter Module number: ";
    cin >> command;

    switch (command) {
        case 1: 
        displayAdminPanel();
        break;
        case 2: 
        displayStudentPanel();
        break;
        default : 
        cout  << "command not found" << endl;
        displayMainPanel();
    }

};

void displayAdminPanel(){
    int command;

    cout 
    << endl
    << endl
    << "ADMIN PANEL" << endl << endl
    << "Manage Category: 1" << endl 
    << "Manage Author: 2" << endl 
    << "Manage Books: 3" << endl 
    << "Issue a new Book: 4" << endl 
    << "Update details of a borrower: 5" << endl
    << "Search authors, books, publicants: 6" << endl
    << "View authors, publications, books, requested books, issued books reports: 7" << endl
    << endl
    << "Back: 8" << endl
    << "Please enter command number: ";
    cin >> command;

    switch(command) {
        case 3: 
            deleteBook();
            break;
        case 8: 
            displayMainPanel();
            break;
        default: 
            cout << "uknown command";
            displayAdminPanel();
    }

    // write some with switch

    
};
void displayStudentPanel(){
    int command;

    cout 
    << endl
    << endl
    << "STUDENT PANEL" << endl << endl
    << "View issued book and book return date-time: 1" << endl
    << "View all books: 2"  << endl
    << endl
    << "Back: 3" << endl
    << "Please enter command number: ";
    cin >> command;

    switch(command) {
        case 2: 
            showBooks();
            break;
        case 3: 
            displayMainPanel();
            break;
        default: 
            cout << "command not found";
            displayStudentPanel();
    }
};

void showBooks() {
    for (int i = 0; i < 50; i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " " << library[i].book_name << " " << library[i].author_name << endl;
        } 
    }

    displayStudentPanel();
}

void deleteBook() {
    int id;

    cout << endl << endl
    << "Please Enter Book ID: ";
    cin >> id;

    for ( int i = 0; i < 50; i++) {
        if (library[i].book_id == id) {
            library[i].book_id = 0;
            cout << "Book was successfuly removed" << endl;
            break;
        }
    }

    for (int i = 0; i < 50; i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " " << library[i].book_name << " " << library[i].author_name << endl;
        } 
    }

    displayAdminPanel();

}

int main() {

    displayMainPanel();

    return 0;
}