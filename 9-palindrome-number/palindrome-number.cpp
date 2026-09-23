class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int original =x;
        int long half = 0;
        while (x!=0) {          // stop when half >= remaining x
            half = half * 10 + x % 10;
            x /= 10;
        }
        // even length: half == x ; odd length: middle digit drops off
        return original==half;
    }
};
