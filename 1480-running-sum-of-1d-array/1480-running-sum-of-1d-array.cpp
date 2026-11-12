class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=size(nums);
        if(n<=1) return nums;

        vector<int> res(n);
        int curr=nums[0];
        res[0]=nums[0];
        for(int i=1;i<n;i++){
            res[i]=curr+nums[i];
            curr=res[i];
        }
        return res;
    }
};