#include "../utils/common.h"
using namespace std;

class SlidingWindowTwoPointers {
public:
    // 模板1: 定长滑动窗口
    int fixedSizeWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        
        int sum = 0;
        // 初始化窗口
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        int maxSum = sum;
        // 滑动窗口
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];  // 新增一个，移除一个
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
    
    // 模板2: 变长滑动窗口 (求最长)
    int longestSubarray(vector<int>& nums, int target) {
        int left = 0, right = 0;
        int sum = 0;
        int maxLen = 0;
        
        while (right < nums.size()) {
            sum += nums[right];
            
            // 收缩窗口
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            
            // 更新答案
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
    
    // 模板3: 变长滑动窗口 (求最短)
    int shortestSubarray(vector<int>& nums, int target) {
        int left = 0, right = 0;
        int sum = 0;
        int minLen = INT_MAX;
        
        while (right < nums.size()) {
            sum += nums[right];
            
            // 收缩窗口
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            
            right++;
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
    
    // 模板4: 对撞指针
    vector<int> twoSum(vector<int>& nums, int target) {
        // 假设数组已排序
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return {left, right};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {};
    }
    
    // 模板5: 快慢指针 (检测环)
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return false;
    }
    
    // 模板6: 三指针 (三数之和)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // 跳过重复元素
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // 跳过重复元素
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
    
    // 模板7: 分组循环
    void groupLoop(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        while (i < n) {
            int start = i;
            // 找到当前组的结束位置
            while (i < n && shouldGroupTogether(nums, start, i)) {
                i++;
            }
            
            // 处理 [start, i) 这一组
            processGroup(nums, start, i);
        }
    }
    
private:
    bool shouldGroupTogether(vector<int>& nums, int start, int current) {
        // 具体的分组条件，根据题目而定
        return true;  // 示例
    }
    
    void processGroup(vector<int>& nums, int start, int end) {
        // 处理分组逻辑
    }
};

// 测试用例
bool testSlidingWindow() {
    SlidingWindowTwoPointers solution;
    
    // 测试定长滑动窗口
    vector<int> nums1 = {1, 2, 3, 4, 5};
    ASSERT_EQ(12, solution.fixedSizeWindow(nums1, 3));
    
    // 测试变长滑动窗口
    vector<int> nums2 = {1, 2, 1, 3, 2};
    ASSERT_EQ(3, solution.longestSubarray(nums2, 6));  // [1,2,1] 或 [1,3,2] 长度为3
    
    // 测试对撞指针
    vector<int> nums3 = {1, 2, 3, 4, 5};
    vector<int> expected = {0, 3};  // 索引0(值1) + 索引3(值4) = 5
    ASSERT_TRUE(vectorsEqual(expected, solution.twoSum(nums3, 5)));
    
    return true;
}

int main() {
    TestRunner::runTest("Sliding Window Two Pointers", testSlidingWindow);
    TestRunner::printSummary();
    return 0;
}