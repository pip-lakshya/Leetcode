class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10, k = 0;    // x = stones to remove this turn, k = turn count
        while (n >= x) {
            n -= x;
            --x;
            ++k;
        }
        return k % 2 == 1;    // odd turns → Alice wins
    }
};