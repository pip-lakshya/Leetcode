class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, bitset<3>> present; // tracks which arrays contain each number

        for (int x : nums1) present[x].set(0);
        for (int x : nums2) present[x].set(1);
        for (int x : nums3) present[x].set(2);

        vector<int> result;
        for (auto& [num, bits] : present) {
            if (bits.count() >= 2) {
                result.push_back(num);
            }
        }
        return result;
    }
};