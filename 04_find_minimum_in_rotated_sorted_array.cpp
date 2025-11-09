class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than the rightmost element,
            // it means the smallest element lies to the right of mid.
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise, the minimum lies to the left (including mid)
            else {
                right = mid;
            }
        }
        // After the loop, left == right and points to the minimum element
        return nums[left];
    }
};
