class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        long left = 1, right = x;
        long ans = 1;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};