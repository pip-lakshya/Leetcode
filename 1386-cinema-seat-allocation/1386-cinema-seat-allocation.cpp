class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        // Store reserved seats row-wise
        for (auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }

        int ans = (n - mp.size()) * 2;

        for (auto &p : mp) {

            unordered_set<int> &s = p.second;

            // Family in seats 2,3,4,5
            bool left = !s.count(2) &&
                        !s.count(3) &&
                        !s.count(4) &&
                        !s.count(5);

            // Family in seats 4,5,6,7
            bool middle = !s.count(4) &&
                          !s.count(5) &&
                          !s.count(6) &&
                          !s.count(7);

            // Family in seats 6,7,8,9
            bool right = !s.count(6) &&
                         !s.count(7) &&
                         !s.count(8) &&
                         !s.count(9);

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};