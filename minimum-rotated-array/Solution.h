/*
LintCode 159. Find Minimum in Rotated Sorted Array

Description

Suppose a sorted array in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You can assume no duplicate exists in the array.

Have you met this question in a real interview?  
Example
Example 1:

Input：[4, 5, 6, 7, 0, 1, 2]
Output：0
Explanation：
The minimum value in an array is 0.
Example 2:

Input：[2,1]
Output：1
Explanation：
The minimum value in an array is 1.
*/


class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1, mid; 
        while(nums[left] > nums[right]) {
            mid = left + (right - left) / 2; 
            if(nums[mid] > nums[right]) {
                left = mid + 1; 
            }
            else {
                right = mid; 
            }
        }
        return nums[left]; 
    }
};