## 二分法

> [【算法精讲系列】基础算法：二分法](https://www.bilibili.com/video/BV11A411R7BK/)

### 算法模板

```cpp
int bsearch1(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2 + 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int bsearch2(int l, int r) {
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return r;
}

bool check(int x) {
    // ...
}
```

### 习题

| 类型 | 代码 | 链接 |
| --- | --- | --- |
| 整数二分 | [力扣 0033](./力扣%200033.cpp) | [查看原题](https://leetcode.cn/problems/search-in-rotated-sorted-array/) |
| 整数二分 | [力扣 0034](./力扣%200034.cpp) | [查看原题](https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/) |
| 整数二分 | [力扣 0035](./力扣%200035.cpp) | [查看原题](https://leetcode.cn/problems/search-insert-position/) |
| 整数二分 | [力扣 0069](./力扣%200069.cpp) | [查看原题](https://leetcode.cn/problems/sqrtx/) |
| 整数二分 | [力扣 0074](./力扣%200074.cpp) | [查看原题](https://leetcode.cn/problems/search-a-2d-matrix/) |
| 整数二分 | [力扣 0081](./力扣%200081.cpp) | [查看原题](https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/) |
| 整数二分 | [力扣 0153](./力扣%200153.cpp) | [查看原题](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/) |
| 整数二分 | [力扣 0154](./力扣%200154.cpp) | [查看原题](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/) |
| 整数二分 | [力扣 0162](./力扣%200162.cpp) | [查看原题](https://leetcode.cn/problems/find-peak-element/) |
