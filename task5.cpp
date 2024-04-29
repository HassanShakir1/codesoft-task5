#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class definition
class Book {
private:
    string title;
    string author;
    string ISBN;
    bool available;

public:
    // Constructor
    Book(string t, string a, string isbn) : title(t), author(a), ISBN(isbn), available(true) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }
    bool isAvailable() const { return available; }

    // Setter for availability status
    void setAvailability(bool avail) { available = avail; }
};

// Function to add a book to the library database
void addBook(vector<Book>& library) {
    string title, author, ISBN;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);

    library.push_back(Book(title, author, ISBN));
    cout << "Book added to the library." << endl;
}

// Function to search for a book by title, author, or ISBN
void searchBook(const vector<Book>& library) {
    string query;
    cout << "Enter search query (title, author, or ISBN): ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const Book& book : library) {
        if (book.getTitle() == query || book.getAuthor() == query || book.getISBN() == query) {
            cout << "Book found:" << endl;
            cout << "Title: " << book.getTitle() << endl;
            cout << "Author: " << book.getAuthor() << endl;
            cout << "ISBN: " << book.getISBN() << endl;
            cout << "Availability: " << (book.isAvailable() ? "Available" : "Not Available") << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

// Main function
int main() {
    vector<Book> library;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchBook(library);
                break;
            case 3:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    }

    return 0;
}