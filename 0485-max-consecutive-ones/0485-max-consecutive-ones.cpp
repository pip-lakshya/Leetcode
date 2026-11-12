class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int n=size(nums);
       int max1=0;
       int curr1=0;
       if(nums[0]==1){
        max1=1;
        curr1=1;
       }
       for(int i=0;i<n-1;i++){
        if(nums[i]==1&&nums[i+1]==1){
            curr1++;
        }else if(nums[i+1]!=1){
           curr1=0;
        }else if(nums[i+1]==1){
            curr1=1;
        }
        max1=max(max1,curr1); 
       }
       return max1;
    }
};