class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int x : nums) {
            st.insert(x);
        }

        int multiple = k;

        while(st.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};