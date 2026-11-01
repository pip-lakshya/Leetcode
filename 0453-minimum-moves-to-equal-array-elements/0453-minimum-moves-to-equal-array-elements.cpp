class Solution {
public:
    int minMoves(vector<int>& nums) {
        // Find the minimum element in the array
        int min_val = *min_element(nums.begin(), nums.end());
        
        int moves = 0;
        // Sum up the differences between each element and the minimum
        for (int num : nums) {
            moves += (num - min_val);
        }
        
        return moves;
    }
};
