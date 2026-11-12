class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=size(prices);
        int maxprofit=0;
        int minp=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]<minp){
            minp=prices[i];
            }
            if(prices[i]-minp>maxprofit){
                maxprofit=prices[i]-minp;
            }
        }
        return maxprofit;
    }
};