#include "../utils/common.h"
using namespace std;

class DynamicProgramming {
public:
    // 模板1: 0/1背包问题
    int knapsack01(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= capacity; w++) {
                dp[i][w] = dp[i-1][w];  // 不选第i个物品
                if (w >= weights[i-1]) {
                    dp[i][w] = max(dp[i][w], dp[i-1][w-weights[i-1]] + values[i-1]);
                }
            }
        }
        
        return dp[n][capacity];
    }
    
    // 模板2: 完全背包问题
    int completeKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
        vector<int> dp(capacity + 1, 0);
        
        for (int i = 0; i < weights.size(); i++) {
            for (int w = weights[i]; w <= capacity; w++) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
        
        return dp[capacity];
    }
    
    // 模板3: 最长递增子序列 (LIS)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
    // 模板4: 最长公共子序列 (LCS)
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    // 模板5: 编辑距离
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // 初始化
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min({
                        dp[i-1][j] + 1,     // 删除
                        dp[i][j-1] + 1,     // 插入
                        dp[i-1][j-1] + 1    // 替换
                    });
                }
            }
        }
        
        return dp[m][n];
    }
    
    // 模板6: 区间DP - 矩阵链乘法
    int matrixChainOrder(vector<int>& dims) {
        int n = dims.size() - 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + dims[i] * dims[k+1] * dims[j+1];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    // 模板7: 状态机DP - 买卖股票
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        // dp[i][0] 表示第i天不持有股票的最大利润
        // dp[i][1] 表示第i天持有股票的最大利润
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        
        return dp[n-1][0];
    }
    
    // 模板8: 数位DP
    int countDigitOne(int n) {
        string s = to_string(n);
        int m = s.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        
        function<int(int, int, bool, bool)> dp = [&](int pos, int cnt, bool limit, bool isNum) -> int {
            if (pos == m) return isNum ? cnt : 0;
            
            if (!limit && isNum && memo[pos][cnt] != -1) {
                return memo[pos][cnt];
            }
            
            int res = 0;
            if (!isNum) {
                res = dp(pos + 1, cnt, false, false);
            }
            
            int up = limit ? s[pos] - '0' : 9;
            for (int d = 1 - isNum; d <= up; d++) {
                res += dp(pos + 1, cnt + (d == 1), limit && d == up, true);
            }
            
            if (!limit && isNum) {
                memo[pos][cnt] = res;
            }
            
            return res;
        };
        
        return dp(0, 0, true, false);
    }
    
    // 模板9: 树形DP - 树的直径
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;
            
            int leftDepth = dfs(node->left);
            int rightDepth = dfs(node->right);
            
            maxDiameter = max(maxDiameter, leftDepth + rightDepth);
            
            return max(leftDepth, rightDepth) + 1;
        };
        
        dfs(root);
        return maxDiameter;
    }
};

// 测试用例
bool testDynamicProgramming() {
    DynamicProgramming solution;
    
    // 测试0/1背包
    vector<int> weights = {1, 3, 4};
    vector<int> values = {1, 4, 5};
    ASSERT_EQ(5, solution.knapsack01(weights, values, 4));
    
    // 测试LIS
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    ASSERT_EQ(5, solution.lengthOfLIS(nums));
    
    // 测试LCS
    ASSERT_EQ(3, solution.longestCommonSubsequence("abcde", "ace"));
    
    return true;
}

int main() {
    TestRunner::runTest("Dynamic Programming", testDynamicProgramming);
    TestRunner::printSummary();
    return 0;
}