/*
    14. First Position of Target
    For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

    If the target number does not exist in the array, return -1.

    Example
    Example 1:
        Input:  [1,4,4,5,7,7,8,9,9,10]，1
        Output: 0

        Explanation:
        the first index of  1 is 0.

    Example 2:
        Input: [1, 2, 3, 3, 4, 5, 10]，3
        Output: 2

        Explanation:
        the first index of 3 is 2.

    Example 3:
        Input: [1, 2, 3, 3, 4, 5, 10]，6
        Output: -1

        Explanation:
        Not exist 6 in array.

    Challenge
    If the count of numbers is bigger than 2^32, can your code work properly?
 */


#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    static int binarySearch(vector<int> &nums, int target) {
        // write your code here

        if (nums.empty()) {
            return -1;
        }

        int left{0}, right{static_cast<int>(nums.size()) - 1};

        while (left + 1 < right) {
            int mid = left + (right - left) / 2;

            if (nums.at(mid) >= target) {
                right = mid;
            }
            else {
                left = mid;
            }
        }

        if (nums[left] == target) {
            return left;
        }

        if (nums[right] == target) {
            return right;
        }

        return -1;
    }
};