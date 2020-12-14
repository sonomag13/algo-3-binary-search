//
// Created by luther on 12/13/20.
//

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
        // write your code here

        if (A.empty()) {
            return vector<int>{-1, -1};
        }

        _size = static_cast<int>(A.size());

        // search for the upper and lower limits
        int lowerLimit{_findLowerLimit(A, target)};
        int upperLimit{_findUpperLimit(A, target)};

        // append the limits to the result and return it
        return vector<int>{lowerLimit, upperLimit};

    }

private:

    int _size{0};

    int _findLowerLimit(const vector<int>& A, const int& target) const {

        int l{0}, r{_size - 1};

        if (target < A[l]) {
            // the lower limit does not exist
            return -1;
        }

        if (target > A[r]) {
            // the lower limit is the larget number of the array
            return r;
        }

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (A[m] <= target) {
                l = m;
            }
            else {
                r = m;
            }
        }
        return l;
    }

    int _findUpperLimit(const vector<int>& A, const int& target) const {

        int l{0}, r{_size - 1};

        if (target > A[r]) {
            // the upper limit does not exits
            return -1;
        }

        if (target < A[l]) {
            // all the elements larger than the target
            return l;
        }

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (A[m] >= target) {
                r = m;
            }
            else {
                l = m;
            }
        }
        return r;
    }


};