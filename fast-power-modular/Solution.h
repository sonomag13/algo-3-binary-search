/*
LintCode 428. Pow(x, n)
Implement pow(x, n). (n is an integer.)

Example
Example 1:

Input: x = 9.88023, n = 3
Output: 964.498
Example 2:

Input: x = 2.1, n = 3
Output: 9.261
Example 3:

Input: x = 1, n = 0
Output: 1
Challenge
O(logn) time

Notice
You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.
*/

class Solution {
public:
    /**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        // a^n % b
        // n = 0 is a corner case        
        if(n == 0) {
            return 1 % b;
        }
        // n = 1 is the bottom of the recursion
        if(n == 1) {
            return a % b;
        }
        /*        
        1. For a^n % b (assuming n is even; see the next equation for the case of odd n)
        	a^n % b = (a^n/2)^2 % b = (a^n/2 % b)^2 % b
        	where (a^n/2 % b) is a small number, and calculated from the previous step of recursion
        	such that (a^n/2 % b)^2 is a small number and does not over flow. 

        2. Equation (a1 * a2) % c = ((a1 % c) × a2) % c is used to handle the parity of n.
        2.1 if n is even, a1 = a2 and are calculated fromthe previous step of recursion
        2.2 if n is odd, a^n = a^n/2 * a^n/2 * a, and in this case 
        		a^n % b = (a^n/2 * a^n/2 * a) % b = (((a^n/2 * a^n/2) % b) * a) % b
        	also notice that
        		(a^n/2 * a^n/2) % b = (a^n/2)^2 % b = (a^n/2 % b)^2 % b
        	and a^n/2 % b is calculated from the previous step of recursion
        */
        long int modular = fastPower(a, b, n/2); 
        return n % 2 == 0 ? (modular * modular) % b : (((modular * modular) % b) * a) % b; 
    }
};