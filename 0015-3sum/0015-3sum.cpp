// Optimised approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sort the input array in ascending order
        vector<vector<int>> result; // Vector to store the resulting triplets
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int left = i + 1; // Pointer for the element on the left
            int right = n - 1; // Pointer for the element on the right
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right]; // Calculate the sum of three elements
                
                if (sum < 0)
                    left++; // Increment left pointer if sum is less than 0
                else if (sum > 0)
                    right--; // Decrement right pointer if sum is greater than 0
                else {
                    result.push_back({nums[i], nums[left], nums[right]}); // Found a triplet that sums to 0
                    
                    // Skip duplicate values for left and right
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    
                    left++; // Move left pointer towards the right
                    right--; // Move right pointer towards the left
                }
            }
        }
        
        return result; // Return the resulting vector of triplets
    }
};






// Brute force approach
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         set<vector<int>>result;
//         vector<vector<int>>output;
//         for(int i=0;i<n-2;i++)
//         {
//             for(int j=i+1;j<n-1;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
                    
//                     if(nums[i]+nums[j]+nums[k]==0)
//                     {
//                         result.insert({nums[i],nums[j],nums[k]});
//                     }
//                 }
//                 }
//             }
//             for(auto it:result)
//             {
//                 output.push_back(it);
//             }
        
//        return output;
//     }
// };