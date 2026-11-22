class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        sort(nums.begin(),nums.end());
        for(int num:nums){
            if(st.empty()){
                st.push(num);
            }else if(num==st.top()){
                st.pop();
            }else{
                return st.top();
            }
        }
        return st.top();
    }
};