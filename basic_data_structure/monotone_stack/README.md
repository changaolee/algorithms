## 单调栈

### 算法模板

```cpp
for (int i = 0; i < n; i++) {
    // 弹出栈顶不满足单调性的元素
    while (!stk.empty() && check(i, stk.top())) {
        stk.pop();
    }
    
    // 输出 ...
    
    // 加入当前元素
    stk.push(i);
}
```

### 习题

| 类型 | 代码 | 链接 |
| --- | --- | --- |
| 单侧最近大（小）于当前值的元素 | [洛谷 P2947](./洛谷%20P2947.cpp) | [查看原题](https://www.luogu.com.cn/problem/P2947) |
| 单侧最近大（小）于当前值的元素 | [洛谷 P5788](./洛谷%20P5788.cpp) | [查看原题](https://www.luogu.com.cn/problem/P5788) |
| 双侧最近大（小）于当前值的元素 | [洛谷 P1901](./洛谷%20P1901.cpp) | [查看原题](https://www.luogu.com.cn/problem/P1901) |
