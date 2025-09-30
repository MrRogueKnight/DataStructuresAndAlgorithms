#include <iostream>
#include <string>
using namespace std;

class S1 {
private:
  string str;
public:
  void setString(string s) {
    str = s;
  }
  string getString() {
    return str;
  }
};

class S2 {
private:
  string str;
public:
  void setString(string s) {
    str = s;
  }
  string getString() {
    return str;
  }
};

class S3 {
private:
  string str;
public:
  void setString(string s) {
    str = s;
  }
  void printString() {
    cout << "Concatenated string: " << str << endl;
  }
};

int main() {
  S1 obj1;
  S2 obj2;
  S3 obj3;

  string s1, s2;

  cout << "Enter first string: ";
  getline(cin, s1);
  cout << "Enter second string: ";
  getline(cin, s2);

  obj1.setString(s1);
  obj2.setString(s2);

  string combined = obj1.getString() + obj2.getString();
  obj3.setString(combined);

  obj3.printString();

  return 0;
}
