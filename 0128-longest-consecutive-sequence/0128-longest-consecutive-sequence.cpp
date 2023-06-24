class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        int longestsequence=0;
        int currentsequence=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(nums[i]==nums[i-1]+1)
                {
                    currentsequence++;
                }
                else
                {
                    longestsequence=max(longestsequence,currentsequence);
                    currentsequence=1;
                }
    
        }
        }
        return max(longestsequence,currentsequence);
    }
    //     int n=nums.size();
    //     if(n==0)
    //     {
    //         return 0;
    //     }
    //     sort(nums.begin(),nums.end());
    //     set<int>result;
    //     bool flag = false;
    //     int c=0;
    //     int max=0;
    //    for(int i=0;i<n;i++)
    //    {
    //        result.insert(nums[i]);
    //    }
    //    vector<int>output;
    //    for(auto it:result)
    //    {
    //        output.push_back(it);
    //    }
    //    for(int i=0;i<output.size()-1;i++)
    //    {
    //        if(output[i]<output[i+1] && output[i+1]-output[i]==1)
    //        {
    //         c++;
    //         flag=true;   
    //        }
    //        else{
    //            if(flag){
    //                if(max<c)
    //                {
    //                    max=c;
    //                }
    //             c=0;
    //             flag=false;
    //            }
    //        }
    //    }

    //    if(flag){

    //        if(max<c)
    //        {
    //            max=c;
    //        }
    //    }

    //    return max+1;

    // }
};