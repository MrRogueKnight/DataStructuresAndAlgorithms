#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
  string accountNumber;
  string accountHolder;
  double balance;

public:
  BankAccount(string accNum, string accHolder, double initialBalance) {
    accountNumber = accNum;
    accountHolder = accHolder;
    balance = initialBalance;
  }

  void deposit(double amount) {
    if (amount > 0) {
      balance += amount;
      cout << "Deposited: $" << amount << " into account " << accountNumber << endl;
    }
    else {
      cout << "Invalid deposit amount!" << endl;
    }
  }

  void withdraw(double amount) {
    if (amount > balance) {
      cout << "Withdrawal failed! Insufficient balance." << endl;
    }
    else if (amount <= 0) {
      cout << "Invalid withdrawal amount!" << endl;
    }
    else {
      balance -= amount;
      cout << "Withdrew: $" << amount << " from account " << accountNumber << endl;
    }
  }

  void displayBalance() {
    cout << "Account Holder: " << accountHolder << " | Balance: $" << balance << endl;
  }
};

int main() {
  BankAccount account("12345", "John", 1000.0);

  account.displayBalance();
  account.deposit(500.0);

  account.displayBalance();
  account.withdraw(200.0);

  account.displayBalance();
  account.withdraw(2000.0);
  account.displayBalance();

  return 0;
}
