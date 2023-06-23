class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0)
        {
            return false;
        }
        int nums=x;
        int r;
        long long t=0;
        while(x>0)
        {
            r=x%10;
            t=(t*10)+r;
            x=x/10;
           
        }
        if(nums==t)
        {
            return true;
        }
        return false;
        }
    
};