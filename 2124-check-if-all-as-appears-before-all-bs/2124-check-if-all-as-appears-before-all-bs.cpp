class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int f=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                f=1;
            }
            if(f==1&&s[i]=='a'){
                return 0;
            }
        }
        return 1;
    }
};