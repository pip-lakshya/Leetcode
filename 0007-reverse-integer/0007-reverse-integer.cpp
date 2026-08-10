class Solution {
public:
    int reverse(int x) {
        long long temp = x;
        
        if(temp < 0)
            temp = -temp;

        long long rev=0;
        while(temp&&rev<pow(2,32)){
            rev*=10;
            rev+=(temp%10);
            temp/=10;
        }
        if(x < 0)
            rev = -rev;

        if(rev > INT_MAX || rev < INT_MIN)
            return 0;

        return (int)rev;
    }
};