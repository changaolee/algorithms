## 单调队列

> [【算法精讲系列】基础数据结构：单调队列 | 滑动窗口最值问题](https://www.bilibili.com/video/BV1UG4y1t7cQ/)

### 算法模板

```cpp
for (int i = 0; i < n; i++) {
    // 移除队头滑动窗口外的元素
    while (!q.empty() && checkWindow(i, q.front())) {
        q.pop_front();
    }
    // 弹出队尾不满足单调性的元素
    while (!q.empty() && check(i, q.back())) {
        q.pop_back();
    }
    // 加入当前元素
    q.push_back(i);

    // 输出 ...
}
```

### 习题

| 类型 | 代码 | 链接 |
| --- | --- | --- |
| 滑动窗口最值 | [洛谷 P1886](./洛谷%20P1886.cpp) | [查看原题](https://www.luogu.com.cn/problem/P1886) |
| 滑动窗口最值 | [洛谷 P1440](./洛谷%20P1440.cpp) | [查看原题](https://www.luogu.com.cn/problem/P1440) |
| 滑动窗口最值 | [洛谷 P2032](./洛谷%20P2032.cpp) | [查看原题](https://www.luogu.com.cn/problem/P2032) |
| 带长度限制的最大子数组和 | [洛谷 P1714](./洛谷%20P1714.cpp) | [查看原题](https://www.luogu.com.cn/problem/P1714) |
| 带长度限制的最大子数组和 | [洛谷 P2629](./洛谷%20P2629.cpp) | [查看原题](https://www.luogu.com.cn/problem/P2629) |
| 单调队列优化 DP | [洛谷 P3957](./洛谷%20P3957.cpp) | [查看原题](https://www.luogu.com.cn/problem/P3957) |
| 单调队列优化 DP | 洛谷 P1725 | [查看原题](https://www.luogu.com.cn/problem/P1725) |
| 二维队列 | 洛谷 P2776 | [查看原题](https://www.luogu.com.cn/problem/P2776) |
