class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        deque<pair<int, int>> dq; // {value, count}
        
        int r = n - 1;
        for (int l = n - 1; l >= 0; --l) {
            int val = nums[l];
            int count = 1;
            
            while (!dq.empty() && dq.front().first <= val) {
                auto [frontVal, frontCnt] = dq.front();
                dq.pop_front();
                cost += 1LL * (val - frontVal) * frontCnt;
                count += frontCnt;
            }
            dq.push_front({val, count});
            
            while (cost > k) {
                auto& [backVal, backCnt] = dq.back();
                cost -= (backVal - nums[r]);
                backCnt--;
                if (backCnt == 0) {
                    dq.pop_back();
                }
                r--;
            }
            
            ans += (r - l + 1);
        }
        
        return ans;
    }
};
