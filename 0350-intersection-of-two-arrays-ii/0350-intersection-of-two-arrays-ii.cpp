class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0;
        while(i<nums1.size())
        {
            int j=0;
            while(j<nums2.size())
            {
                if(nums1[i]==nums2[j])
                {
                    ans.push_back(nums1[i]);
                    nums2[j]=INT_MIN;
                    break;
                }
                j++;
            }
            i++;
        }
        return ans;
    }
};