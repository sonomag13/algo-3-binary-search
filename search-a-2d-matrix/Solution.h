// LeetCode 74. Search a 2D Matrix
// Medium

#include <vector>

using namespace std; 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        bool result{false};
        
        int numRow = matrix.size();
        int numCol = matrix[0].size();
        
        // make sure which row to search about
        for (int i = 0; i < numRow; ++i) {            
            if (matrix[i][0] <= target && target <= matrix[i][numCol - 1]) {
                result = binarySearch(matrix[i], target);
                break;
            }                        
        }
        
        return result;
        
    }
    
private:
    
    bool binarySearch(const vector<int> nums, int target) {
        
        int l = 0, r = nums.size(); 
        
        while (l + 1 < r) {
            
            int m = l + (r - l) / 2; 
            
            if (nums[m] == target) {
                return true;
            }
            
            if (nums[m] > target) {
                r = m;
            }
            else {
                l = m;
            }            
        }
                
        if (nums[l] == target || nums[r] == target) {
            return true; 
        }
            
        return false;         
    }
    
};