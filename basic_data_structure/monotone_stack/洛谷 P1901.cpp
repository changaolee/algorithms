#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int h[N], v[N], sum[N];

stack<int> stk;

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &h[i], &v[i]);
    }
    
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && h[stk.top()] <= h[i]) {
            stk.pop();
        }
        if (!stk.empty()) sum[stk.top()] += v[i];
        stk.push(i);
    }
    
    stack<int>().swap(stk);
    
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && h[stk.top()] <= h[i]) {
            stk.pop();
        }
        if (!stk.empty()) sum[stk.top()] += v[i];
        stk.push(i);
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sum[i]);
    }
    
    printf("%d\n", ans);
    
    return 0;
}