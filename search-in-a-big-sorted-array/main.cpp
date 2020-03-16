#include <iostream>
#include "Solution.h"

using namespace std;

int main() {

    int sortedArray [] = {1,1,1,1,
                          2,2,
                          3,3,3,
                          4,4,4,
                          5,5,5,5,5,5,5,
                          6,6,6,6,6,6,
                          7,7,7,
                          8,8,8,8,
                          9,9,9,9,
                          10,10,10,10,10,10,10,10,10,
                          11,11,11,11,
                          12,12,12,
                          13,13,13,13,13,
                          14,14,14,14,14,
                          15,15,15,15,15,15,15,
                          16,16,16,16,16,16,16,16,16,
                          17,17,17,17,17,17,17,
                          18,18,19,
                          19,19,19,
                          20,20,20,20,20,20,20,20,20};

    int target = 4;
    Solution solution;
    int targetIdx = solution.searchBigSortedArray(sortedArray, target);

    cout << "target = " << target << endl;
    cout << "target idx = " << targetIdx << endl;

    return 0;

}
