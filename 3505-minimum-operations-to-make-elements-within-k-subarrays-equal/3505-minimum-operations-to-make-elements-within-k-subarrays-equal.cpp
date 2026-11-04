class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> left, right;
        long long sumL = 0, sumR = 0;

        auto balance = [&]() {
            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();
                left.erase(left.find(v));
                sumL -= v;
                right.insert(v);
                sumR += v;
            }

            while (left.size() < right.size()) {
                int v = *right.begin();
                right.erase(right.find(v));
                sumR -= v;
                left.insert(v);
                sumL += v;
            }
        };

        auto add = [&](int v) {
            if (left.empty() || v <= *left.rbegin()) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = left.find(v);

            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                it = right.find(v);
                right.erase(it);
                sumR -= v;
            }
            balance();
        };

        auto getCost = [&]() -> long long {
            long long median = *left.rbegin();

            return median * left.size() - sumL
                 + sumR - median * right.size();
        };

        // Calculate the cost of every window of size x.
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < x; i++)
            add(nums[i]);

        cost[0] = getCost();

        for (int i = 1; i <= n - x; i++) {
            remove(nums[i - 1]);
            add(nums[i + x - 1]);
            cost[i] = getCost();
        }

        // DP: minimum cost to select j non-overlapping windows
        // from the first i elements.
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};