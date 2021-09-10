// LeetCode 4. Median of Two Sorted Arrays
// Hard

#include <vector>

using namespace std; 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        const int size1 = nums1.size();
        const int size2 = nums2.size(); 
        
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1); 
        }
        
        // IMPORTANT: 
        //  - total size is odd, k is the index of the median value (despite we do not know what the value is)
        //  - total size is even, k and k + 1 are the indices of two numbers in the middle
        // 
        // We need to select k numbers from nums1 and nums2 to form the first k numbers in the merged array 
        // (assume we have a merged array)
        const int k = (size1 + size2  + 1) / 2; 
        
        int l = 0; 
        int r = size1; 
        
        while (l < r) {
            
            // IMPORTANT: 
            // - m1 is an index pointing to (m1 + 1)th element in the array
            // - that said, before m1 index, there are m1 numbers            
            // - m2 = k - m1, implying that m2 points to the (m2 + 1)th element in the array, 
            //   and before m1 index, there are m2 numbers 
            int m1 = l + (r - l) / 2;             
            int m2 = k - m1; 
            
            if (nums1[m1] < nums2[m2 - 1]) {
                l = m1 + 1; 
            }
            else {
                r = m1;
            }          
        }
        
        // we will use m1 element from nums1
        int m1 = l;     
        int m2 = k - m1; 
        
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], 
                     m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
 
        if ((size1 + size2) % 2 == 1) {
            return static_cast<double>(c1);    
        }
            
        double c2 = min(m1 >= size1 ? INT_MAX : nums1[m1], 
                        m2 >= size2 ? INT_MAX : nums2[m2]);
            
        return static_cast<double>(c1 + c2) * 0.5;  
        
    }
};