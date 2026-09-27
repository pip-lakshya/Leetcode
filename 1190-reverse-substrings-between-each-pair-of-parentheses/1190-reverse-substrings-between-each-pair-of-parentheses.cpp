class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        vector<int> pair(s.size(), -1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans;
        int i = 0;
        int dir = 1;

        while (i >= 0 && i < s.size()) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                dir = -dir;
            } else {
                ans += s[i];
            }
            i += dir;
        }

        return ans;
    }
};