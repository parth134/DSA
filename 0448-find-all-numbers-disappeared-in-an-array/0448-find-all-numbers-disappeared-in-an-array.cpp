class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // using hashset
        // unordered_set<int>s(begin(nums),end(nums));
        // vector<int>ans(size(nums)-size(s));
        // for(int i=1,j=0;i<=size(nums);i++)
        // {
           
        //     if(!s.count(i))
        //     {
        //         ans[j++]=i;
        //     }
        // }
        // return ans;

        // brute force
        // vector<int>ans;
        // for(int i=1;i<=nums.size();i++)
        // {
        //     if(find(nums.begin(),nums.end(),i)==nums.end())
        //     {
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        // sort & binary-search
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<=nums.size();i++)
        {
            if(!binary_search(nums.begin(),nums.end(),i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};