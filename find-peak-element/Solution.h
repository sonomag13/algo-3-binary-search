/*
LintCode 75. Find Peak Element

Description
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peak if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.
Have you met this question in a real interview?  

Example
Example 1:
    Input:  [1, 2, 1, 3, 4, 5, 7, 6]
    Output:  1 or 6
    
    Explanation:
    return the index of peek.


Example 2:
    Input: [1,2,3,4,1]
    Output:  3

*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        
        // write your code here
        int left = 1, right = A.size(), mid; 
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (A[mid] > A[mid-1] && A[mid] > A[mid+1])
                return mid;                
            /*
                Notice that it is correct to use mid + 1 or mid - 1 to improve efficiency
                The reason is that since A[mid] > A[mid-1] && A[mid] > A[mid+1] is false (otherwise mid is already returned)
                That said, mid cannot be the peak, so that is it either in the up slope (if A[mid] > A[mid-1]) or down slope
                Taking the up slope for example, we do not need to set left at the mid (again, mid is not the peak), 
                but to look at the element after mid, thus left = mid + 1
                Similar to right
            */
            if (A[mid] > A[mid-1]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
                
        }
        return -1;
    }
};