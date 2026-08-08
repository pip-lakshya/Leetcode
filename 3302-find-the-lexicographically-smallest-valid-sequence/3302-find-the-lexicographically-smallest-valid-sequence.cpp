class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1);
        suf[n] = m;

        int j = m - 1;

        // Find how much of word2 can be matched from the right
        for(int i = n - 1; i >= 0; i--) {

            if(j >= 0 && word1[i] == word2[j])
                j--;

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        for(int i = 0; i < n; i++) {

            if(j == m)
                break;

            // Normal matching
            if(word1[i] == word2[j]) {

                ans.push_back(i);
                j++;
            }

            // Use our one mismatch
            else if(!changed && suf[i + 1] <= j + 1) {

                changed = true;
                ans.push_back(i);
                j++;
            }
        }

        if(j == m)
            return ans;

        return {};
    }
};