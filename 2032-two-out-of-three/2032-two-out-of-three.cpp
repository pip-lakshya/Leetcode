class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        vector <bool> arr1 (101) ; 
        for (auto x : nums1)
        arr1[x] = true ;

        vector <bool> arr2 (101) ; 
        for (auto x : nums2)
        arr2[x] = true  ; 

        vector <bool> arr3 (101) ; 
        for (auto x : nums3)
        arr3[x] = true ; 

        vector <int> ans ; 
        int count = 0 ; 

        for (int i = 1 ; i < 101 ; i++)
        {
            if (arr1[i])
            count++; 
            if (arr2[i])
            count++ ; 
            if (arr3[i])
            count++ ;

            if (count > 1)
            ans.push_back(i) ; 

            count = 0 ; 
        }

        return ans ; 
    }
};