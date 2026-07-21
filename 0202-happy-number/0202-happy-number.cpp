class Solution {
public:
    int getNext(int n)
    {
        int sum=0;

        while(n!=0)
        {
            int lastDigit=n%10;
            sum+=lastDigit*lastDigit;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int>st;

        while(n!=1 && st.find(n)==st.end())
        {
            st.insert(n);
            n=getNext(n);
        }

        return n==1;
    }
};