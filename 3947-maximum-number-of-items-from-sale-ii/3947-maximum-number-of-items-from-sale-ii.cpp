#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        long long rem_budget = budget;
        
        // 1. Count frequency of each factor and find the global minimum price
        vector<int> freq(n + 1, 0);
        long long min_price = 2e9; // Larger than max possible price (10^9)
        
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            freq[f]++;
            min_price = min(min_price, p);
        }
        
        // 2. Precompute number of multiples for each factor in O(N log N)
        vector<int> multiples(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (freq[f] > 0) {
                for (int mult = f; mult <= n; mult += f) {
                    multiples[f] += freq[mult];
                }
            }
        }
        
        // 3. Collect all 2-yield bundles: {price, available_count}
        vector<pair<long long, long long>> bundles;
        bundles.reserve(n);
        for (const auto& item : items) {
            int f = item[0];
            long long p = item[1];
            long long count = multiples[f] - 1;
            if (count > 0) {
                bundles.push_back({p, count});
            }
        }
        
        // Sort bundles from cheapest to most expensive
        sort(bundles.begin(), bundles.end());
        
        long long total_items = 0;
        
        // 4. Greedily buy 2-yield bundles while they beat buying two min_price items
        for (const auto& [p, count] : bundles) {
            if (p > rem_budget || p > 2 * min_price) {
                break;
            }
            
            long long take = min(count, rem_budget / p);
            total_items += take * 2;
            rem_budget -= take * p;
        }
        
        // 5. Spend all remaining budget on the single cheapest item (1-yield)
        total_items += rem_budget / min_price;
        
        return total_items;
    }
};
