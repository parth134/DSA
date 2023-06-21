class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        // brute force
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(nums[i]+nums[j]==target)
        //         {
        //             return {i,j};
        //         }
                
        //     }
        // }
        // return{-1,-1};

        // optimised solution
        vector<pair<int,int>>v;
        for(int i=0; i<nums.size();++i){
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        int left=0,right=n-1;
        int sum;
        while(left<right)
        {
             sum=v[left].first+v[right].first;
            if(sum==target)
            {
                return {v[left].second,v[right].second};
            }
            else if(sum<target)
            {
                left++;
            }
            else if(sum>target)
            {
                right--;
            }
        }
        return {-1,-1};
    }
};