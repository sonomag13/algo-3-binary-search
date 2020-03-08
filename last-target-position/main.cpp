#include <iostream>
#include <vector>
using namespace std;

int lastPosition(vector<int>&, int);
int firstPosition(vector<int>&, int);

int main() {

    vector<int> orderedVector {1, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5};
    int target = 3;

    int targetLastPosition = lastPosition(orderedVector, target);
    int targetFirstPosition = firstPosition(orderedVector, target);

    cout << "\n\nlast target position = " << targetLastPosition << endl;
    cout << "\n\nfirst target position = " << targetFirstPosition << endl;

    return 0;

}

int lastPosition(vector<int>& orderedVector, int target) {
    int targetLastPosition = -1;
    int vectorSize = orderedVector.size();

    if(vectorSize == 0 || target < orderedVector[0] || target > orderedVector[vectorSize-1]) {
        return targetLastPosition;
    }

    int l = 0, r = vectorSize - 1, mid;
    int itr = 0;
    while(l <= r) {
        mid = (r + l) >> 1;
        if(orderedVector[mid] == target) {
            targetLastPosition = mid;
        }
        if(orderedVector[mid] <= target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return targetLastPosition;
}

int firstPosition(vector<int>& orderedVector, int target) {
    int targetLastPosition = -1;
    int vectorSize = orderedVector.size();
    if(vectorSize == 0 || target < orderedVector[0] || target > orderedVector[vectorSize-1]) {
        return targetLastPosition;
    }
    int l = 0, r = vectorSize - 1, mid;
    int itr = 0;
    while(l <= r) {
        mid = (r + l) >> 1;
        if(orderedVector[mid] == target) {
            targetLastPosition = mid;
        }
        if(orderedVector[mid] >= target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return targetLastPosition;
}
