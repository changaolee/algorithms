class Solution {
    vector<int> f;
    deque<int> q;
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        f = vector<int>(n); f[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            while (!q.empty() && i - k > q.front()) {
                q.pop_front();
            }
            while (!q.empty() && f[q.back()] < f[i - 1]) {
                q.pop_back();
            }
            q.push_back(i - 1);
            f[i] = nums[i] + max(f[q.front()], 0);
            ans = max(ans, f[i]);
        }
        return ans;
    }
};