#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500010;

int pos[N], score[N];
int n, d, k;

vector<ll> f;
deque<int> q;

//// 原始 DP：O(n^2)
//bool check(int g)
//{
//  f = vector<ll>(N, -1e18);
//  f[0] = 0;
//  int l = max(d - g, 1), r = d + g;
//  for (int i = 1; i <= n; i++) {
//      for (int j = i - 1; j >= 0; j--) {
//          if (pos[i] - pos[j] < l) continue;
//          if (pos[i] - pos[j] > r) break;
//          f[i] = max(f[i], f[j] + score[i]);
//          if (f[i] >= k) return true;
//      }
//  }
//  return false;
//}

// 单调队列优化后的 DP：O(n)
bool check(int g)
{
    int cur = 0;
    q.clear();
    f = vector<ll>(N, -1e18);
    f[0] = 0;
    int l = max(d - g, 1), r = d + g;
    for (int i = 1; i <= n; i++) {
        while (pos[i] - pos[cur] >= l) {
            while (!q.empty() && f[q.back()] < f[cur]) {
                q.pop_back();
            }
            q.push_back(cur++);
        }
        while (!q.empty() && pos[i] - pos[q.front()] > r) {
            q.pop_front();
        }
        if (!q.empty()) {
            f[i] = f[q.front()] + score[i];
        }
        if (f[i] >= k) return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &d, &k);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &pos[i], &score[i]);
    }
    
    int l = 0, r = pos[n];
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    if (check(r)) printf("%d\n", r);
    else printf("-1\n");
    
    return 0;
}