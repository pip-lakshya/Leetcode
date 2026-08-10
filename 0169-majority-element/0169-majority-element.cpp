class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> hash;
        for(int i=0;i<n;i++){
              if(i > 0 && nums[i] == nums[i-1])
                continue;
            hash.push_back({nums[i],1});
            for(int j=i+1;j<n;j++){
                if(nums[j] == nums[i]) {
                    hash.back()[1]++;
                }else{
                    break;
                }
            }
        }
        for(int i=0;i<hash.size();i++){
           if(hash[i][1]>n/2)
           return hash[i][0];
        }
        return -1;
    }
};