
// LintCode Problem 460. find K Closest Elements
// https://www.lintcode.com/problem/find-k-closest-elements/description?_from=ladder&&fromId=1

#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {

    int sortedArray [] = {1, 4, 6, 8};
    int target = 3, k = 3;

    vector<int> sortedVect, vecClosestNums;
    Solution solution;

    int N = sizeof(sortedArray) / sizeof(int);

    for(int i = 0; i < N; i++) {
        sortedVect.push_back(sortedArray[i]);
    }

    vecClosestNums = solution.kClosestNumbers(sortedVect, target, k);

    for(int i = 0; i < vecClosestNums.size(); i++) {
        std::cout << vecClosestNums[i] << std::endl;
    }

    return 0;

}
