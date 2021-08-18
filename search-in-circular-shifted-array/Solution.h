//
// Created by strobe on 3/22/20.
//

#ifndef SEARCH_IN_CIRCULAR_SHIFTED_ARRAY_SOLUTION_H
#define SEARCH_IN_CIRCULAR_SHIFTED_ARRAY_SOLUTION_H

#include <vector>

using namespace std;

/*
    The key to solve this question is, use mid to separate the array into 2 sections.
    One section must be sorted, and another section must be circularly sorted

    If the mid value is greater than the left, the mid point is on the sorted section, and in this case:
    - if the target is in the range of [*left, *mid], we know that if the target exists, it must be in the sorted side, such that right = mid - 1
    - if the target is not in that range, then if the target exists, it must be in the circularly sorted side, such that left = mid + 1

    If the mid value is less than the left, the mid point must be on the circularly sorted section. The treatment is simiarly to the section above

 */


class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int>& nums, int target) {
        // write your code here

        if(nums.empty()) {
            return -1;
        }

        size_t l{0}, r{nums.size() - 1};
        /*
         why left + 1 < right instead of left < right?
         - if there are two values only in the array, there might be infinite loop
         - if we use left < right, after the loop, there might be the possibility that left = right, and it will require more work to handle this situation

         For example, if left = 2 and right = 3
         - using while(left + 1 < right), the loop will break and left = 2 and right = 3
         - using while(left < right), the loop goes for one more time, which may yields left = right, and it will require more work to handle
         */
                while (l + 1 < r) {
            
            size_t m{l + (r - l) / 2}; 
            
            if (nums[m] == target) {
                return m; 
            }
            
            if (nums[m] > nums[l]) {
                
                // Case 1 m is on the left side of the array
                
                if (nums[l] <= target && target < nums[m]) {
                    // Case 1.1 target is between [l, m]
                    r = m; 
                }
                else {
                    // Case 1.2 target is between [m, l];
                    l = m;
                }                
                
            }
            else {
                
                // Case 2 m is on the right side of the array 
                
                if (nums[m] < target && target <= nums[r]) {
                    // Case 2.1 target is between [m, r]
                    l = m;                                        
                }
                else {
                    // Case 2.2 target is between [l, m]
                    r = m;
                }                
            }
                        
        }
        
        if (nums[l] == target) {
            return l; 
        }
        
        if (nums[r] == target) {
            return r;
        }
        
        return -1;
        
    }

};

#endif //SEARCH_IN_CIRCULAR_SHIFTED_ARRAY_SOLUTION_H
