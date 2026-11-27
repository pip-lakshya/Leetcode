class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free_cnt(n, 0);
        int min_price = INT_MAX;

        // Precompute how many free copies buying item i once gives,
        // and track the cheapest single-item price for leftover budget.
        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            int pi = items[i][1];
            min_price = min(min_price, pi);

            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % fi == 0) {
                    free_cnt[i]++;
                }
            }
        }

        // 0/1 Knapsack: dp[b] = max copies obtained by buying each chosen item at most once with cost b
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; ++i) {
            int cost = items[i][1];
            int gain = 1LL + free_cnt[i];
            for (int b = budget; b >= cost; --b) {
                dp[b] = max(dp[b], dp[b - cost] + gain);
            }
        }

        // Spend any remaining budget greedily on the cheapest item
       int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra = (budget - b) / min_price;
            ans = max(ans, dp[b] + extra);
        }

        return ans;
    }
};
