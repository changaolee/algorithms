class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};

        vector<int> ans(2);

        // 找到左端点（第一个 >= target 的元素下标）
        // 左侧：nums[i] < target
        // 右侧：nums[i] >= target
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (nums[l] != target) return {-1, -1};
        ans[0] = l;

        // 找到右端点（最后一个 >= target 的元素下标）
        // 左侧：nums[i] <= target
        // 右侧：nums[i] > target
        l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        ans[1] = r;

        return ans;
    }
};