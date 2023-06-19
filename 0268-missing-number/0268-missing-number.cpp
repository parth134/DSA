class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int missing=0;
        vector<int>count(n+1,0);
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(count[i]==0)
            {
                missing=i;
            }
        }
        return {missing};
    }
};