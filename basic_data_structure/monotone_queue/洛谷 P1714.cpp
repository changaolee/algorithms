#include <bits/stdc++.h>

using namespace std;

const int N = 500010;
int sum[N];

deque<int> q;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    
    q.push_back(0);
    
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && i - m > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && sum[q.back()] > sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
        ans = max(ans, sum[i] - sum[q.front()]);
    }
    printf("%d\n", ans);
    
    return 0;
}