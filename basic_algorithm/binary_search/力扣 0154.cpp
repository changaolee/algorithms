class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r && nums[l] == nums[r]) l++;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= nums.back()) r = mid;
            else l = mid + 1;
        }
        return nums[r];
    }
};