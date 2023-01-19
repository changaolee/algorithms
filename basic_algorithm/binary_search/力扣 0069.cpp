class Solution {
public:
    int mySqrt(int x) {
        // 找到 x 的平方根（左侧最后一个下标）
        // 左侧：nums[i]^2 <= x
        // 右侧：nums[i]^2 > x
        int l = 0, r = x;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};