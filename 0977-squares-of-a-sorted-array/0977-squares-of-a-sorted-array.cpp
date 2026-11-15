class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=size(nums);
        for(int i=0;i<n;i++){
            long long temp=nums[i];
            nums[i]=temp*temp;
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};