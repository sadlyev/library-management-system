#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

class FirstAuthor {
    public :
        int author_id;
};

class Author: public FirstAuthor {
    public: 
        string author_name;
        string author_surname;
        vector <int> b; 
        
        void setName(string name){
            author_name = name;
        }

        void setLastName(string name) {
            author_surname = name;
        }

        void setBook(int a){
            b.push_back(a);
        }
};

struct Publicant {
    int publicant_id;
    string publicant_name;  
    string city;
    vector <int> b;              
};

class Book {
    public:
        int book_id;
        string book_name;
        string author_name;     
        string author_surname;  
        string book_category;
        string book_publicant;
        int quantity;

    void setId(int a){
        this->book_id = a;
    }
    
    void setQuantity(int a) {
        this->quantity = a;
    }

    void setName(string name) {
        this->book_name = name;
    }

    void setAuthorFirstName(string name) {
        this->author_name = name;
    }

    void setAuthorLastName(string name) {
        this->author_surname = name;
    }

    void setCategory(string name)  {
        this->book_category = name;
    }

    void setPublicant(string name)  {
        this->book_publicant = name;
    }
};

class Borrowed_book {
    int book_id;
    bool is_taken;         
    int quantity;
    Date time;

    public :
        Borrowed_book(int id, bool taken, int quan, Date d) {
            this->book_id = id;
            this->is_taken = taken;
            this->quantity = quan;
            this->time.year = d.year;
            this->time.month = d.month;
            this->time.day = d.day;
        }

        int getId() {
            return book_id;
        }

        bool getTaken() {
            return is_taken;
        }

        int getQuantity() {
            return quantity;
        }

        Date getDate() {
            return time;
        }

        void setTaken(bool a) {
            this->is_taken = a;
        }


};

// Authors
vector <Author> authors;

// Publicants
vector <Publicant> publicants;

// Books
vector <Book> library;

// Borrowed books
vector <Borrowed_book> borrowed;

vector <string> category;

vector <int> requested;

const string AUTHORS_FILE    = "authors.txt";
const string PUBLICANTS_FILE = "publicants.txt";
const string BORROWED_FILE   = "borrowed.txt";
const string CATEGORY_FILE   = "category.txt";
const string REQUESTED_FILE  = "requested.txt";



// HELPFUL FUNCTIONS

// helps to turn all characters of string to lowercase
string toLower(); //  done
int readInt(); // done
void loadAuthors(); // done
void loadPublicants(); // done
void loadBorrowed(); // done
void loadCategory(); // done
void loadRequested();  // done
void saveRequested(); // done
void loadAll(); // done



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
void editAuthor(); // not done
void showAuthor(); // done


// to manage books
void manageBooks(); //  done;
void addBook(); //  done;
void editBook(); //  done
void deleteBook(); // done
void showBooks(); // done

// to manage issusing a book
void issueBook(); //  done

// to manage return of a book
void returnBook(); // done

// to search by author, book, publicant
void manageSearch(); // done
void searchPublicant(); // done
void searchAuthor(); // done
void searchBook(); // done

// to show everything

void manageShow(); // done
void showAuthors(); // done
void showPublicants(); //  done
void manageViewBooks(); // done
void showRequestedBooks(); // done
void showBorrowed(); // done



// STUDENT FUNCTIONS

// to show issues books
void studentIssuedBooks(); // done
// to show books
void showBooksStudent();
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
    int* numberPtr = &number;

    while (true) {
        cin >> *numberPtr;
        if (cin.eof()) {
            exit(0);
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, enter a number: ";
        }
        else {
            cin.ignore(1000, '\n');
            return *numberPtr;
        }
    }
}

string intsToString(const vector<int>& v) {
    string s;
    for (int i = 0; i < v.size(); i++) {
        if (i > 0) s += ",";
        s += to_string(v[i]);
    }
    return s;
}

vector<int> stringToInts(const string& s) {
    vector<int> v;
    stringstream ss(s);
    string part;
    while (getline(ss, part, ',')) {
        try { v.push_back(stoi(part)); } catch (...) {}
    }
    return v;
}

void saveBooks() {
    ofstream out("books.txt");
    if (!out) {
        cout << "Could not open " << "books.txt" << " for writing" << endl;
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id == 0) continue;  

        out << library[i].book_id << '|'
            << library[i].book_name << '|'
            << library[i].author_name << '|'
            << library[i].author_surname << '|'
            << library[i].book_category << '|'
            << library[i].book_publicant << '|'
            << library[i].quantity << '\n';
    }
}

void loadBooks() {
    ifstream in("books.txt");
    if (!in) return;   

    vector<Book> loaded;
    string line;

    while (getline(in, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, first, last, cat, pub, qty;

        getline(ss, id,    '|');
        getline(ss, name,  '|');
        getline(ss, first, '|');
        getline(ss, last,  '|');
        getline(ss, cat,   '|');
        getline(ss, pub,   '|');
        getline(ss, qty,   '|');

        try {
            Book b;
            b.setId(stoi(id));
            b.setName(name);
            b.setAuthorFirstName(first);
            b.setAuthorLastName(last);
            b.setCategory(cat);
            b.setPublicant(pub);
            b.setQuantity(stoi(qty));
            loaded.push_back(b);
        } catch (...) {
        }
    }

    library = loaded;
}

void saveAuthors() {
    ofstream out(AUTHORS_FILE);
    if (!out) { cout << "Could not write " << AUTHORS_FILE << endl; return; }

    for (int i = 0; i < authors.size(); i++) {
        out << authors[i].author_id << '|'
            << authors[i].author_name << '|'
            << authors[i].author_surname << '|'
            << intsToString(authors[i].b) << '\n';
    }
}

void loadAuthors() {
    ifstream in(AUTHORS_FILE);
    if (!in) return;

    vector<Author> loaded;
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, surname, books;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, surname, '|');
        getline(ss, books, '|');

        try {
            Author a;
            a.author_id = stoi(id);
            a.author_name = name;
            a.author_surname = surname;
            a.b = stringToInts(books);
            loaded.push_back(a);
        } catch (...) {}
    }
    authors = loaded;
}

void savePublicant() {
    ofstream out(PUBLICANTS_FILE);
    if (!out) { cout << "Could not write " << PUBLICANTS_FILE << endl; return; }

    for (int i = 0; i < publicants.size(); i++) {
        out << publicants[i].publicant_id << '|'
            << publicants[i].publicant_name << '|'
            << publicants[i].city << '|'
            << intsToString(publicants[i].b) << '\n';
    }
}

void loadPublicants() {
    ifstream in(PUBLICANTS_FILE);
    if (!in) return;

    vector<Publicant> loaded;
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, city, books;
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, city, '|');
        getline(ss, books, '|');

        try {
            Publicant p;
            p.publicant_id = stoi(id);
            p.publicant_name = name;
            p.city = city;
            p.b = stringToInts(books);
            loaded.push_back(p);
        } catch (...) {}
    }
    publicants = loaded;
}

void saveBooked() {
    ofstream out(BORROWED_FILE);
    if (!out) { cout << "Could not write " << BORROWED_FILE << endl; return; }

    for (int i = 0; i < borrowed.size(); i++) {
        Date d = borrowed[i].getDate();
        out << borrowed[i].getId() << '|'
            << borrowed[i].getTaken() << '|'
            << borrowed[i].getQuantity() << '|'
            << d.year << '|' << d.month << '|' << d.day << '\n';
    }
}

void loadBorrowed() {
    ifstream in(BORROWED_FILE);
    if (!in) return;

    vector<Borrowed_book> loaded;
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, taken, quan, y, m, d;
        getline(ss, id, '|');
        getline(ss, taken, '|');
        getline(ss, quan, '|');
        getline(ss, y, '|');
        getline(ss, m, '|');
        getline(ss, d, '|');

        try {
            Date date = {stoi(y), stoi(m), stoi(d)};
            loaded.push_back(Borrowed_book(stoi(id), stoi(taken) != 0, stoi(quan), date));
        } catch (...) {}
    }
    borrowed = loaded;
}

void saveCategory() {
    ofstream out(CATEGORY_FILE);
    if (!out) { cout << "Could not write " << CATEGORY_FILE << endl; return; }

    for (int i = 0; i < category.size(); i++) {
        out << category[i] << '\n';
    }
}

void loadCategory() {
    ifstream in(CATEGORY_FILE);
    if (!in) return;

    vector<string> loaded;
    string line;
    while (getline(in, line)) {
        if (!line.empty()) loaded.push_back(line);
    }
    category = loaded;
}

void saveRequested() {
    ofstream out(REQUESTED_FILE);
    if (!out) { cout << "Could not write " << REQUESTED_FILE << endl; return; }

    for (int i = 0; i < requested.size(); i++) {
        out << requested[i] << '\n';
    }
}

void loadRequested() {
    ifstream in(REQUESTED_FILE);
    if (!in) return;

    vector<int> loaded;
    string line;
    while (getline(in, line)) {
        try { loaded.push_back(stoi(line)); } catch (...) {}
    }
    requested = loaded;
}

void loadAll() {
    loadBooks();
    loadAuthors();
    loadPublicants();
    loadBorrowed();
    loadCategory();
    loadRequested();
}



void displayMainPanel() {

    int command;

    cout << endl << endl << "LIBRARY MANAGEMENT SYSTEM" << endl << "Admin Module: 1" << endl << "Student Module: 2" <<  endl << "Exit system: 3" << endl << "Please Enter Module number: ";
    command = readInt();

    switch (command) {
        case 1: 
            displayAdminPanel();
            break;
        case 2: 
            displayStudentPanel();
            break;
        case 3:
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
    << "Return borrowed book: 5" << endl
    << "Search authors, books, publicants: 6" << endl
    << "View authors, publications, books, requested books, issued books reports: 7" << endl
    << endl
    << "Back: 8" << endl
    << "Please enter command number: ";
    command = readInt();

    switch(command) {
        case 1: 
            manageCategory();
            break;
        case 2:
            manageAuthors();
            break;
        case 3: 
            manageBooks();
            break;
        case 4: 
            issueBook();
            break;
        case 5: 
            returnBook();
            break;
        case 6: 
            manageSearch();
            break;
        case 7:
            manageShow();
            break;
        case 8: 
            displayMainPanel();
            break;
        default: 
            cout << endl << "UNKNOWN COMMAND" << endl;
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
    command = readInt();

    switch(command) {
        case 1: 
            studentIssuedBooks();
            break;
        case 2: 
            showBooksStudent();
            break;
        case 3: 
            displayMainPanel();
            break;
        default: 
            cout << "UKNOWN COMMAND" << endl;
            displayStudentPanel();
    }
};


// Category
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
    command = readInt();

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
        saveCategory();
        manageCategory();
    }
};

void editCategory() {
    string old_name, new_name;
    int categoryIndex = -1;

    cout << "Please enter category name you want to edit: ";
    cin >> ws;
    getline(cin, old_name);

    for (int i = 0; i < category.size(); i++) {
        if (toLower(category[i]) == toLower(old_name)) {
            categoryIndex = i;
            break;
        }
    }

    if (categoryIndex == -1) {
        cout << "Category with this name was not found" << endl;
        manageCategory();
        return;
    }

    cout << "Please enter new name for chosen category: ";
    getline(cin, new_name);

    if (new_name.empty()) {
        cout << "Category name cannot be empty" << endl;
        manageCategory();
        return;
    }

    for (int i = 0; i < category.size(); i++) {
        if (i != categoryIndex && toLower(category[i]) == toLower(new_name)) {
            cout << "Category with this name already exists" << endl;
            manageCategory();
            return;
        }
    }

    string previousName = category[categoryIndex];
    category[categoryIndex] = new_name;

    for (int i = 0; i < library.size(); i++) {
        if (toLower(library[i].book_category) == toLower(previousName)) {
            library[i].setCategory(new_name);
        }
    }

    cout << "Category name has been successfully updated!" << endl;

    saveCategory();
    saveBooks();

    manageCategory();
}

void deleteCategory() {
    string category_name;
    int categoryIndex = -1;

    cout << "Please enter category name to delete: ";
    cin >> ws;
    getline(cin, category_name);

    for (int i = 0; i < category.size(); i++) {
        if (toLower(category[i]) == toLower(category_name)) {
            categoryIndex = i;
            break;
        }
    }

    if (categoryIndex == -1) {
        cout << "Category with this name was not found" << endl;
        manageCategory();
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        if (toLower(library[i].book_category) == toLower(category[categoryIndex])) {
            cout << "Cannot delete category while books are assigned to it" << endl;
            manageCategory();
            return;
        }
    }

    category.erase(category.begin() + categoryIndex);

    cout << "Category has been successfully deleted" << endl;
    saveCategory();
    manageCategory();
}

void showCategory() {
    cout << endl << "LIST of CATEGORIES: ";
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
    << "Edit Author: 3" << endl
    << "Show Authors: 4" << endl
    << "Back: 5" << endl << endl
    << "Please enter command number: " <<  endl;

    command = readInt();

    switch(command) {
        case 1: 
            deleteAuthor();
            break;
        case 2:
            addAuthor();
            break;
        case 3: 
            editAuthor();
            break;
        case 4:
            showAuthor();
            break;
        case 5:
            displayAdminPanel();
            break;
        default: 
            cout << "UKNOWN COMMAND" << endl;
            manageAuthors();
    }
}



void deleteAuthor() {
    string name_author;

    cout << endl << "DELETING AUTHOR" << endl
         << "Please enter author name or surname: ";
    getline(cin >> ws, name_author);
    name_author = toLower(name_author);

    int authorIndex = -1;

    for (int i = 0; i < authors.size(); i++) {
        string fullName = toLower(
            authors[i].author_name + " " + authors[i].author_surname
        );

        if (toLower(authors[i].author_name) == name_author || toLower(authors[i].author_surname) == name_author ||  fullName == name_author) {
            authorIndex = i;
            break;
        }
    }

    if (authorIndex == -1) {
        cout << "Author was not found" << endl;
        manageAuthors();
        return;
    }

    for (int i = 0; i < library.size(); i++) {
    if (toLower(library[i].author_name) == toLower(authors[authorIndex].author_name) &&
        toLower(library[i].author_surname) == toLower(authors[authorIndex].author_surname)) {
            cout << "Cannot delete author while their books exist" << endl;
            manageAuthors();
            return;
        }
    }

    authors.erase(authors.begin() + authorIndex);
    saveAuthors();

    cout << "Author was successfully deleted" << endl;
    manageAuthors();
}

void addAuthor() {
    int id;
    string name, surname;

    cout << endl << "ADDING AUTHOR" << endl;

    cout << "Author ID: ";
    id = readInt();

    for (int i = 0; i < authors.size(); i++) {
        if (authors[i].author_id == id) {
            cout << "An author with this ID already exists" << endl;
            addAuthor();
            return;
        }
    }

    cout << "First name: ";
    getline(cin >> ws, name);

    cout << "Last name: ";
    getline(cin >> ws, surname);

    if (name.empty() || surname.empty()) {
        cout << "Name and surname cannot be empty" << endl;
        addAuthor();
        return;
    }

    Author a;
    a.author_id = id;
    a.author_name = name;
    a.author_surname = surname;

    authors.push_back(a);

    cout << "Author added." << endl;
    saveAuthors();
    manageAuthors();
}

void editAuthor() {
    int command;

    cout << "EDITING AUTHOR" << endl
    << "Edit name: 1" << endl
    << "Edit last name: 2" << endl
    << "Edit book id: 3" << endl
    << "Back: 4" << endl
    << "Please enter command number: ";

    command = readInt();

    switch (command) {
        case 1:
        case 2: {
            int id;
            int needed_id = -1;
            string name;

            cout << "Please enter author ID (0 to quit): ";
            id = readInt();

            if (id == 0) {
                manageAuthors();
                return;
            }

            for (int i = 0; i < authors.size(); i++) {
                if (authors[i].author_id == id) {
                    needed_id = i;
                    break;
                }
            }

            if (needed_id == -1) {
                cout << "Author with this ID was not found" << endl;
                editAuthor();
                return;
            }

            cout << "Please enter new "
                 << (command == 1 ? "first name: " : "last name: ");

            getline(cin >> ws, name);

            if (name.empty()) {
                cout << "Name cannot be empty" << endl;
                editAuthor();
                return;
            }

            if (command == 1) {
                authors[needed_id].setName(name);
            }
            else {
                authors[needed_id].setLastName(name);
            }

            for (int i = 0; i < library.size(); i++) {
                for (int j = 0; j < authors[needed_id].b.size(); j++) {
                    if (library[i].book_id == authors[needed_id].b[j]) {
                        if (command == 1) {
                            library[i].setAuthorFirstName(name);
                        }
                        else {
                            library[i].setAuthorLastName(name);
                        }
                    }
                }
            }

            cout << "Author information has been successfully updated" << endl;

            saveAuthors();
            saveBooks();

            manageAuthors();
            return;
        }

        case 3: {
            int id;
            int bk_id;
            int needed_id = -1;
            int bookIndex = -1;

            cout << "Please enter author ID (0 to quit): ";
            id = readInt();

            if (id == 0) {
                manageAuthors();
                return;
            }

            for (int i = 0; i < authors.size(); i++) {
                if (authors[i].author_id == id) {
                    needed_id = i;
                    break;
                }
            }

            if (needed_id == -1) {
                cout << "Author with this ID was not found" << endl;
                editAuthor();
                return;
            }

            cout << "Enter book ID to add (0 to quit): ";
            bk_id = readInt();

            if (bk_id == 0) {
                manageAuthors();
                return;
            }

            for (int i = 0; i < library.size(); i++) {
                if (library[i].book_id == bk_id) {
                    bookIndex = i;
                    break;
                }
            }

            if (bookIndex == -1) {
                cout << "Book with this ID was not found" << endl;
                editAuthor();
                return;
            }

            for (int i = 0; i < authors[needed_id].b.size(); i++) {
                if (authors[needed_id].b[i] == bk_id) {
                    cout << "This book is already assigned to this author" << endl;
                    editAuthor();
                    return;
                }
            }

            for (int i = 0; i < authors.size(); i++) {
                for (int j = 0; j < authors[i].b.size();) {
                    if (authors[i].b[j] == bk_id) {
                        authors[i].b.erase(authors[i].b.begin() + j);
                    }
                    else {
                        j++;
                    }
                }
            }

            authors[needed_id].setBook(bk_id);

            library[bookIndex].setAuthorFirstName(authors[needed_id].author_name);
            library[bookIndex].setAuthorLastName(authors[needed_id].author_surname);

            cout << "Book has been successfully assigned to the author" << endl;

            saveAuthors();
            saveBooks();

            manageAuthors();
            return;
        }

        case 4:
            manageAuthors();
            return;

        default:
            cout << "UNKNOWN COMMAND" << endl;
            editAuthor();
            return;
    }
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

// BOOKS

void manageBooks() {
    int command;

    cout << endl << "MANAGE BOOKS" <<  endl
    << "Edit book: 1" << endl
    << "Add book: 2" << endl
    << "Delete book: 3" << endl
    << "Show all books: 4" << endl
    << "Back: 5" << endl << endl
    << "Enter command number: ";
    command = readInt();

    switch(command) {
        case 1: 
            editBook();
            break;
        case 2: 
            addBook();
            break;
        case 3: 
            deleteBook();
            break;
        case 4: 
            showBooks();
            break;
        case 5: 
            displayAdminPanel();
            break;
        default: 
            cout << "UKNOWN COMMAND" <<  endl;
            manageBooks();
        
    }
}
void addBook() {
    Book new_book;
    string book_name, author_first_name, author_last_name, publicant_name, new_category;
    int quan;
    bool exists = false;

    cout << "ADDING A BOOK" << endl
    << "Please enter book name (0 to quit): ";
    cin >> ws;
    getline(cin, book_name);

    if (book_name == "0") {
        manageBooks();
        return;
    }

    if (book_name.empty()) {
        cout << "Book name cannot be empty!" << endl;
        manageBooks();
        return;
    }

    cout << "Please enter author first name(0 to quit): ";
    cin >> ws;
    getline(cin, author_first_name);

    if (author_first_name == "0") {
        manageBooks();
        return;
    }

    if (author_first_name.empty()) {
        cout << "Author first name cannot be empty!" << endl;
        manageBooks();
        return;
    }

    cout << "Please enter author last name(0 to quit): ";
    cin >> ws;
    getline(cin, author_last_name);

    if (author_last_name == "0") {
        manageBooks();
        return;
    }

    if (author_last_name.empty()) {
        cout << "Author last name cannot be empty!" << endl;
        manageBooks();
        return;
    }

    cout << "Please enter category name(0 to quit): ";
    cin >> ws;
    getline(cin, new_category);

    if (new_category == "0") {
        manageBooks();
        return;
    }

    if (new_category.empty()) {
        cout << "Category name cannot be empty!" << endl;
        manageBooks();
        return;
    }

    for (int i = 0; i < category.size(); i++) {
        if (toLower(category[i]) == toLower(new_category)) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        cout << "This category does not exist in category list, please add it first" << endl;
        manageBooks();
        return;
    }

    cout << "Please enter publicant name(0 to quit): ";
    cin >> ws;
    getline(cin, publicant_name);

    if (publicant_name == "0") {
        manageBooks();
        return;
    }

    if (publicant_name.empty()) {
        cout << "Publicant name cannot be empty!" << endl;
        manageBooks();
        return;
    }

    cout << "Please enter quantity of the book(-1 to quit): ";
    quan = readInt();

    if (quan == -1) {
        manageBooks();
        return;
    }

    if (quan < 0) {
        cout << "Quantity cannot be negative!" << endl;
        manageBooks();
        return;
    }

    int nextId = 1;

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id >= nextId) {
            nextId = library[i].book_id + 1;
        }
    }

    new_book.setId(nextId);
    new_book.setName(book_name);
    new_book.setAuthorFirstName(author_first_name);
    new_book.setAuthorLastName(author_last_name);
    new_book.setCategory(new_category);
    new_book.setPublicant(publicant_name);
    new_book.setQuantity(quan);

    library.push_back(new_book);

    for (int i = 0; i < authors.size(); i++) {
        if (toLower(authors[i].author_name) == toLower(author_first_name) &&
            toLower(authors[i].author_surname) == toLower(author_last_name)) {
            authors[i].setBook(nextId);
        }
    }

    for (int i = 0; i < publicants.size(); i++) {
        if (toLower(publicants[i].publicant_name) == toLower(publicant_name)) {
            publicants[i].b.push_back(nextId);
        }
    }

    saveBooks();
    saveAuthors();
    savePublicant();

    cout << endl << "New book have been successfully added!" << endl;
    manageBooks();
}
void editBook() {
    int book_id;
    int needed_book = -1;

    cout << "EDITING BOOK" << endl
    << "Please enter book_id of the book you want to edit(0 to quit): " << endl;

    book_id = readInt();

    if (book_id == 0) {
        manageBooks();
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id == book_id) {
            needed_book = i;
            break;
        }
    }

    if (needed_book == -1) {
        cout << "Book with this ID wasn't found" << endl;
        editBook();
        return;
    }

    int command;

    cout << "BOOK FOUND" << endl
    << "Edit Name: 1" << endl
    << "Edit Quantity: 2" << endl
    << "Edit Author First Name: 3" << endl
    << "Edit Author Last name: 4" << endl
    << "Edit Publicant: 5" << endl
    << "Back: 6" << endl << endl
    << "Please enter number of command: ";

    command = readInt();

    switch (command) {
        case 1: {
            string name;

            cout << "Please enter new name for the book(0 to quit): ";
            getline(cin >> ws, name);

            if (name == "0") {
                manageBooks();
                return;
            }

            if (name.empty()) {
                cout << "Book name cannot be empty!" << endl;
                manageBooks();
                return;
            }

            library[needed_book].setName(name);

            cout << "Book name was successfully updated" << endl;

            saveBooks();
            manageBooks();
            return;
        }

        case 2: {
            int num;

            cout << "Please enter book quantity(-1 to quit): ";
            num = readInt();

            if (num == -1) {
                manageBooks();
                return;
            }

            if (num < 0) {
                cout << "Quantity cannot be negative!" << endl;
                manageBooks();
                return;
            }

            library[needed_book].setQuantity(num);

            cout << "Book quantity was successfully updated" << endl;

            saveBooks();
            manageBooks();
            return;
        }

        case 3: {
            string name;
            string oldFirst = library[needed_book].author_name;
            string oldLast = library[needed_book].author_surname;

            cout << "Please enter Author first name(0 to quit): ";
            getline(cin >> ws, name);

            if (name == "0") {
                manageBooks();
                return;
            }

            if (name.empty()) {
                cout << "Author name cannot be empty" << endl;
                manageBooks();
                return;
            }

            library[needed_book].setAuthorFirstName(name);

            for (int i = 0; i < authors.size(); i++) {
                if (toLower(authors[i].author_name) == toLower(oldFirst) &&
                    toLower(authors[i].author_surname) == toLower(oldLast)) {

                    for (int j = 0; j < authors[i].b.size();) {
                        if (authors[i].b[j] == book_id) {
                            authors[i].b.erase(authors[i].b.begin() + j);
                        }
                        else {
                            j++;
                        }
                    }
                }
            }

            for (int i = 0; i < authors.size(); i++) {
                if (toLower(authors[i].author_name) == toLower(name) &&
                    toLower(authors[i].author_surname) == toLower(oldLast)) {

                    bool alreadyExists = false;

                    for (int j = 0; j < authors[i].b.size(); j++) {
                        if (authors[i].b[j] == book_id) {
                            alreadyExists = true;
                            break;
                        }
                    }

                    if (!alreadyExists) {
                        authors[i].setBook(book_id);
                    }
                }
            }

            cout << "Book author name was updated successfully!" << endl;

            saveBooks();
            saveAuthors();

            manageBooks();
            return;
        }

        case 4: {
            string surname;
            string oldFirst = library[needed_book].author_name;
            string oldLast = library[needed_book].author_surname;

            cout << "Please enter Author last name(0 to quit): ";
            getline(cin >> ws, surname);

            if (surname == "0") {
                manageBooks();
                return;
            }

            if (surname.empty()) {
                cout << "Author last name cannot be empty" << endl;
                manageBooks();
                return;
            }

            library[needed_book].setAuthorLastName(surname);

            for (int i = 0; i < authors.size(); i++) {
                if (toLower(authors[i].author_name) == toLower(oldFirst) &&
                    toLower(authors[i].author_surname) == toLower(oldLast)) {

                    for (int j = 0; j < authors[i].b.size();) {
                        if (authors[i].b[j] == book_id) {
                            authors[i].b.erase(authors[i].b.begin() + j);
                        }
                        else {
                            j++;
                        }
                    }
                }
            }

            for (int i = 0; i < authors.size(); i++) {
                if (toLower(authors[i].author_name) == toLower(oldFirst) &&
                    toLower(authors[i].author_surname) == toLower(surname)) {

                    bool alreadyExists = false;

                    for (int j = 0; j < authors[i].b.size(); j++) {
                        if (authors[i].b[j] == book_id) {
                            alreadyExists = true;
                            break;
                        }
                    }

                    if (!alreadyExists) {
                        authors[i].setBook(book_id);
                    }
                }
            }

            cout << "Book author last name was updated successfully!" << endl;

            saveBooks();
            saveAuthors();

            manageBooks();
            return;
        }

        case 5: {
            string name;
            string oldName = library[needed_book].book_publicant;

            cout << "Please enter publicant name(0 to quit): ";
            getline(cin >> ws, name);

            if (name == "0") {
                manageBooks();
                return;
            }

            if (name.empty()) {
                cout << "Publicant name cannot be empty" << endl;
                manageBooks();
                return;
            }

            library[needed_book].setPublicant(name);

            for (int i = 0; i < publicants.size(); i++) {
                if (toLower(publicants[i].publicant_name) == toLower(oldName)) {
                    for (int j = 0; j < publicants[i].b.size();) {
                        if (publicants[i].b[j] == book_id) {
                            publicants[i].b.erase(publicants[i].b.begin() + j);
                        }
                        else {
                            j++;
                        }
                    }
                }
            }

            for (int i = 0; i < publicants.size(); i++) {
                if (toLower(publicants[i].publicant_name) == toLower(name)) {
                    bool alreadyExists = false;

                    for (int j = 0; j < publicants[i].b.size(); j++) {
                        if (publicants[i].b[j] == book_id) {
                            alreadyExists = true;
                            break;
                        }
                    }

                    if (!alreadyExists) {
                        publicants[i].b.push_back(book_id);
                    }
                }
            }

            cout << "Book publicant name was updated successfully" << endl;

            saveBooks();
            savePublicant();

            manageBooks();
            return;
        }

        case 6:
            manageBooks();
            return;

        default:
            cout << "UNKNOWN COMMAND" << endl;
            editBook();
            return;
    }
}
void deleteBook() {
    int id;
    int bookIndex = -1;

    cout << endl << endl << "Please Enter Book ID: ";
    id = readInt();

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id == id) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book was not found" << endl;
        manageBooks();
        return;
    }

    for (int i = 0; i < borrowed.size(); i++) {
        if (borrowed[i].getId() == id && borrowed[i].getTaken()) {
            cout << "Cannot delete a book while it is borrowed" << endl;
            manageBooks();
            return;
        }
    }

    library.erase(library.begin() + bookIndex);

    for (int i = 0; i < authors.size(); i++) {
        for (int j = 0; j < authors[i].b.size();) {
            if (authors[i].b[j] == id) {
                authors[i].b.erase(authors[i].b.begin() + j);
            }
            else {
                j++;
            }
        }
    }

    for (int i = 0; i < publicants.size(); i++) {
        for (int j = 0; j < publicants[i].b.size();) {
            if (publicants[i].b[j] == id) {
                publicants[i].b.erase(publicants[i].b.begin() + j);
            }
            else {
                j++;
            }
        }
    }

    for (int i = 0; i < requested.size();) {
        if (requested[i] == id) {
            requested.erase(requested.begin() + i);
        }
        else {
            i++;
        }
    }

    cout << "Book was successfully removed" << endl;

    saveBooks();
    saveAuthors();
    savePublicant();
    saveRequested();

    cout << endl << "REMAINING BOOKS: " << endl;

    for (int i = 0; i < library.size(); i++) {
        cout << library[i].book_id << " | " << library[i].book_name << " | " << library[i].author_name << endl;
    }

    manageBooks();
}



void showBooks() {
    cout << endl << "ALL BOOKS" << endl;
    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " | " << library[i].book_name << " | " << library[i].author_name << " " << library[i].author_surname << endl;
        } 
    }

    manageBooks();
}
// {1, "The Silent Stage",  true, 1},
bool validReturnDate(int year, int month, int day) {
    if (month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool leapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

    if (leapYear) {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1]) {
        return false;
    }

    time_t now = time(nullptr);
    tm current = *localtime(&now);

    int currentYear = current.tm_year + 1900;
    int currentMonth = current.tm_mon + 1;
    int currentDay = current.tm_mday;

    if (year < currentYear) {
        return false;
    }

    if (year == currentYear && month < currentMonth) {
        return false;
    }

    if (year == currentYear && month == currentMonth && day <= currentDay) {
        return false;
    }

    return true;
}
void issueBook() {
    int book_id, quan, year, day, month, bookIndex = -1;

    cout << "ISSUING BOOK" << endl
    << "Please enter book id you want to issue(-1 to quit): ";
    book_id = readInt();

    if (book_id == -1) {
        displayAdminPanel();
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id == book_id) {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1) {
        cout << "Book not found" << endl;
        issueBook();
        return;
    }

    cout << "Please enter issued quantity of the book(-1 to quit): ";
    quan = readInt();

    if (quan == -1) {
        displayAdminPanel();
        return;
    }

    if (quan <= 0 || quan > library[bookIndex].quantity) {
        cout << "Invalid quantity" << endl;
        issueBook();
        return;
    }

    cout << "Please enter return year(-1 to quit): ";
    year = readInt();

    if (year == -1) {
        displayAdminPanel();
        return;
    }

    cout << "Please enter return month(-1 to quit): ";
    month = readInt();

    if (month == -1) {
        displayAdminPanel();
        return;
    }

    cout << "Please enter return day(-1 to quit): ";
    day = readInt();

    if (day == -1) {
        displayAdminPanel();
        return;
    }

    if (!validReturnDate(year, month, day)) {
        cout << "Invalid return date. Please enter a valid future date." << endl;
        issueBook();
        return;
    }

    Date retr = {year, month, day};

    Borrowed_book borrowed1(book_id, true, quan, retr);

    library[bookIndex].setQuantity(library[bookIndex].quantity - quan);

    borrowed.push_back(borrowed1);

    cout << "A book was issued to student" << endl;

    saveBooked();
    saveBooks();

    displayAdminPanel();
}

void returnBook() {
    int book_id, bookIndex = -1;
    int borrowedIndex = -1;

    cout << "RETURNING BOOK" << endl;
    cout << "Please enter book id you want to return(-1 to quit): ";
    book_id = readInt();

    if (book_id == -1) {
        displayAdminPanel();
        return;
    }

    for (int i = 0; i < borrowed.size(); i++) {
        if (borrowed[i].getId() == book_id && borrowed[i].getTaken()) {
            borrowedIndex = i;
            break;
        }
    }

    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id == book_id) {
            bookIndex = i;
            break;
        }
    }

    if (borrowedIndex == -1 || bookIndex == -1) {
        cout << "No active borrowed record was found for this book" << endl;
        returnBook();
        return;
    }

    borrowed[borrowedIndex].setTaken(false);

    library[bookIndex].setQuantity(
        library[bookIndex].quantity + borrowed[borrowedIndex].getQuantity()
    );

    cout << endl << "Borrowed book has been returned" << endl;

    saveBooked();
    saveBooks();

    displayAdminPanel();
}

void manageSearch() {
    int command;
    cout << endl << "SEARCH MANAGER" << endl
    << "Search authors: 1" << endl
    << "Search books: 2" << endl
    << "Search publicant: 3" << endl
    << "Back: 4" << endl;
    command = readInt();

    switch(command) {
        case 1: 
            searchAuthor();
            break;
        case 2: 
            searchBook();
            break;
        case 3: 
            searchPublicant();
            break;
        case 4: 
            displayAdminPanel();
            break;
        default: 
            cout << "UNKNOWN COMMAND" << endl;
            manageSearch();
            break;
    }
}

void searchPublicant() {
    string searched_word;
    cout << "SEARCHING PUBLICANT" << endl
    << "Please enter publicant name(0 to quit): ";
    cin >> ws;
    getline(cin, searched_word);

    if (searched_word.empty()) {
        cout  << "Publicant name cannot be empty" << endl;
        searchPublicant();
        return;
    }

    if (searched_word == "0") {
        displayAdminPanel();
        return;
    }

    cout << "SEARCH RESULT: " << endl;
    for (int i  = 0; i < publicants.size(); i++) {
        if (toLower(publicants[i].publicant_name).find(toLower(searched_word))  != string::npos) {
            cout << "Publicant Name: " << publicants[i].publicant_name << " " << "Publicant city: " << publicants[i].city <<  endl;
        }
    }

    displayAdminPanel();
    return;
}

void searchAuthor() {
    string searched_word;
    cout << "SEARCHING AUTHOR" << endl
    << "Please enter author name(0 to quit): ";
    cin >> ws;
    getline(cin, searched_word);

    if (searched_word.empty()) {
        cout  << "Author name cannot be empty" << endl;
        searchAuthor();
        return;
    }

    if (searched_word == "0") {
        displayAdminPanel();
        return;
    }

    cout << "SEARCH RESULT: " << endl;
    for (int i  = 0; i < authors.size(); i++) {
        if (toLower(authors[i].author_name).find(toLower(searched_word))  != string::npos || toLower(authors[i].author_surname).find(toLower(searched_word)) != string::npos || (toLower(authors[i].author_name) + " " + toLower(authors[i].author_surname)).find(toLower(searched_word)) != string::npos) {
            cout << "Author name: " << authors[i].author_name << " " << "Author last name: " << authors[i].author_surname <<  endl;
        }
    }

    displayAdminPanel();
    return;
}

void searchBook(){
    string searched_word;
    cout << "SEARCHING BOOK" << endl
    << "Please enter book name(0 to quit): ";
    cin >> ws;
    getline(cin, searched_word);

    if (searched_word.empty()) {
        cout  << "Book name cannot be empty" << endl;
        searchBook();
        return;
    }

    if (searched_word == "0") {
        displayAdminPanel();
        return;
    }

    cout << "SEARCH RESULT: " << endl;
    for (int i  = 0; i < library.size(); i++) {
        if (toLower(library[i].book_name).find(toLower(searched_word))  != string::npos) {
            cout << "Book name: " << library[i].book_name << " " << "Quantity: " << library[i].quantity <<   endl;
        }
    }

    displayAdminPanel();
    return;
}

void manageShow(){ 
    int command;
    cout << endl << "VIEW MANAGER" << endl
    << "View Authors: 1" << endl
    << "View Publicants: 2" << endl
    << "View Books: 3" << endl
    << "View requested books: 4" << endl
    << "View borrowed books: 5" << endl
    << "Back: 6" << endl
    << "Please enter command number: ";
    command = readInt();

    switch(command) {
        case 1:
           showAuthors();
           break;
        case 2:
            showPublicants();
            break;
        case 3: 
            manageViewBooks();
            break;
        case 4: 
            showRequestedBooks();
            break;
        case 5: 
            showBorrowed();
            break;
        case 6:
            displayAdminPanel();
            break;
        default:
            cout << "UNKNOWN COMMAND" << endl; 
            manageShow();
            break; 
    }

}

void showAuthors(){
    cout << endl <<  "ALL AUTHORS" << endl;
    for (int i = 0; i < authors.size();i++) {
        cout << "Author Id: " << authors[i].author_id << " " << "Author name: " << authors[i].author_name <<" " <<  authors[i].author_surname << endl;
        cout << "Author books: " << endl;
        for (int j = 0; j < library.size();j++) {
            for (int l = 0; l < authors[i].b.size();l++){
                if (library[j].book_id == authors[i].b[l]) {
                    cout << "Book id: " << library[j].book_id << " " << "Book name: " << library[j].book_name << " " << "Book Publicant: " << library[j].book_publicant <<  endl;
                }
            }
        }

        cout << endl;
    }

    manageShow();
    return;
} 
void showPublicants(){
    cout << "ALL PUBLICANTS" << endl;
    for (int i = 0;i < publicants.size();i++) {
        cout << "Publicant name: " << publicants[i].publicant_name << " " << "City: " << publicants[i].city << endl;
        cout << "Published books: " << endl;
        for (int j = 0; j < library.size();j++){
            for (int l = 0; l < publicants[i].b.size();l++){
                if (library[j].book_id == publicants[i].b[l]) {
                    cout << "Book name: " << library[j].book_name << endl;
                }
            }
        }

    cout << endl;
    }

    manageShow();
    return;
} 
void manageViewBooks(){
    
    cout << endl << "VIEW BOOKS" << endl;

    for (int i = 0; i < library.size(); i++) {
        cout << "Book info: " << "Id: " << library[i].book_id << " | " << "Name: " << library[i].book_name << " | " << "Author: " << library[i].author_name + " " + library[i].author_surname << " | " << "Publicant: " << library[i].book_publicant << endl;
    }

    manageShow();
    return;
}; 


void studentIssuedBooks() {
    cout << endl << "ISSUED BOOKS AND THEIR RETURN TIME: " << endl;

    for (int i = 0; i < library.size(); i++) {
        for (int j = 0; j < borrowed.size(); j++) {
            if (library[i].book_id == borrowed[j].getId() && borrowed[j].getTaken()) {
                cout << "Book id: " << library[i].book_id << " | " << "Book name: " << library[i].book_name << " | " << "Return time: " << borrowed[j].getDate().year << " " << borrowed[j].getDate().month << " " << borrowed[j].getDate().day << endl;
            }
        }
    }

    displayStudentPanel();
    return;
}

void showRequestedBooks(){
    cout << endl << "REQUESTED BOOKS: " << endl;
    for (int i = 0; i < library.size(); i++) {
        for (int j = 0; j < requested.size();j++){
            if (library[i].book_id == requested[j]) {
                cout << "Book id: " << library[i].book_id << " | " << "Book name: " << library[i].book_name << endl;
            }
        }
    }

    manageShow();
    return;
}; 

void showBorrowed() {
    cout << endl << "BORROWED BOOKS: " << endl;

    for (int i = 0; i < library.size(); i++) {
        for (int j = 0; j < borrowed.size(); j++) {
            if (library[i].book_id == borrowed[j].getId() && borrowed[j].getTaken()) {
                cout << "Book id: " << library[i].book_id << " | " << "Book name: " << library[i].book_name << " | " << "Return time: " << borrowed[j].getDate().year << " " << borrowed[j].getDate().month << " " << borrowed[j].getDate().day << endl;
            }
        }
    }

    manageShow();
    return;
} 



void showBooksStudent() {
    cout  << endl << "FULL LIBRARY" << endl;
    for (int i = 0; i < library.size(); i++) {
        if (library[i].book_id != 0) {
            cout << library[i].book_id << " | " << library[i].book_name << " | " << library[i].author_name << " " << library[i].author_surname << endl;
        } 
    }

    displayStudentPanel();
    return;
}







int main() {
    loadAll();
    displayMainPanel();

    return 0;
}