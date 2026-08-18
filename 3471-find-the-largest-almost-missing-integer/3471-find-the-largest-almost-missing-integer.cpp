class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1)
                    ans = max(ans, x);
            }

            return ans;
        }

        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        int first = nums[0];
        int last = nums[n - 1];

        int firstCount = 0;
        int lastCount = 0;

        for (int x : nums) {
            if (x == first)
                firstCount++;

            if (x == last)
                lastCount++;
        }

        int ans = -1;

        if (firstCount == 1)
            ans = max(ans, first);

        if (lastCount == 1)
            ans = max(ans, last);

        return ans;
    }
};