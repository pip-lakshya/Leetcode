class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long c1 = cost1, c2 = cost2, cb = costBoth;
        long long n1 = need1, n2 = need2;
        
        long long ov = min(n1, n2);
        long long mx = max(n1, n2);
        long long d = n1 - n2;
        
        // A: cover everything with combos
        long long a = mx * cb;
        // B: cover overlap with combos, remainder with dedicated items
        long long b = ov * cb + abs(d) * (d > 0 ? c1 : c2);
        // C: no combos at all
        long long c = n1 * c1 + n2 * c2;
        
        return min({a, b, c});
    }
};