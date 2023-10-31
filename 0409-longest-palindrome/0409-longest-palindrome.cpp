class Solution {
public:
    int longestPalindrome(string s) {
        int lower[26] = {0};
        int upper[26] = {0};
        int count = 0;
        bool odd = 1;

        for(char c: s){
            if(c-97 >= 0) lower[c-97]++;
            else upper[c-65]++;
        }

        for(int i=0; i<26; i++){
            if(lower[i]%2 == 0)
                count+=lower[i];
            else{
                if(odd){
                    count+=lower[i];
                    odd = !odd;
                }
                else count+=lower[i]-1;
            }
        }

        for(int i=0; i<26; i++){
            if(upper[i]%2 == 0)
                count+=upper[i];
            else{
                if(odd){
                    count+=upper[i];
                    odd = !odd;
                }
                else count+=upper[i]-1;
            }
        }
        return count;
    }
};