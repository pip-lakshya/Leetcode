class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=size(nums);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.contains(target-nums[i])){
                return {mp.find(target-nums[i])->second,i};
            }
            mp[nums[i]]=i;
        }
        vector<int> res;
        return res;
        }
};