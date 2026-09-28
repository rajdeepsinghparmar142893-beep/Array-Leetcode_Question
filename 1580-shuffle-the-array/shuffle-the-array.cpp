class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);       // x_i
            result.push_back(nums[n + i]);   // y_i
        }
        return result;

    }
};