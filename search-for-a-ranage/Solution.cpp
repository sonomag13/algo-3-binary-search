/*    
    61. Search for a Range
    Description
    Given a sorted array of n integers, find the starting and ending position of a given target value.

    If the target is not found in the array, return [-1, -1].

    Have you met this question in a real interview?  
    Example
    Example 1:

    Input:
    []
    9
    Output:
    [-1,-1]

    Example 2:

    Input:
    [5, 7, 7, 8, 8, 10]
    8
    Output:
    [3, 4]
    Challenge
    O(log n) time.
 */

#pragma once 
#include <vector>

using namespace std; 

class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: a list of length 2, [index1, index2]
     */
    vector<int> searchRange(vector<int> &A, int target) {
        // corner casing handling
        if (A.empty()) {
            return vector<int>{-1, -1}; 
        }
        
        // set the size of the vector
        _size = static_cast<int>(A.size()); 
        
        // search for the upper and lower limits
        int firstAppearance{_findFirstAppearance(A, target)}; 
        int lastAppearance{_findLastAppearance(A, target)}; 
        
        // append the limits to the result and return it
        return vector<int>{firstAppearance, lastAppearance}; 
        
    }
    
private: 

    int _size{0};

    /**
     * this function is used to search for the first appearance and 
     * the last appearance of the target value in a sorted array
     **/ 
    int _findFirstAppearance(const vector<int>& A, const int& target) {
        
        int l{0}, r{_size - 1}; 
        
        /**
         * In this search, since we are searching for the first appearance, 
         * if the mid value is equal to the target, then move the right pointer
         * to the mid, such that the pointers are converging to the first appearance
         * of the target
         * 
         * The while loops breaks when left nad right are neighbor to each other, 
         * and we need to check if the first appearance is at left pointer or 
         * right pointer. If neither of the matches the target, return -1.
         **/
        while (l + 1 < r) {
            int m = l + (r - l) / 2; 
            if (A[m] >= target) {
                r = m; 
            }
            else {
                l = m; 
            }
        }
        
        if (A[l] == target) {
            return l;    
        }
        
        if (A[r] == target) {
            return r;
        }
        
        return -1; 
        
    }

    int _findLastAppearance(const vector<int>& A, const int& target) {
        
        int l{0}, r{_size - 1}; 
        
        /**
         * In this search, since we are searching for the last appearance, 
         * if the mid value is equal to the target, then move the left pointer
         * to the mid, such that the pointers are converging to the last appearance
         * of the target
         * 
         * The while loops breaks when left nad right are neighbor to each other, 
         * and we need to check if the last appearance is at left pointer or 
         * right pointer. If neither of the matches the target, return -1.
         **/
        while (l + 1 < r) {
            int m = l + (r - l) / 2; 
            if (A[m] <= target) {
                l = m; 
            }
            else {
                r = m; 
            }
        }
        if(A[r] == target) {
            return r; 
        }
        
        if (A[l] == target) {
            return l; 
        }        
        return -1;         
    }
        
};