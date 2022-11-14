#include <iostream>
#include <deque>

using namespace std;

const int N = 2000010;
int a[N];

deque<int> q;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    printf("0\n");
    
    for (int i = 0; i < n - 1; i++) {
        while (!q.empty() && i - m + 1 > q.front()) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] > a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (!q.empty()) printf("%d\n", a[q.front()]);
        else printf("0\n");
    }
    
    return 0;
}