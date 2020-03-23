/*
LintCode 585. Maximum Number in Mountain Sequence
Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.

Example
Example 1:

Input: nums = [1, 2, 4, 8, 6, 3] 
Output: 8
Example 2:

Input: nums = [10, 9, 8, 7], 
Output: 10
Notice
Arrays are strictly incremented, strictly decreasing

*/

class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int mid, left = 0, right = nums.size() - 1; 
        
        int midVal;
        
        while(left < right) {
            
            mid = (left + right) >> 1;
            midVal = nums[mid];
            
            if(maxVal < nums[mid + 1]) {
                left = mid + 1;
            }
            else if(maxVal < nums[mid - 1]) {
                right = mid - 1;
            }
            else {
                return midVal; 
            }
        }
        
        return nums[left] > nums[right] ? nums[left] : nums[right]; 
        
    }

};