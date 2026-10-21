class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        if (s == t) return 0;

        int n = s.size();
        bool allSame = true;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[0]) {
                allSame = false;
                break;
            }
        }

        if (allSame) return 0;

        if (n == 2) return -1;

        if (s[0] == t[0] || s[n - 1] == t[n - 1])
            return 1;

        if (s[0] == t[n - 1] && s[n - 1] == t[0]) {
            for (int i = 1; i < n - 1; i++) {
                if (s[i] == t[0] || s[i] == t[n - 1])
                    return 2;
            }
            return 3;
        }

        return 2;
    }
};