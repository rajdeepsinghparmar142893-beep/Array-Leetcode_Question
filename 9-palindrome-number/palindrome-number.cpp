class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int half = 0;
        while (half < x) {          // stop when half >= remaining x
            half = half * 10 + x % 10;
            x /= 10;
        }
        // even length: half == x ; odd length: middle digit drops off
        return half == x || half / 10 == x;
    }
};
