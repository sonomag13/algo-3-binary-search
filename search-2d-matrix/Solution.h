/*
    28. Search a 2D Matrix    
    Write an efficient algorithm that searches for a value in an m x n matrix.

    This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
    Example
    Example 1:
        Input:  [[5]], 2
        Output: false
        
        Explanation: 
        false if not included.
        
    Example 2:
        Input:  
        [ [1, 3, 5, 7],
          [10, 11, 16, 20],
          [23, 30, 34, 50]], 3
        Output: true
        
        Explanation: 
        return true if included.
            
    Challenge
    O(log(n) + log(m)) time
 */

#pragma once

#include <vector>

using namespace std; 

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        
        _rowNum = matrix.size(); 
        _colNum = matrix.at(0).size(); 
        
        if (!_rowNum || !_colNum) {
            return false; 
        }
        
        // start binary searching
        int left{0}, right{_rowNum * _colNum - 1}; 
        
        while (left + 1 < right) {
            int mid{left + (right - left) / 2}; 
            if (_checkMatch(matrix, mid, target)) {
                return true; 
            }
            if (matrix[mid / _colNum][mid % _colNum] < target) {
                left = mid;
            }
            else {
                right = mid; 
            }
        }
        
        if (_checkMatch(matrix, left, target) || _checkMatch(matrix, right, target)) {
            return true; 
        }
        
        return false; 
        
    }
    
private:
    // size of the matrix
    int _rowNum{0}, _colNum{0}; 
    
    // check if the ith element is equal to the target
    bool _checkMatch(const vector<vector<int>>& matrix, const int& idx, const int& target) {
         if (matrix[idx / _colNum][idx % _colNum] == target) {
            return true; 
        }
    }
    
};