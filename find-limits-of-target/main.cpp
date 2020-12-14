#include <iostream>
#include <vector>

#include "Solution.h"

using namespace std;

int main() {

    vector<int> arrc{1, 3, 5, 6, 7, 7, 7, 8, 9, 10};
    int target{7};

    Solution solution;
    vector<int> limits{solution.searchRange(arrc, target)};

    cout << "index of lower limit = " << limits.at(0) << endl;
    cout << "index of upper limit = " << limits.at(1) << endl;

    return EXIT_SUCCESS;
}