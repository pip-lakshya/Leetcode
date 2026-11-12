class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=size(digits);
        if(digits[n-1]<9){
            digits[n-1]+=1;
            return digits;
        }
        int i=n-1;
        while(i>=0){
            if(digits[i]+1==10){
                digits[i]=0;
                i--;
            }else if(digits[i]+1!=10){
                digits[i]++;
                return digits;
               }
            if(i==0){
                if(digits[i]+1!=10){
                    digits[i]++;
                    return digits;
                }
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};