class Solution {
    bool isRotation(vector<int>& a, vector<int>& b) {
        int k = a.size();

        vector<int> pi(k, 0);
        for (int i = 1; i < k; i++) {
            int j = pi[i - 1];

            while (j > 0 && b[i] != b[j])
                j = pi[j - 1];

            if (b[i] == b[j])
                j++;

            pi[i] = j;
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int x = a[i % k];

            while (j > 0 && x != b[j])
                j = pi[j - 1];

            if (x == b[j])
                j++;

            if (j == k)
                return true;
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;

            for (int start = 0; start < n && ok; start += k) {
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);

                vector<int> b(sorted.begin() + start,
                              sorted.begin() + start + k);

                if (!isRotation(a, b))
                    ok = false;
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};