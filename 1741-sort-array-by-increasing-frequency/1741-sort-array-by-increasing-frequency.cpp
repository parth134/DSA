class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        else{
            return a.second>b.second;
        }
       
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        vector<int>ans;
        map<int,int>mapp;
        for(int i=0;i<n;i++)
        {
            mapp[nums[i]]++;
        }
        for(auto it:mapp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),comp);
        int cnt=0;
        for(auto it:v)
        {
            cnt=it.first;
            while(cnt--)
            {
                ans.push_back(it.second);
            }
           
        }
        return ans;
    }
};