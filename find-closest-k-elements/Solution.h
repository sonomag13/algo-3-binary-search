/*
    460. Find K Closest Elements

    Given target, a non-negative integer k and an integer array A sorted in ascending order, 
    find the k closest numbers to target in A, sorted in ascending order by the difference 
    between the number and target. Otherwise, sorted in ascending order by number if the difference is same.

    Example
    Example 1:

    Input: A = [1, 2, 3], target = 2, k = 3
    Output: [2, 1, 3]
    Example 2:

    Input: A = [1, 4, 6, 8], target = 3, k = 3
    Output: [4, 1, 6]
    Challenge
    O(logn + k) time

    Notice
    1. The value k is a non-negative integer and will always be smaller than the length of the sorted array.
    2. Length of the given array is positive and will not exceed 10^4​​ 
    3. Absolute value of elements in the array will not exceed 10^4

 */

#pragma once 

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {

        vector<int> result; 
        
        /**
         * we need to find the first element in the vector that is greater or equal 
         * to the target. The index of this element is used by the right pointer, and
         * the left pointer is just one element prior, i.e. left and right pointers are
         * neighbor to each other. 
         * 
         * Thare are two corner cases:
         * 1. target is larger than all the element in the vector: the right pointer
         *    points to A.size() and accordingly the left pointer points to A.size()-1 
         *    (or the last element in the vector), we only need to append last k elements 
         *    in the vector but in the reversed order. In this case, the left pointer moves
         *    by k but right pointer stays still.
         * 
         * 2. target is smaller than all the element in the vector: the right pointer
         *    points to 0, and the left pointer points to -1. On the contrary to Case 1, 
         *    the right point moves by k while the left pointer stays still. 
         **/ 
        int right{_findFirstIdx(A, target)}; 
        int left = right - 1; 
        
        while(k > 0) {
            
            // count down by 1
            k--; 

            // corner case 1
            if (right >= A.size()) {
                result.push_back(A[left--]); 
                continue; 
            }
            
            // corner case 2
            if (left < 0) {
                result.push_back(A[right++]);
                continue; 
            }
            
            /**
             * Compare which pointer points to a value that is closer to the target. 
             * If the delta are the same, first append the left pointer
             **/ 
            if ((target - A[left]) <= (A[right] - target)) {
                result.push_back(A[left--]);
            }
            else {
                result.push_back(A[right++]); 
            }
            
        }
        
        return result; 
    }
    
private:

    /**
     * this function locates the index of the first element in a sorted 
     * vector that is greater or larger than the target
     **/
    int _findFirstIdx(const vector<int>& A, const int target) {                
        
        int l{0}, r{A.size()-1}; 
        
        /**
         * corner case 1: 
         * all the element in the vector is smaller than the target         
         **/ 
        if (target > A[r]) {
            return A.size(); 
        }
        
        /**
         * corner case 2: 
         * all the element in the vector is greater than the target         
         **/ 
        if (target < A[l]) {
            return 0; 
        }
        
        // start binary search
        while(l + 1 < r) {
            int m = l + (r - l) / 2; 
            // mid point is equal to the target
            if (A[m] == target) {
                return m; 
            }
            // reset the l and r
            if (A[m] < target) {
                l = m; 
            }
            else {
                r = m; 
            }
        }
        
        /**
         * once the binary search has been completed, r pointer should points
         * to the first value that is larger than the target
         **/ 
        return r; 
    }
    
};