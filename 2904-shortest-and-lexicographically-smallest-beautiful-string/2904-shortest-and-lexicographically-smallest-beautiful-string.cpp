class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0;
        int r=0;
        int ones=0;
        int n=s.size();
        int minlen=INT_MAX;
        string ans="";
        while(r<n){
            if(s[r]=='1')ones++;
            while(ones==k){
                if(ones==k){
                    if(r-l+1<=minlen){
                        if(r-l+1==minlen){
                            if(ans>s.substr(l,r-l+1))ans=s.substr(l,r-l+1);
                        }
                        else ans=s.substr(l,r-l+1);
                        minlen=r-l+1;

                    }

                }
                if(s[l]=='1')ones--;
                l++;

            }
            r++;

        }
        return ans;
        
    }
};