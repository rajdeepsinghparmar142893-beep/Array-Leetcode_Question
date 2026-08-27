#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = getValue(s[i]);
            int nextVal = 0;

            // Check if there is a next character
            if (i + 1 < n) {
                nextVal = getValue(s[i + 1]);
            }

            // If current is smaller than next, it's a subtraction case (e.g., IV, IX)
            if (currentVal < nextVal) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }

        return total;
    }

private:
    // Helper function to get value without a map
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
};