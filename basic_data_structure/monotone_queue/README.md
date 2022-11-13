## 单调队列

### 算法模板

```cpp
for (int i = 0; i < n; i++) {
    while (!q.empty() && checkWindow(i, q.front())) {
        q.pop_front();
    }
    while (!q.empty() && check(i, q.back())) {
        q.pop_back();
    }
    q.push_back(i);
    // 输出 ...
}
```
