// LeetCode 35. Search Insert Position

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int left = 0; 
        int right = nums.size() - 1; 

        while (left + 1 < right) {
            int mid = left + (right - left) / 2; 
            int midVal = nums[mid]; 
            if (midVal == target) {
                return mid; 
            }
            if (midVal < target) {
                left = mid; 
            }
            else {
                right = mid; 
            }
        }

        if (target < nums[left]) {
            return max(left - 1, 0);
        }

        if (nums[left] == target) {
            return left; 
        }

        if (nums[left] < target && target < nums[right]) {
            return left + 1; 
        }

        if (nums[right] == target) {
            return right; 
        }

        return right + 1; 

    }
};