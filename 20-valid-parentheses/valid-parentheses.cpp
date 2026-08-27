#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    // Custom Stack implementation
    class Stack {
    private:
        char* data;
        int topIndex;
        int capacity;

    public:
        Stack(int size) {
            capacity = size;
            data = new char[capacity];
            topIndex = -1;
        }

        ~Stack() {
            delete[] data;
        }

        // Check if stack is empty
        bool empty() {
            return topIndex == -1;
        }

        // Check if stack is full
        bool isFull() {
            return topIndex == capacity - 1;
        }

        // Push element onto stack
        void push(char val) {
            if (isFull()) {
                // In this problem, stack won't exceed string length, 
                // but good to handle logically
                return; 
            }
            data[++topIndex] = val;
        }

        // Pop element from stack
        char pop() {
            if (empty()) {
                return '\0'; // Return null char if empty
            }
            return data[topIndex--];
        }

        // Peek at top element
        char peek() {
            if (empty()) {
                return '\0';
            }
            return data[topIndex];
        }
    };

    // Helper function to check if two characters match as a pair
    bool isMatch(char open, char close) {
        if (open == '(' && close == ')') return true;
        if (open == '{' && close == '}') return true;
        if (open == '[' && close == ']') return true;
        if (open == '<' && close == '>') return true;
        return false;
    }

public:
    bool isValid(string s) {
        int n = s.length();
        Stack stack(n); // Initialize stack with max possible size

        for (int i = 0; i < n; i++) {
            char current = s[i];

            // If it's an opening bracket, push to stack
            if (current == '(' || current == '{' || current == '[') {
                stack.push(current);
            } 
            // If it's a closing bracket
            else if (current == ')' || current == '}' || current == ']') {
                // If stack is empty, no matching opening bracket
                if (stack.empty()) {
                    return false;
                }

                char top = stack.pop();
                // Check if the popped opening bracket matches the current closing one
                if (!isMatch(top, current)) {
                    return false;
                }
            }
        }

        // String is valid only if stack is empty (all brackets matched)
        return stack.empty();
    }
};