#include <vector>
#include <algorithm>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // Create a temporary copy of the input vector
        vector<int> temp;
        temp = nums;
        
        // Sort the temporary vector
        sort(temp.begin(), temp.end());
        
        // Get the size of the input vector
        int n = nums.size();
        
        // Initialize the indices for the unsorted subarray
        int i = 0, j = n - 1;
        
        // Find the first index where the elements differ between the input and temporary vectors
        for (i = 0; i < n; i++) {
            if (nums[i] != temp[i]) {
                break;
            }
        }
        
        // Find the last index where the elements differ between the input and temporary vectors
        for (j = n - 1; j >= 0; j--) {
            if (nums[j] != temp[j]) {
                break;
            }
        }
        
        // Calculate the length of the unsorted subarray
        int c = 0;
        for (int k = i; k <= j; k++) {
            c++;
        }
        
        // Return the length of the unsorted subarray
        return c;
    }
};
