class Solution {
public:
         //You can use lower_bound stl function if you wanna skip this part. 
          //this is implementation of that function.
                 
         int binary_search(vector<int>& arr ,int x){
            int s = 0;
            int e = arr.size()-1;
            int ans = e;
            while(s<=e){
                int mid = s+(e-s)/2;

                if(arr[mid] >= x){
                    ans = mid;
                    e = mid - 1;
                }
                else if(arr[mid] < x){
                    s = mid  + 1;
                }
                else{
                    e = mid - 1;
                }
            }
            return ans;  //to find 'x' as lowerbound
        }
        

     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
             int hi = binary_search(arr,x);
             int lo = hi-1;
             while(k--){

                if(lo < 0){             
                    hi++;
                }
                 else if(hi >= arr.size()){
                    lo--;
                }
                else if(x-arr[lo] <= arr[hi]-x){
                    lo--;
                }
                else{
                    hi++;
                }
         }
             return vector<int>(arr.begin() + lo + 1 , arr.begin() + hi);
    }
};