# LeetCode C++ 练习项目

一个系统化的 LeetCode 算法练习项目，基于12个核心算法分类进行组织，使用 C++17 实现。

## 📁 项目结构

```
LeetCode-Practice/
├── 01-sliding-window-two-pointers/     # 滑动窗口与双指针
├── 02-binary-search/                   # 二分算法
├── 03-monotonic-stack/                 # 单调栈
├── 04-grid-graph/                      # 网格图
├── 05-bit-manipulation/                # 位运算
├── 06-graph-algorithms/                # 图论算法
├── 07-dynamic-programming/             # 动态规划
├── 08-data-structures/                 # 常用数据结构
├── 09-math-algorithms/                 # 数学算法
├── 10-greedy-thinking/                 # 贪心与思维
├── 11-linkedlist-tree-backtrack/       # 链表、二叉树与回溯
├── 12-string-algorithms/               # 字符串
├── templates/                          # 通用模板和数据结构
├── utils/                              # 测试和辅助工具
└── CMakeLists.txt                      # 构建配置
```

## 🎯 算法分类详情

### 1. 滑动窗口与双指针
- 定长/不定长滑动窗口
- 单序列/双序列双指针
- 三指针、分组循环

### 2. 二分算法
- 二分答案、最小化最大值
- 最大化最小值、第K小

### 3. 单调栈
- 基础单调栈、矩形面积
- 贡献法、最小字典序

### 4. 网格图
- DFS/BFS遍历
- 综合应用

### 5. 位运算
- 基础位运算、性质应用
- 拆位、试填、恒等式、思维

### 6. 图论算法
- DFS/BFS、拓扑排序、基环树
- 最短路、最小生成树、网络流

### 7. 动态规划
- 入门DP、背包问题、划分DP
- 状态机、区间DP、状压DP
- 数位DP、数据结构优化
- 树形DP、博弈DP、概率期望

### 8. 常用数据结构
- 前缀和、差分、栈、队列、堆
- 字典树、并查集、树状数组、线段树

### 9. 数学算法
- 数论、组合数学、概率期望
- 博弈论、计算几何、随机算法

### 10. 贪心与思维
- 基本贪心策略、反悔贪心
- 区间贪心、字典序、数学
- 思维题、脑筋急转弯、构造

### 11. 链表、二叉树与回溯
- 前后指针、快慢指针
- DFS/BFS、直径、LCA、一般树

### 12. 字符串算法
- KMP、Z函数、Manacher
- 字符串哈希、AC自动机
- 后缀数组、子序列自动机

## 🚀 快速开始

### 环境要求
- C++17 或更高版本
- CMake 3.16 或更高版本
- 支持的编译器：GCC、Clang、MSVC

### 构建项目
```bash
mkdir build
cd build
cmake ..
make
```

### 运行单个算法分类的模板
```bash
# 例如运行滑动窗口模板
./01-sliding-window-two-pointers_template

# 或运行动态规划模板  
./07-dynamic-programming_template
```

### 编译特定题目
```bash
# 假设在 01-sliding-window-two-pointers/problems/ 下有 0003-longest-substring.cpp
make 01-sliding-window-two-pointers_0003-longest-substring
./01-sliding-window-two-pointers_0003-longest-substring
```

## 📝 使用方法

### 1. 学习算法模板
每个分类目录下都有：
- `README.md` - 算法知识点总结
- `template.cpp` - 核心算法模板代码
- `problems/` - 具体题目解答
- `notes/` - 学习笔记

### 2. 添加新题目
在对应分类的 `problems/` 目录下创建新的 `.cpp` 文件：
```cpp
#include "../utils/common.h"
using namespace std;

class Solution {
public:
    // 你的解法
};

// 测试用例
bool testSolution() {
    Solution solution;
    // 添加测试
    return true;
}

int main() {
    TestRunner::runTest("题目名称", testSolution);
    TestRunner::printSummary();
    return 0;
}
```

### 3. 使用通用工具
- `templates/` 提供常用数据结构：ListNode、TreeNode、UnionFind
- `utils/` 提供测试框架和通用函数
- 所有文件都可以通过 `#include "../utils/common.h"` 使用

## 🛠️ 内置工具

### 数据结构
- **ListNode**: 链表节点，包含创建、打印、删除等辅助函数
- **TreeNode**: 二叉树节点，支持层序创建和遍历
- **UnionFind**: 并查集，支持路径压缩和按秩合并

### 测试框架
- `ASSERT_EQ(expected, actual)` - 断言相等
- `ASSERT_TRUE(condition)` - 断言为真
- `TestRunner::runTest()` - 运行单个测试
- `TestRunner::printSummary()` - 打印测试总结

## 📊 学习建议

1. **按分类系统学习**: 每次专注一个算法分类
2. **理解模板代码**: 先理解每个分类的核心模板
3. **大量练习**: 在 problems 目录下添加具体题目
4. **总结规律**: 在 notes 目录下记录解题心得
5. **测试驱动**: 为每个解法编写完整的测试用例

## 🤝 贡献指南

欢迎提交 Pull Request 来完善这个项目：
- 添加新的算法模板
- 补充经典题目解答  
- 优化代码实现
- 修正文档错误

## 📄 许可证

MIT License - 详见 [LICENSE](LICENSE) 文件

---

**Happy Coding! 🎉**