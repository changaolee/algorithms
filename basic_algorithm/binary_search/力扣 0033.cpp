class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        // 找到数组旋转点（左侧最后一个下标）
        // 左侧：nums[i] >= nums[0]
        // 右侧：nums[i] < nums[0]
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        // 确定 target 在哪个区间，设置 l、r
        if (target >= nums[0]) l = 0;
        else l = r + 1, r = nums.size() - 1;

        // 子区间内二分查找（第一个 >= target 的元素下标）
        // 左侧：nums[i] < target
        // 右侧：nums[i] >= target
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        // 注意：此时 l 可能越界，返回时用 r 判断
        return nums[r] == target ? r : -1;
    }
};