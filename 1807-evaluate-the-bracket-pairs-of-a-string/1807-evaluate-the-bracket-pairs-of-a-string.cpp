class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        
        for (auto &v : knowledge) {
            mp[v[0]] = v[1];
        }
        
        string ans;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '(') {
                ans += s[i];
                continue;
            }
            
            int j = i + 1;
            string key;
            
            while (s[j] != ')') {
                key += s[j];
                j++;
            }
            
            if (mp.count(key))
                ans += mp[key];
            else
                ans += "?";
            
            i = j;
        }
        
        return ans;
    }
};