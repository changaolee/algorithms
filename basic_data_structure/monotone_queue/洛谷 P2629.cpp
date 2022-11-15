#include <iostream>
#include <deque>

using namespace std;

const int N = 2000010;
int a[N], sum[N];

deque<int> q;

int main() {
    int n;
    scanf("%d", &n);
    
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i < n) a[i + n] = a[i];
    }
    
    for (int i = 1; i < 2 * n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }
    
    int ans = 0;
    for (int i = 1; i < 2 * n; i++) {
        while (!q.empty() && i - n > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && sum[q.back()] > sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i - n >= 0 && sum[q.front()] >= sum[i - n]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}