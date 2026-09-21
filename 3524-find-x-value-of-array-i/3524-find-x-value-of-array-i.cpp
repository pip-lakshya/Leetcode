class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int cur = num % k;
            vector<long long> next(k, 0);

            // Start a new subarray with current element
            next[cur]++;

            // Extend all previous subarrays
            for (int rem = 0; rem < k; rem++) {
                int newRem = (rem * cur) % k;
                next[newRem] += dp[rem];
            }

            // Add all subarrays ending here to final answer
            for (int rem = 0; rem < k; rem++) {
                ans[rem] += next[rem];
            }

            dp = next;
        }

        return ans;
    }
};