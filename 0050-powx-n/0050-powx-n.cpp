class Solution {
public:
    double myPow(double x, int n) {
        if (n==0)
        {
            return 1;
        }
        if(n<0)
        {
            x=1/x;
            if(n==INT_MIN)
            {
                n=-(n+1);
                return x*myPow(x,n);
            }
            else
            {
                n=-n;
                return myPow(x,n);
            }
            
        }
        if(n==1)
        {
            return x;
        }
        
        double a = myPow(x,n/2);
        if(n&1)
        {
            return a * a *x;
        }
        else
        {
            return  a * a;      
        }
    }
};