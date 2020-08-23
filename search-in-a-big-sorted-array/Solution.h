//
// Created by lu.gao on 3/15/2020.
//

class Solution {
public:
    /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        
        if (target < reader->get(0)) {
            return -1; 
        }
        
        int l{0}, r{1}, m; 
        
        // find the upper boundary
        while (reader->get(r) < target) {
            r *= 2; 
        }
        
        // binary search
        while (l + 1 < r) {
            
            m = l + (r - l) / 2; 
            
            // looking for the first appearance, so that if *m == target, move r to m
            if (reader->get(m) >= target) {
                r = m; 
            }
            else {
                l = m; 
            }
        }
        
        // since we are looking for the first appearance of the target, first check left
        if (reader->get(l) == target) {
            return l; 
        }
        
        if (reader->get(r) == target) {
            return r; 
        }
        
        
        return -1; 
    }
};