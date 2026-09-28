class Solution {
public:
    int maxDepth(string s) {
        int maxe=0;
        int currmax=0;
        for(auto ch:s){
            if(ch=='('){
                currmax++;
                maxe=max(currmax,maxe);
            }else if(ch==')'){
                currmax--;
            }
        }
        return maxe;
    }
};