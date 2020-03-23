/*
LintCode 74. First Bad Version
The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.

Example
Given n = 5:

    isBadVersion(3) -> false
    isBadVersion(5) -> true
    isBadVersion(4) -> true

Here we are 100% sure that the 4th version is the first bad version.
Challenge
You should call isBadVersion as few as possible.

Notice
Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is SVNRepo.isBadVersion(v)
*/

/**
 * class SVNRepo {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use SVNRepo::isBadVersion(k) to judge whether 
 * the kth code version is bad or not.
*/

class Solution {

public:
    /**
     * @param n: An integer
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here

    	/*
			Notice that in this case, the version start with 1, not zero, such that left is initialized as 1
			Similarly, right is initialized as n, not n - 1
    	*/ 
        int left = 1, right = n, mid; 
        
        /*
        	left + 1 < right is recommended by JiuZhang to minimize the risk of infinite loop
        	If we use while(left + 1 < right), the while loop stop while left != right. 
        	For example, if right = 5:
        	- if using while(left+1 < right), the while loop breaks when left = 4
        	- if using while(left < right), the while loop break when left = 5
        */
        while(left + 1 < right) {
            mid = left + (right - left) / 2; 
            if(SVNRepo::isBadVersion(mid)) {
                right = mid; 
            }
            else {
                left = mid;
            }
        }
        if(SVNRepo::isBadVersion(left)) {
            return left; 
        }
        else {
            return right;    
        }
    }
};