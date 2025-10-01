#include <iostream>
#include <cctype>
using namespace std;

class temp_ture {
private:
  char A1[500], A2[500], A3[500], A4[500], A5[500];

public:
  void setData() {
    cout << "Enter 5 strings:\n";
    cin >> A1 >> A2 >> A3 >> A4 >> A5;
  }

  void displayData() {
    cout << "Stored Strings:\n";
    cout << A1 << endl << A2 << endl << A3 << endl << A4 << endl << A5 << endl;
  }

  void countVowelsConsonants() {
    int vowels = 0, consonants = 0;
    char* arrays[] = { A1, A2, A3, A4, A5 };

    for (int i = 0; i < 5; i++) {
      for (int j = 0; arrays[i][j] != '\0'; j++) {
        char ch = tolower(arrays[i][j]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
          vowels++;
        }
        else if (isalpha(ch)) {
          consonants++;
        }
      }
    }
    cout << "Vowels: " << vowels << "\nConsonants: " << consonants << endl;
  }

  void countCharacters() {
    int total = 0;
    char* arrays[] = { A1, A2, A3, A4, A5 };
    for (int i = 0; i < 5; i++) {
      for (int j = 0; arrays[i][j] != '\0'; j++) {
        total++;
      }
    }
    cout << "Total characters in all strings: " << total << endl;
  }
};

int main() {
  temp_ture obj;
  obj.setData();
  obj.displayData();
  obj.countVowelsConsonants();
  obj.countCharacters();
  return 0;
}
