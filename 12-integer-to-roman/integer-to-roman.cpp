class Solution {
public:
    string intToRoman(int num) {
        // Define the mapping of values to Roman numerals, including subtractive cases
        vector<pair<int, string>> values = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        string result = "";
        
        // Iterate through each value and append the corresponding Roman numeral
        for (auto& [value, symbol] : values) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        
        return result;
    }
};