class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > subset;
        vector<int> empty;
        subset.push_back( empty );

        for (int i = 0; i < nums.size(); i++)
        {
        vector< vector<int> > subsetTemp = subset;  //making a copy of given 2-d vector.

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( nums[i] );   // adding set[i] element to each subset of subsetTemp. like adding {2}(in 2nd iteration  to {{},{1}} which gives {{2},{1,2}}.

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );  //now adding modified subsetTemp to original subset (before{{},{1}} , after{{},{1},{2},{1,2}}) 
    }
    return subset;
    }
};