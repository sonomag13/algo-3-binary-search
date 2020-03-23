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
    int search(vector<int> &A, int target) {
        // write your code here

        if(A.empty()) {
            return -1;
        }

        int left = 0, right = A.size() - 1, mid;
        /*
         why left + 1 < right instead of left < right?
         - if there are two values only in the array, there might be infinite loop
         - if we use left < right, after the loop, there might be the possibility that left = right, and it will require more work to handle this situation

         For example, if left = 2 and right = 3
         - using while(left + 1 < right), the loop will break and left = 2 and right = 3
         - using while(left < right), the loop goes for one more time, which may yields left = right, and it will require more work to handle
         */
        while(left + 1 < right) {
            mid = left + (right - left) / 2;
            if(A[mid] == target) {
                return mid;
            }
            if(A[mid] > A[left]) {
                if(isInRange(A[left], A[mid], target)) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if(isInRange(A[mid], A[right], target)) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        if(A[left] == target) {
            return left;
        }

        if (A[right] == target) {
            return right;
        }

        return -1;

    }

private:
    bool isInRange(int val1, int val2, int target) {
        return target >= val1 && target <= val2 ? true : false;
    }
};

#endif //SEARCH_IN_CIRCULAR_SHIFTED_ARRAY_SOLUTION_H
