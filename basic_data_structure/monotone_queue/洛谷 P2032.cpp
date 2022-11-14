#include <iostream>
#include <deque>

using namespace std;

const int N = 2000010;
int a[N];

deque<int> q;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (int i = 0; i < n; i++) {
        while (!q.empty() && i - k + 1 > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] < a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i + 1 >= k) {
            printf("%d\n", a[q.front()]);
        }
    }
    
    return 0;
}