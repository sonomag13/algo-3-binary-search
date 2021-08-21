/*
    34. Find First and Last Position of Element in Sorted Array
    Medium
    
    Given an array of integers nums sorted in ascending order, 
    find the starting and ending position of a given target value.

    If target is not found in the array, return [-1, -1].

    You must write an algorithm with O(log n) runtime complexity.

    Example 1:

    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]
    Example 2:

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]
    Example 3:

    Input: nums = [], target = 0
    Output: [-1,-1]
 */

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result; 
        
        if (nums.empty()) {
            return vector<int>{-1, -1}; 
        }
        
        result.push_back(_find_first_position(nums, target));
        result.push_back(_find_last_position(nums, target));
        
        return result; 
        
    }
    
private:
    
    int _find_first_position(const vector<int>& nums, int target) {
        int firstPos{-1};
        
        int l = 0;
        int r = nums.size() - 1; 
        
        while (l + 1 < r) {            
            int m = l + (r - l) / 2;             
            if (nums[m] >= target) {
                r = m;
            } 
            else {
                l = m; 
            }            
        }
        
        if (nums[l] == target) {
            return l; 
        }
        
        if (nums[r] == target) {
            return r;
        }
        
        return firstPos;
    }
    
    int _find_last_position(const vector<int>& nums, int target) {
        int lastPos{-1};
        
        int l = 0;
        int r = nums.size() - 1; 
                
        while (l + 1 < r) {            
            int m = l + (r - l) / 2;             
            if (nums[m] <= target) {
                l = m;
            }
            else {
                r = m;
            }                        
        }
        
        if (nums[r] == target) {
            return r;
        }
        
        if (nums[l] == target) {
            return l;
        }
        
        return lastPos;
    }
    
};