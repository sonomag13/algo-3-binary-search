// LeetCode 278. First Bad Version
// Easy

class SVNRepo {
    public:
    static bool isBadVersion(int k);
};

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