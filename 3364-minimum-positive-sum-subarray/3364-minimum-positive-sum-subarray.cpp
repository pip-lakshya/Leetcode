class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=size(nums);
        int mins=INT_MAX;
        for(int k=l;k<=r;k++){
        int curr=0;
            for(int i=0;i<n;i++){
                if(i<k){
                curr+=nums[i];
                }else{
                    curr-=nums[i-k];
                    curr+=nums[i];
                }
                if(i>=k-1){
                if(curr>0&&curr<mins){
                    mins=curr;
                }
                }
            }
        }
        if(mins==INT_MAX){
            return -1;
        }
        return mins;
    }
};
