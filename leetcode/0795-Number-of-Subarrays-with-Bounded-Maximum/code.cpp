// Problem: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
// Method: sliding window

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int low, int high) {
        int n = nums.size();
        int res = 0, windowSize = 0;
        
        for (int l = 0, r = 0; r < n; ++r) {
            if (nums[r] >= low && nums[r] <= high) {
                windowSize = r - l + 1;
            }
            else if (nums[r] > high) {
                windowSize = 0;
                l = r + 1;
            }
            res += windowSize;
        }
        return res;
    }
};