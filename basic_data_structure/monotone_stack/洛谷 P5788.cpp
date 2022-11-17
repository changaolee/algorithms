#include <bits/stdc++.h>

using namespace std;

const int N = 3000010;
int a[N], ans[N];

stack<int> stk;

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[stk.top()] <= a[i]) {
            stk.pop();
        }
        ans[i] = !stk.empty() ? stk.top() : 0;
        stk.push(i);
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    
    return 0;
}