class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>v;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        int las=-1;
        while(i<n1 && j<n2)
        {
            if(nums1[i]==nums2[j])
            {
                if(las!=nums1[i])
                {
                    v.push_back(nums1[i]);
                    las=nums1[i];
                }
                i++;
                j++;
            }
            else if(nums1[i]>nums2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return v;
    }
};