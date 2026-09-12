#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string ISBN, Title, Author;
    bool isIssued;

    Book() {
        isIssued = false;
    }

    Book(string i, string t, string a) {
        ISBN = i;
        Title = t;
        Author = a;
        isIssued = false;
    }
};
int main() {
    Book books[30];
    int count = 0;
    int choice;
    do {
        cout << "\n===== Library Catalog =====\n";
        cout << "1. Add ";
        cout << "2. Issue ";
        cout << "3. Return ";
        cout << "4. Search ";
        cout << "5. Display All ";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            string ISBN, Title, Author;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            cout << "Enter Title: ";
            getline(cin, Title);
            cout << "Enter Author: ";
            getline(cin, Author);
            books[count] = Book(ISBN, Title, Author);
            count++;
            cout << "Book added.\n";
        }
        else if (choice == 2) {
            string ISBN;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].ISBN == ISBN) {
                    found = true;
                    if (books[i].isIssued)
                        cout << "Book already isIssued.\n";
                    else {
                        books[i].isIssued = true;
                        cout << "Book issued successfully.\n";
                    }
                    break;
                }
            }
            if (!found)
                cout << "ISBN not found.\n";
        }
        else if (choice == 3) {
            string ISBN;
            cout << "Enter ISBN: ";
            getline(cin, ISBN);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].ISBN == ISBN) {
                    found = true;

                    if (!books[i].isIssued)
                        cout << "Book is not issued.\n";
                    else {
                        books[i].isIssued = false;
                        cout << "Book returned.\n";
                    }
                    break;
                }
            }
            if (!found)
                cout << "ISBN not found.\n";
        }
        else if (choice == 4) {
            string search;
            cout << "Enter title to search: ";
            getline(cin, search);
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (books[i].Title.find(search) != string::npos) {
                    cout << books[i].Title << " by "
                         << books[i].Author << "\n";
                    found = true;
                }
            }
            if (!found)
                cout << "ISBN not found.\n";
        }
        else if (choice == 5) {
            if (count == 0) {
                cout << "No matching books.\n";
            } else {
                for (int i = 0; i < count; i++) {
                    cout << "["<< books[i].ISBN<<"] "<< books[i].Title<<" by "<< books[i].Author<<(books[i].isIssued ? " - Issued" : "Available");
                    cout << "\n";
                }
            }
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);
    return 0;
}
