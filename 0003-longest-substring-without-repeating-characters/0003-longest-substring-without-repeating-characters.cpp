class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int maxi = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_set<char> res;
            int j = i;
            while (j < s.length() && res.find(s[j]) == res.end()) {
                res.insert(s[j]);
                j++;
            }
            maxi = max(maxi, j - i);
        }
        return maxi;
    }
};
