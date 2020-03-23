/*
    LintCode 62. Search in Rotated Sorted Array
    Description
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    You are given a target value to search. If found in the array return its index, otherwise return -1.

    You may assume no duplicate exists in the array.

    Have you met this question in a real interview?
    Example
    Example 1:

    Input: [4, 5, 1, 2, 3] and target=1,
    Output: 2.
    Example 2:

    Input: [4, 5, 1, 2, 3] and target=0,
    Output: -1.

 */

#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {

    // int rotatedSortedArray [] = {4, 3};
    int rotatedSortedArray [] = {5, 6, 7, 0, 1, 2, 3, 4};
    int target = 3, idxTarget;
    vector<int> rotatedSortedVector;

    for(int i = 0; i < sizeof(rotatedSortedArray)/sizeof(int); i++) {
        rotatedSortedVector.push_back(rotatedSortedArray[i]);
    }

    Solution solution;
    idxTarget = solution.search(rotatedSortedVector, target);
    cout << "target index = " <<  idxTarget << endl;

    return 0;
}
