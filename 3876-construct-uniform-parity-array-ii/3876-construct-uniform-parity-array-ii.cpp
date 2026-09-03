class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;

        for(int x : nums1) {
            if(x % 2 == 0)
                smallestEven = min(smallestEven, x);
            else
                smallestOdd = min(smallestOdd, x);
        }

        // All elements already have same parity
        if(smallestOdd == INT_MAX || smallestEven == INT_MAX)
            return true;

        // Every even element needs a smaller odd element
        if(smallestOdd < smallestEven)
            return true;

        return false;
    }
};