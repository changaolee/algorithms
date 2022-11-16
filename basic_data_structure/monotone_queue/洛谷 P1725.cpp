#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
int a[N];
int n, l, r;

vector<int> f;
deque<int> q;

//// 原始 DP：O(n^2)
//int solve()
//{
//  int ans = INT_MIN;
//  f = vector<int>(N, -1e9);
//  f[0] = 0;
//  for (int i = l; i <= n + r - 1; i++) {
//      for (int j = max(i - r, 0); j <= i - l; j++) {
//          f[i] = max(f[i], f[j] + a[i]);
//      }
//      if (i + l > n) ans = max(ans, f[i]);
//  }
//  return ans;
//}

// 单调队列优化后的 DP：O(n)
int solve()
{
    int ans = INT_MIN;
    int cur = 0;
    q.clear();
    f = vector<int>(N, -1e9);
    f[0] = 0;
    for (int i = l; i <= n + r - 1; i++) {
        while (!q.empty() && i - r > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && f[q.back()] < f[i - l]) {
            q.pop_back();
        }
        q.push_back(i - l);
        f[i] = f[q.front()] + a[i];
        if (i + l > n) ans = max(ans, f[i]);
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &l, &r);
    
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("%d\n", solve());
    
    return 0;
}