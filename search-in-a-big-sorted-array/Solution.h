//
// Created by lu.gao on 3/15/2020.
//

#ifndef SEARCH_IN_A_BIG_SORTED_ARRAY_SOLUTION_H
#define SEARCH_IN_A_BIG_SORTED_ARRAY_SOLUTION_H

#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(int* sortedArray, int target) {
        // write your code here
        int i = 0, left = 0, leftVal, right, rightVal, mid, midVal;
        if(*(sortedArray) == target) {
            return left;
        }
        while(*(sortedArray + int(pow(2, i))) < target) {
            i++;
        }
        right = pow(2, i);
        /*
        cout << "power = " << i << endl;
        cout << "initial right = " << right << endl;
        */
        while(left <= right - 1) {
            mid = left + (right - left) / 2;
            midVal = *(sortedArray + mid);
            leftVal = *(sortedArray + left);
            rightVal = *(sortedArray + right);
            if(midVal == target) {
                while(*(sortedArray + mid - 1) == target) {
                    mid--;
                }
                return mid;
            }
            if(left == right - 1) {
                if(leftVal == target) {
                    return left;
                }
                if(rightVal == target) {
                    return right;
                }
                return -1;
            }
            if(midVal < target) {
                left = mid;
            }
            if(midVal > target) {
                right = mid;
            }
        }
    }
};


#endif //SEARCH_IN_A_BIG_SORTED_ARRAY_SOLUTION_H
