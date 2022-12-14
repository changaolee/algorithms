#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int a[N];
deque<int> q;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    // 计算最小值
    for (int i = 0; i < n; i++) {
        // 去头
        while (!q.empty() && i - k + 1 > q.front()) {
            q.pop_front();
        }
        // 去尾
        while (!q.empty() && a[q.back()] > a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i + 1 >= k) {
            cout << a[q.front()] << " ";
        }
    }
    printf("\n");
    
    q.clear();
    
    // 计算最大值
    for (int i = 0; i < n; i++) {
        // 去头
        while (!q.empty() && i - k + 1 > q.front()) {
            q.pop_front();
        }
        // 去尾
        while (!q.empty() && a[q.back()] < a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i + 1 >= k) {
            cout << a[q.front()] << " ";
        }
    }
    printf("\n");
    
    return 0;
}