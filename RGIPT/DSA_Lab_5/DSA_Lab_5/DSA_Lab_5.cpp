#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <sstream>

void sort_stack(const std::vector<int>& input_list) {
  std::stack<int> main_stack;
  std::stack<int> temp_stack;

  for (int num : input_list) {
    while (!main_stack.empty() && main_stack.top() > num) {
      temp_stack.push(main_stack.top());
      main_stack.pop();
    }

    main_stack.push(num);

    while (!temp_stack.empty()) {
      main_stack.push(temp_stack.top());
      temp_stack.pop();
    }
  }

  std::vector<int> sorted_vec;
  while (!main_stack.empty()) {
    sorted_vec.push_back(main_stack.top());
    main_stack.pop();
  }
  std::reverse(sorted_vec.begin(), sorted_vec.end());

  std::cout << "Final Sorted Stack (bottom -> top): [";
  for (size_t i = 0; i < sorted_vec.size(); ++i) {
    std::cout << sorted_vec[i] << (i == sorted_vec.size() - 1 ? "" : ", ");
  }
  std::cout << "]" << std::endl;
}

void print_input(const std::vector<int>& input) {
  std::cout << "Input set of integers: ";
  for (int val : input) {
    std::cout << val << " ";
  }
  std::cout << std::endl;
}

int main() {

  std::cout << "Test Case 1: Required Example" << std::endl;
  std::vector<int> test1 = { 6, 5, 3, 2, 1, 1, 3, 4, 8, 5, 9, 6, 7 };
  print_input(test1);
  sort_stack(test1);
  std::cout << std::endl;

  std::cout << "Test Case 2: Reversed Order" << std::endl;
  std::vector<int> test2 = { 10, 8, 6, 4, 2 };
  print_input(test2);
  sort_stack(test2);
  std::cout << std::endl;

  std::cout << "Test Case 3: Mixed Negatives and Positives" << std::endl;
  std::vector<int> test3 = { 5, -3, 0, 1, -1, 4 };
  print_input(test3);
  sort_stack(test3);

  return 0;
}
