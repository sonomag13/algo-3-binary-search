// LeetCode 540. Single Element in a Sorted Array
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
                
        int l = 0, r = nums.size() - 1; 
        
        while (l + 1 < r) {
            
            int m = l + (r - l) / 2;             
            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                return nums[m];
            }
            
            /**
             * Notice that C++ is 0-index
             * conditions of no single element in [l, m]
             *  - m is even and it is equal to m - 1
             *  - m is odd and it is equal to m + 1 
             **/ 
            bool cond1 = (m % 2 == 0) && nums[m] == nums[m + 1];            
            bool cond2 = (m % 2 == 1) && nums[m] == nums[m - 1];
            
            if (cond1 || cond2) {
                l = m + 1;
            }
            else {
                r = m - 1; 
            }
        }
        
        /**
         * hereby l + 1 = r and we want to return mid = (l + r) / 2
         * Notice that numerically (l + r)/2 = l
         * 
         * However, there is one exemption of r = size - 1, means
         * r has never moved, meaning [0, r) is always normal, such that
         * r points to the single number
         */
        if (r == nums.size() - 1) {
            // right has never moved
            return nums[r]; 
        }
                        
        return nums[l]; 
        
    }
};