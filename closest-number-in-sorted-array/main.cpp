#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {

    vector<double> arrc;
    const int n{10};
    arrc.reserve(n);
    for (int i = 0; i < n; ++i) {
        // arrc.push_back(static_cast<double>(i) + 0.5);
        arrc.push_back((double)i + 0.5);
    }

    double target{5.6};

    cout << "target = " << target << endl;
    for (int i = 0; i < arrc.size(); ++i) {
        cout << i << ": " << arrc[i] << endl;
    }

    Solution solution;

    int idx = solution.closestNumber(arrc, target);

    cout << "idx = " << idx << endl;


}