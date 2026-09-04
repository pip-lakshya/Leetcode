class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffix(n);
        suffix[n - 1] = nums[n - 1];

        // suffix minimum
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = min(nums[i], suffix[i + 1]);
        }

        int prefMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefMax = max(prefMax, nums[i]);

            if (prefMax - suffix[i] <= k)
                return i;
        }

        return -1;
    }
};