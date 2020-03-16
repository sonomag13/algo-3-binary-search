//
// Created by lu.gao on 3/15/2020.
//

#ifndef FIND_CLOSEST_K_ELEMENTS_SOLUTION_H
#define FIND_CLOSEST_K_ELEMENTS_SOLUTION_H

#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {

public:
    vector<int> kClosestNumbers(vector<int> &A, int target, int k) {
        // write your code here
        vector<int> vecClosestNums;
        int N = A.size() - 1;
        int delta, rightDelta, leftDelta, minDelta = 1E5, minIdx = 1E5;
        int left = 0, right = N, mid, midVal;
        if(target < A[0]) {
            for(int i = 0; i < k - 1; i++) {
                vecClosestNums.push_back(A[i]);
            }
            return vecClosestNums;
        }
        if(target > A[N]) {
            for(int i = N - k + 1; i < N; i++) {
                vecClosestNums.push_back(A[i]);
            }
            return vecClosestNums;
        }

        while(left <= right - 1) {
            mid = left + (right - left) / 2;
            midVal = A[mid];
            delta = abs(midVal - target);
            // mid value is the target
            if(delta == 0) {
                minIdx = mid;
                break;
            }
            if(left == right - 1) {
                if(abs(A[left] - target) <= abs(A[right] - target)) {
                    mid = left;
                }
                else {
                    mid = right;
                }
                break;
            }
            if(delta < minDelta) {
                minIdx = mid;
                minDelta = delta;
                if(target > midVal) {
                    left = mid;
                }
                else {
                    right = mid;
                }
            }

        }
        // push the first element into the vector
        vecClosestNums.push_back(A[minIdx]);
        // cout << "breakpoint 5" << endl;
        left = mid - 1;
        right = mid + 1;
        k--;

        while(k != 0) {
            rightDelta = abs(A[right] - target);
            leftDelta = abs(A[left] - target);
            if(rightDelta == leftDelta) {
                vecClosestNums.push_back(A[left]);
                vecClosestNums.push_back(A[right]);
                k -= 2;
                left--;
                right++;
            }
            if(rightDelta > leftDelta) {
                vecClosestNums.push_back(A[left]);
                k--;
                left--;
            }
            if(rightDelta < leftDelta) {
                vecClosestNums.push_back(A[right]);
                k--;
                right++;
            }
        }

        return vecClosestNums;

    }

};


#endif //FIND_CLOSEST_K_ELEMENTS_SOLUTION_H
