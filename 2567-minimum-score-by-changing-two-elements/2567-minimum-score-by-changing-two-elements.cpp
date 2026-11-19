class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int changeTwoSmallest = nums[n - 1] - nums[2];
        int changeTwoLargest  = nums[n - 3] - nums[0];
        int changeBothEnds    = nums[n - 2] - nums[1];
        
        return min({changeTwoSmallest, changeTwoLargest, changeBothEnds});
    }
};
