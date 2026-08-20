class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;
        if(nums.size()<3){
           return nums;
        }
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i=2;
        while(i<nums.size()){
            if(arr1.back()>arr2.back()){
                arr1.push_back(nums[i++]);
            }else{
                arr2.push_back(nums[i++]);
            }
        }
        vector<int> result;
        for(int i=0;i<arr1.size();i++){
            result.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            result.push_back(arr2[i]);
        }
        return result;
    }
};