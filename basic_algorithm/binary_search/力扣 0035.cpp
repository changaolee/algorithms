class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找到第一个 >= target 的元素下标
        // 左侧：nums[i] < target
        // 右侧：nums[i] >= target
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};