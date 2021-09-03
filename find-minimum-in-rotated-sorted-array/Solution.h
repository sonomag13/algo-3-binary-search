// LeetCode 153. Find Minimum in Rotated Sorted Array
// Medium

class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while (l + 1 < r) {

            int m = l + (r - l) / 2;

            if (nums[m - 1] > nums[m]) {
                return nums[m];
            }

            if (nums[m] > nums[r]) {
                l = m;
            }
            else {
                r = m;
            }
        }

        return nums[l] < nums[r] ? nums[l] : nums[r];

    }
};
