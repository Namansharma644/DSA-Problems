class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0;
        int product=1;
        while(n!=0)
        {
            int lastDigit=n%10;
            sum+=lastDigit;
            product*=lastDigit;
            n/=10;
        }
        return product-sum;
    }
};