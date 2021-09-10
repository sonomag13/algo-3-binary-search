// LeetCode 81. Search in Rotated Sorted Array II
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1; 
        
        while (l + 1 < r) {
            
            int m = l + (r - l) / 2; 
            
            if (nums[m] == target || nums[l] == target || nums[r] == target) {
                return true; 
            }
            
            if (nums[m] < nums[l]) {
                if (nums[m] < target && target < nums[r]) {
                    l = m + 1;
                }
                else {
                    r = m - 1; 
                }                
            }
            else if (nums[m] > nums[l]) {
                if (nums[l] < target && target < nums[m]) {
                    r = m - 1; 
                }
                else {
                    l = m + 1; 
                }
            }
            else {
                // in case nums[m] = nums[l] 
                // e.g. [1 1 1 1 1 2 1 ]
                l++; 
            }
            
        }        
        
        if (nums[l] == target || nums[r] == target) {
            return true; 
        }
        
        return false; 
        
    }
        
};