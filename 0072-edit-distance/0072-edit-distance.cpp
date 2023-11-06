class Solution {
public:

    // Top Down

    // int dp[505][505];

    // int helper(string s1, string s2, int i, int j){
    //     if(i>=s1.length()) return s2.length()-j;
    //     if(j>=s2.length()) return s1.length()-i;
        
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s1[i]==s2[j])  return dp[i][j] =  helper(s1,s2,i+1,j+1);
    //     else{
    //         int a = 1+helper(s1,s2,i+1,j+1);   //replace char at i;
    //         int b = 1+helper(s1,s2,i+1,j);    // delete char at i
    //         int c = 1+helper(s1,s2,i,j+1);     // insert char at i;

    //         return dp[i][j] = min(a,min(b,c));
    //     }
    // }

    // Bottom Up

    static int helper2(string s1, string s2){
        int dp[505][505];
        memset(dp,0,sizeof dp);

        for(int j=0; j<s2.size(); j++){    //  base case
            int i=s1.size();
            dp[i][j] = s2.size()-j;
        }

        for(int i=0; i<s1.size(); i++){    // base case
            int j=s2.size();
            dp[i][j] = s1.size()-i;
        }

        for(int i=s1.size()-1; i>=0; i--){
            for(int j=s2.size()-1; j>=0; j--){
                if(s1[i]==s2[j])  dp[i][j] =  dp[i+1][j+1];
                else{
                    int a = 1+dp[i+1][j+1];   //replace char at i;
                    int b = 1+dp[i+1][j];    // delete char at i
                    int c = 1+dp[i][j+1];     // insert char at i;

                    dp[i][j] = min(a,min(b,c));
                }       
            }
        }
        return dp[0][0];
    }


    int minDistance(string s1, string s2) {
        if(s1.length()==0) return s2.length();
        return helper2(s1,s2);
    }
};