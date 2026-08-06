class Solution {
public:
    int product(int n){
        int temp=n;
        int prod=1;
        while(temp){
            int rem=temp%10;
            prod*=rem;
            temp/=10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int prod=product(n);
        while(prod%t!=0){
            prod=product(++n);
        }
        return n;
    }
};