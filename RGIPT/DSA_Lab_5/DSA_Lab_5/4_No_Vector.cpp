#include <iostream>
#include <stack>
#include <sstream>

template <size_t N>
void print_input(const int (&input)[N]) {
    std::cout << "Input set of integers: ";
    for (size_t i = 0; i < N; ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

void sort_stack(std::stack<int> input_stack) {
    std::stack<int> sorted_stack;
    std::stack<int> temp_stack;

    while (!input_stack.empty()) {
        int num = input_stack.top();
        input_stack.pop();

        while (!sorted_stack.empty() && sorted_stack.top() > num) {
            temp_stack.push(sorted_stack.top());
            sorted_stack.pop();
        }

        sorted_stack.push(num);

        while (!temp_stack.empty()) {
            sorted_stack.push(temp_stack.top());
            temp_stack.pop();
        }
    }
    
    std::stack<int> display_stack;
    while (!sorted_stack.empty()) {
        display_stack.push(sorted_stack.top());
        sorted_stack.pop();
    }

    std::cout << "Final Sorted Stack (bottom -> top): [";
    while (!display_stack.empty()) {
        std::cout << display_stack.top();
        display_stack.pop();
        if (!display_stack.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

template <size_t N>
std::stack<int> array_to_stack(const int (&arr)[N]) {
    std::stack<int> s;
    for (size_t i = N; i > 0; --i) {
        s.push(arr[i-1]);
    }
    return s;
}

int main() {
    
    std::cout << "--- Q.4 Stack Sorting Program (No Vector) ---" << std::endl;
    
    std::cout << "Test Case 1: Required Example" << std::endl;
    int test1[] = { 6, 5, 3, 2, 1, 1, 3, 4, 8, 5, 9, 6, 7 };
    print_input(test1);
    sort_stack(array_to_stack(test1));
    std::cout << std::endl;

    std::cout << "Test Case 2: Reversed Order" << std::endl;
    int test2[] = { 10, 8, 6, 4, 2 };
    print_input(test2);
    sort_stack(array_to_stack(test2));
    std::cout << std::endl;

    std::cout << "Test Case 3: Mixed Negatives and Positives" << std::endl;
    int test3[] = { 5, -3, 0, 1, -1, 4 };
    print_input(test3);
    sort_stack(array_to_stack(test3));

    return 0;
}
