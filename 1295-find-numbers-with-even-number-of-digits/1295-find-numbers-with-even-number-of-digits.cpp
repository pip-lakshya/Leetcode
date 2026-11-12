class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=size(nums);
        int count=0;
        for(int i=0;i<n;i++){
            int curr=0;
            while(nums[i]!=0){
                nums[i]/=10;
                curr++;
            }
            if(curr%2==0){
            count++;}
            }
        return count;
    }
};