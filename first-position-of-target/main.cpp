#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {

    vector<int> vect{1, 4, 4, 5, 7, 7, 8, 9, 9, 10};
    int target{1};

    int idx{Solution::binarySearch(vect, target)};

    cout << "idx = " << idx << endl;

    return EXIT_SUCCESS;
}