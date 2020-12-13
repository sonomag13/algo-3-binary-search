#include <cmath>
#include <vector>


using namespace std;

class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    template <typename T>
    int closestNumber(vector<T> &A, T target) {
        // write your code here
        if (A.empty()) {
            return -1;
        }

        int l{0};
        int r{static_cast<int>(A.size() - 1)};

        if (target <= A[l]) {
            return l;
        }

        if (target >= A[r]) {
            return r;
        }

        // start binary search
        while (l + 1 < r) {
            int m = l + (r - l) / 2;

            if (A[m] == target) {
                return m;
            }

            if (A[m] < target) {
                l = m;
            }
            else {
                r = m;
            }
        }

        if (abs(A[l] - target) <= abs(A[r] - target)) {
            return l;
        }
        else {
            return r;
        }
    }

};