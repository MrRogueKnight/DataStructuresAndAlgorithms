#include <iostream>
#include <string>
using namespace std;

class Library {
private:
  string bookTitle;
  string author;
  bool isAvailable;

public:
  Library(string title, string auth) {
    bookTitle = title;
    author = auth;
    isAvailable = true;
  }

  void lendBook() {
    if (isAvailable) {
      isAvailable = false;
      cout << "Book '" << bookTitle << "' has been lent out." << endl;
    }
    else {
      cout << "Book '" << bookTitle << "' is not available." << endl;
    }
  }

  void returnBook() {
    isAvailable = true;
    cout << "Book '" << bookTitle << "' has been returned." << endl;
  }

  void displayStatus() {
    cout << bookTitle << " by " << author;
    cout << " - " << (isAvailable ? "Available" : "Not Available") << endl;
  }
};

int main() {
  Library book1("The Great Gatsby", "F. Scott Fitzgerald");

  book1.displayStatus();
  book1.lendBook();
  book1.lendBook();
  book1.returnBook();
  book1.displayStatus();

  return 0;
}
