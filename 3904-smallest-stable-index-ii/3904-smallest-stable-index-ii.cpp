class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = max(prefix[i - 1], nums[i]);
        }

        vector<int> postfix(n);
        postfix[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            postfix[i] = min(postfix[i + 1], nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] - postfix[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};
