class Solution {
    public:
        string reverseVowels(string s) {
        string word=s;
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";
        
        while (start < end) {
            // Move start pointer until it points to a vowel
            while (start < end && vowels.find(word[start]) == -1) {
                start++;
            }
            
            // Move end pointer until it points to a vowel
            while (start < end && vowels.find(word[end]) == -1) {
                end--;
            }
            
            // Swap the vowels
           swap(word[start],word[end]);
            
            // Move the pointers towards each other
            start++;
            end--;
        }
        
        
        return word;
    }
};