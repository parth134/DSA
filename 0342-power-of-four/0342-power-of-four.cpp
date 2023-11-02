class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
        {
            return false;
        }
        if(n==1)
        {
            return true;
        }
        double logar=log(n)/log(4);
        return (logar==(int)logar);
    }
};