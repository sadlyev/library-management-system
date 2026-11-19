#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Author {
    int author_id;
    string author_name;
    string author_surname;
    vector <int> b;             
};

struct Publicant {
    int publicant_id;
    string publicant_name;  
    string city;
    vector <int> b;              
};

struct Book {
    int book_id;
    string book_name;
    string author_name;     
    string author_surname;  
    string book_category;
    string book_publicant;
    int quantity;
};

struct Date {
    int year;
    int month;
    int day;
};

struct Borrowed_book {
    int book_id;
    string book_name;
    bool is_taken;         
    Date return_date;
};

// Authors
vector <Author> authors = {
    {1, "Rustam",  "Sadiyev",  {1, 6}},
    {2, "Aziz",    "Yanvarov", {2, 7}},
    {3, "Dilnoza", "Karimova", {3, 8}},
    {4, "Jasur",   "Tursunov", {4, 9}},
    {5, "Malika",  "Rahimova", {5, 10}}
};

// Publicants
vector <Publicant> publicants = {
    {1, "Publicant-1", "Tashkent",  {1, 4, 8}},
    {2, "Publicant-2", "Samarkand", {2, 6, 10}},
    {3, "Publicant-3", "Bukhara",   {3, 7}},
    {4, "Publicant-4", "Namangan",  {5, 9}}
};

// Books
vector <Book> library = {
    {1,  "The Silent Stage",    "Rustam",  "Sadiyev",  "Drama",    "Publicant-1", 5},
    {2,  "Dragon of the North", "Aziz",    "Yanvarov", "Fantasy",  "Publicant-2", 3},
    {3,  "Learning C++",        "Dilnoza", "Karimova", "Computer", "Publicant-3", 8},
    {4,  "A Brief History",     "Jasur",   "Tursunov", "History",  "Publicant-1", 4},
    {5,  "Love in Samarkand",   "Malika",  "Rahimova", "Romance",  "Publicant-4", 6},
    {6,  "Curtain Call",        "Rustam",  "Sadiyev",  "Drama",    "Publicant-2", 2},
    {7,  "The Last Sorcerer",   "Aziz",    "Yanvarov", "Fantasy",  "Publicant-3", 7},
    {8,  "Data Structures",     "Dilnoza", "Karimova", "Computer", "Publicant-1", 10},
    {9,  "Silk Road Empires",   "Jasur",   "Tursunov", "History",  "Publicant-4", 3},
    {10, "Letters at Dawn",     "Malika",  "Rahimova", "Romance",  "Publicant-2", 1}
};

// Borrowed books
vector <Borrowed_book> borrowed = {
    {1, "The Silent Stage",  true,  {2026, 11, 25}},
    {3, "Learning C++",      true,  {2026, 11, 15}},  
    {7, "The Last Sorcerer", true,  {2026, 11, 30}},
    {8, "Data Structures",   false, {2026, 11, 10}}   
};

vector <string> category = {
    "Drama",
    "Fantasy",
    "Computer",
    "History",
    "Romance",
    "Science",
    "Mathematics",
    "Biography",
    "Poetry",
    "Mystery",
    "Adventure",
    "Philosophy",
    "Art",
    "Geography",
    "Children"
};



// HELPFUL FUNCTIONS

// helps to turn all characters of string to lowercase
string toLower(); //  done
int readInt(); // done
void saveBooks(); // not done
void saveAuthors(); // not done
void savePublicant(); // not done
void saveBooked(); // not done
void saveCategory(); // not done




// MAIN FUNCTIONS

// to show main panel
void displayMainPanel(); // done
// to show admin panel
void displayAdminPanel(); // done
// to show student panel
void displayStudentPanel(); // done


// ADMIN FUNCTIONS

// to manage categories
void manageCategory(); // done
void editCategory(); // done
void deleteCategory(); // done
void addCategory(); // done
void showCategory(); // done

// to manage authors
void manageAuthors(); // done
void deleteAuthor(); // done
void addAuthor(); // done
void showAuthor(); // done

// to manage books
void manageBooks(); // not done;
void addBook(); // not done;
void editBook(); // not done
void deleteBook(); // done
void showBooks(); // not done

// to manage issusing a book
void issueBook(); // not done

// to manage return of a book
void returnBook(); // no done

// to search by author, book, publicant
void searchByNamePublicantAuthor(); // done 

// to check reports
void manageReports(); // not done
void authorReports(); // not done
void publicationReports(); // not done
void bookReport(); // not done
void requestedBooks(); // not done
void issuesBooks(); // not done




// STUDENT FUNCTIONS

// to show issues books
void studentIssuesBooks(); // not done
// to show books
void showBooks();  // done



// HELPFULL
string toLower(string a) {
    
    for (int i = 0; i < a.length(); i++) {
        a[i] = tolower(a[i]);
    }
    return a;
}

int readInt() {
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();              
            cin.ignore(1000, '\n');    
            cout << "Invalid input, enter a number: ";
        }
        else {
            cin.ignore(1000, '\n');  
            return number;
        }
    }
}






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
        case 1: 
            manageCategory();
            break;
        case 2:
            manageAuthors();
            break;
        case 3: 
            deleteBook();
            break;
        case 6: 
            searchByNamePublicantAuthor();
            break;
        case 8: 
            displayMainPanel();
            break;
        default: 
            cout << "UNKNOWN COMMAND" << endl;
            displayAdminPanel();
    }

    
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

void manageCategory() {
    int command;
    cout 
    << endl << "MANAGE CATEGORY" << endl
    << "Add a new category: 1" << endl
    << "Edit a category: 2" << endl
    << "Delete a category: 3" << endl  
    << "Show all categories: 4" << endl
    << "Back: 5" << endl << endl
    << "Please enter command number: ";
    cin >> command;

    switch(command) {
        case 1: 
           addCategory();
           break;
        case 2:
            editCategory();
            break;
        case 3: 
            deleteCategory();
            break;
        case 4: 
            showCategory();
            break;
        case 5: 
            displayAdminPanel();
            break;
        default: 
            cout << "UNKNOWN COMMAND" << endl;
            manageCategory();
    }
};

void addCategory() {
    string new_category, lowered;
    bool exists = false;

    cout << "Please Enter New Category Name: ";
    cin >> ws;
    getline(cin, new_category);
    lowered = toLower(new_category);

    for (int i = 0; i < category.size() ;i++) {
        if (toLower(category[i]) == lowered) {
            exists = true;
            break;
        }
    }

    if (exists) {
        cout << "Category with this name already exists" << endl;
        manageCategory();
    } else {
        category.push_back(new_category);
        cout << "New Category has been successfully added!" << endl;
        manageCategory();
    }
};

void editCategory() {
    string old_name, new_name;
    bool exists = false;

    cout << "Please enter category name you want to edit: ";
    cin >> ws;
    getline(cin, old_name);
    old_name = toLower(old_name);

    for (int i = 0; i < category.size(); i++) {
        if (toLower(category[i]) == old_name) {
            exists = true;
            break;
        }
    }

    if (exists) {
        cout << "Please enter new name for chosen category: ";
        cin >> ws;
        getline(cin, new_name);

        for (int i = 0; i < category.size();i++) {
            if (toLower(category[i]) == old_name) {
                category[i] = new_name;
                break;
            }
        }

        cout << "Category name have been edited successfuly!" << endl;
        manageCategory();
    } else {
        cout << "Category with this name was not found(";
        manageCategory();
    }

}

void deleteCategory() {
    string category_name;
    bool  exists = false;

    cout << "Please enter category name to delete: ";
    cin >> ws;
    getline(cin, category_name);
    category_name = toLower(category_name);

    for (int i = 0; i < category.size();i++) {
        if (toLower(category[i]) == category_name) {
            category.erase(category.begin() + i);
            cout << "Category have been successfully deleted" << endl;
            exists = true;
            manageCategory();
            break;
            
        } 
    }

    if (!exists) {
        cout << "Category with this name was not found(" << endl;
        manageCategory();
    } 
}

void showCategory() {
    cout << "LIST of CATEGORIES: ";
    for (int i  = 0; i < category.size();i++) {
        cout << category[i] << endl;
    }

    manageCategory();
}


// AUTHOR

void manageAuthors() {
    int command;

    cout << endl
    << "AUTHOR MANAGEMENT" << endl
    << "Delete Author: 1" << endl
    << "Add Author: 2" << endl
    << "Show Authors: 3" << endl
    << "Back: 4" << endl << endl
    << "Please enter command number: " <<  endl;

    cin >> command;

    switch(command) {
        case 1: 
            deleteAuthor();
            break;
        case 2:
            addAuthor();
            break;
        case 3:
            showAuthor();
            break;
        case 4:
            displayAdminPanel();
            break;
        default: 
            cout << "UKNOWN COMMAND" << endl;
            manageAuthors();
    }
}



void deleteAuthor() {
    string name_author;
    bool  exists = false;
    cout << endl << "DELETING AUTHOR" <<  endl
    << "Please enter author name or surname: ";
    cin  >> ws;
    getline(cin, name_author);
    name_author = toLower(name_author);

    for (int i = 0; i < authors.size();i++) {
        if (toLower(authors[i].author_name) == name_author || toLower(authors[i].author_surname) == name_author || ( toLower(authors[i].author_name) + " " + toLower(authors[i].author_surname ) == name_author)) {
            authors.erase(authors.begin() + i);
            cout << "Author have been successfully deleted!" << endl;
            exists = true;
            manageAuthors();
            break;

        }
    }

    if (!exists) {
        cout << "Author with this surname or name was not found(" << endl;
        manageAuthors();
    }
}

void addAuthor() {
    int id;
    string name, surname;
    vector<int> b;

    cout << endl << "ADDING AUTHOR" << endl;

    cout << "Author ID: ";
    id = readInt();

    // reject a duplicate author ID
    for (int i = 0; i < authors.size(); i++) {
        if (authors[i].author_id == id) {
            cout << "An author with this ID already exists." << endl;
            return;
        }
    }

    cout << "First name: ";
    getline(cin, name);

    cout << "Last name: ";
    getline(cin, surname);

    // reject empty names
    if (name.empty() || surname.empty()) {
        cout << "Name and surname cannot be empty." << endl;
        return;
    }

    // read book IDs one at a time, 0 to finish
    int bookId;
    while (true) {
        cout << "Enter book ID (0 to finish): ";
        bookId = readInt();

        if (bookId == 0)
            break;

        // the book must exist
        bool exists = false;
        for (int i = 0; i < library.size(); i++) {
            if (library[i].book_id == bookId) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            cout << "No book with this ID." << endl;
            continue;
        }

        // no duplicates in this author's list
        bool already = false;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == bookId) {
                already = true;
                break;
            }
        }
        if (already) {
            cout << "Book already added." << endl;
            continue;
        }

        b.push_back(bookId);
    }

    Author a;
    a.author_id = id;
    a.author_name = name;
    a.author_surname = surname;
    a.b = b;

    authors.push_back(a);

    cout << "Author added." << endl;
    manageAuthors();
}

void showAuthor() {
    cout << endl <<  "ALL AUTHORS" << endl;

    for (int i = 0; i < authors.size(); i++) {
        cout << endl <<  authors[i].author_id << " | " << authors[i].author_name << " " << authors[i].author_surname << " | " << "Books: " << endl;
         for (int j = 0; j < library.size();j++) {
            for  (int d = 0; d < authors[i].b.size();d++) {
                if (authors[i].b[d] == library[j].book_id) {
                    cout << library[j].book_name << " | " << library[j].book_category << " | " << "Quantity: " << library[j].quantity << endl;
                }
            }
        }
        
    }

    manageAuthors();
}



void showBooks() {
    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " | " << library[i].book_name << " | " << library[i].author_name << " " << library[i].author_surname << endl;
        } 
    }

    displayStudentPanel();
}



void deleteBook() {
    int id;

    cout << endl << endl
    << "Please Enter Book ID: ";
    cin >> id;

    for ( int i = 0; i < library.size(); i++) {
        if (library[i].book_id == id) {
            library[i].book_id = 0;
            cout << "Book was successfuly removed" << endl;
            break;
        } 
    }

    cout << endl << "REMAINING BOOKS: " << endl;
    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " | " << library[i].book_name << " | " << library[i].author_name << endl;
        } 
    }

    displayAdminPanel();

};

void searchByNamePublicantAuthor() {
    string searched;
    bool is_found = false;

    cout << "Enter book, author or publicant name: ";
    cin >> searched;
    searched = toLower(searched);

    for (int i  = 0; i < library.size(); i++) {
        if (library[i].book_id > 0) {
             if (toLower(library[i].author_name).find(searched) != string::npos || toLower(library[i].book_name).find(searched) != string::npos || toLower(library[i].book_publicant).find(searched) != string::npos) {
                is_found = true;
                cout << library[i].book_id << " | " << library[i].author_name << " | " << library[i].book_name << " | " << library[i].book_publicant << endl;  
            }
        }
       
    }

    if (!is_found) {
        cout << "No results matched: " << searched << endl;
    }

    displayAdminPanel();
}






int main() {

    displayMainPanel();

    return 0;
}