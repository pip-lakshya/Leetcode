class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            int step_cost = costs[i - 1]; // 1-indexed conversion
            
            for (int k = max(0, i - 3); k < i; ++k) {
                int jump_dist = i - k;
                int jump_cost = step_cost + (jump_dist * jump_dist);
                dp[i] = min(dp[i], dp[k] + jump_cost);
            }
        }

        return dp[n];
    }
};
