class Solution {
public:

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // All subsets
        for(int mask = 1; mask < (1 << n); mask++) {

            long long L = 1;
            int bits = 0;

            for(int i = 0; i < n; i++) {

                if(mask & (1 << i)) {

                    L = lcm(L, coins[i]);
                    bits++;

                    if(L > x)
                        break;
                }
            }

            if(L > x)
                continue;

            // Odd number of elements -> add
            if(bits % 2 == 1)
                ans += x / L;

            // Even number of elements -> subtract
            else
                ans -= x / L;
        }

        return ans;
    }


    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        // Maximum possible kth answer
        long long high = 1LL * (*min_element(coins.begin(),
                                             coins.end())) * k;

        while(low < high) {

            long long mid = low + (high - low) / 2;

            if(count(mid, coins) >= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};