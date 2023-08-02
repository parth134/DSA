class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    bool fl = false;
                    int ele;
                    for(int k=j+1;k<m;k++){
                        if(nums2[k] > nums2[j]){
                            ele = nums2[k];
                            fl = true;
                            break;
                        }
                    }
                    if(fl){
                        ans.push_back(ele);
                    }else{
                        ans.push_back(-1);
                    }
                }
            }
        }
        return ans;
    }
};