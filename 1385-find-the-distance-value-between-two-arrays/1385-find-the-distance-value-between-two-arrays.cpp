class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distanceValue = 0;
        sort(arr2.begin(), arr2.end());

        for (int num : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), num);
            
            bool isValid = true;
            
            if (it != arr2.end() && *it - num <= d) {
                isValid = false;
            }
            
            if (isValid && it != arr2.begin() && num - *(it - 1) <= d) {
                isValid = false;
            }
            
            if (isValid) {
                distanceValue++;
            }
        }

        return distanceValue;
    }
};
