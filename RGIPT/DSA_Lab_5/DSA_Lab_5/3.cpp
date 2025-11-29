#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <cmath>

int precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  return 0;
}

std::string infix_to_postfix(const std::string& expression) {
  std::stack<char> s;
  std::string output = "";
  for (char ch : expression) {
    if (isdigit(ch)) {
      output += ch;
    }
    else if (ch == '(') {
      s.push(ch);
    }
    else if (ch == ')') {
      while (!s.empty() && s.top() != '(') {
        output += s.top();
        s.pop();
      }
      if (!s.empty()) s.pop();
    }
    else {
      while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(ch)) {
        output += s.top();
        s.pop();
      }
      s.push(ch);
    }
  }
  while (!s.empty()) {
    output += s.top();
    s.pop();
  }
  return output;
}

double evaluate_postfix(const std::string& expr) {
  std::stack<double> s;
  for (char ch : expr) {
    if (isdigit(ch)) {
      s.push(ch - '0');
    }
    else {
      double val2 = s.top(); s.pop();
      double val1 = s.top(); s.pop();
      switch (ch) {
      case '+': s.push(val1 + val2); break;
      case '-': s.push(val1 - val2); break;
      case '*': s.push(val1 * val2); break;
      case '/': s.push(val1 / val2); break;
      }
    }
  }
  return s.top();
}

int main() {
  std::vector<std::string> test_expressions = { "3+(2*4)", "5*(6-2)/2", "9/(3-0)" };

  for (const auto& exp : test_expressions) {
    std::string postfix = infix_to_postfix(exp);
    double value = evaluate_postfix(postfix);

    std::cout << "Infix: " << exp
      << " -> Postfix: " << postfix
      << " -> Evaluated Value: " << value << std::endl;
  }
  return 0;
}
