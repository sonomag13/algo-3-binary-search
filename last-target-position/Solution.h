/*
	458. Last Position of Target	
	Find the last position of a target number in a sorted array. Return -1 if target does not exist.

	Example
	Example 1:

	Input: nums = [1,2,2,4,5,5], target = 2
	Output: 2
	Example 2:

	Input: nums = [1,2,2,4,5,5], target = 6
	Output: -1
 */

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        
        if (nums.empty()) {
            return -1; 
        }
        
        int left = 0, right = nums.size() - 1; 
        
        if (target < nums[left] || target > nums[right]) {
            return -1; 
        }
        
        while (left + 1 < right) {
            
            int mid = left + (right - left) / 2; 
            
            if (nums[mid] > target) {
                right = mid; 
            }
            else {
                left = mid; 
            }
        }
        
        if (nums[right] == target) {
            return right; 
        }
        
        if (nums[left] == target) {
            return left; 
        }
        
        return -1; 
        
    }
};