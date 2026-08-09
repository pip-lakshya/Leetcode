class Solution {
public:
    vector<vector<int>> dp;
    vector<int> sum;

    int rec(int i, int m, vector<int>& piles) {
        int n = piles.size();

        if (i == n)
            return 0;

        if (dp[i][m] != -1)
            return dp[i][m];

        int total = sum[i];
        int ans = 0;

        for (int x = 1; x <= 2 * m && i + x <= n; x++) {
            ans = max(ans, total - rec(i + x, max(m, x), piles));
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix sum
        sum.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
            sum[i] = piles[i] + sum[i + 1];

        dp.assign(n, vector<int>(n + 1, -1));

        return rec(0, 1, piles);
    }
};