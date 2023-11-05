class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mpp;
        vector<string> arr = strs ;
        int n = strs.size();
        for(int i = 0 ;i < n; i++){
            sort(arr[i].begin(),arr[i].end());
            mpp[arr[i]].push_back(strs[i]);
        }
        vector<vector<string>> ans ;
        for(auto it : mpp){
            vector<string> temp ;
            for(int i = 0 ;i <it.second.size(); i++){
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};