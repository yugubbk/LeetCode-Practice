#pragma once
#include <vector>
#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper functions for binary tree operations
class TreeHelper {
public:
    // Create binary tree from level-order array (LeetCode format)
    // null values represented as INT_MIN
    static TreeNode* createTree(const std::vector<int>& values) {
        if (values.empty() || values[0] == INT_MIN) return nullptr;
        
        TreeNode* root = new TreeNode(values[0]);
        std::queue<TreeNode*> q;
        q.push(root);
        
        size_t i = 1;
        while (!q.empty() && i < values.size()) {
            TreeNode* current = q.front();
            q.pop();
            
            // Left child
            if (i < values.size() && values[i] != INT_MIN) {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }
            i++;
            
            // Right child
            if (i < values.size() && values[i] != INT_MIN) {
                current->right = new TreeNode(values[i]);
                q.push(current->right);
            }
            i++;
        }
        
        return root;
    }
    
    // Convert binary tree to level-order array
    static std::vector<int> toLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<int> result;
        std::queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current) {
                result.push_back(current->val);
                q.push(current->left);
                q.push(current->right);
            } else {
                result.push_back(INT_MIN);
            }
        }
        
        // Remove trailing nulls
        while (!result.empty() && result.back() == INT_MIN) {
            result.pop_back();
        }
        
        return result;
    }
    
    // Print tree in level-order
    static void print(TreeNode* root) {
        auto values = toLevelOrder(root);
        std::cout << "[";
        for (size_t i = 0; i < values.size(); ++i) {
            if (values[i] == INT_MIN) {
                std::cout << "null";
            } else {
                std::cout << values[i];
            }
            if (i < values.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    // Delete entire tree
    static void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    
    // Tree traversal methods
    static void preorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorderTraversal(root->left, result);
        preorderTraversal(root->right, result);
    }
    
    static void inorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        inorderTraversal(root->left, result);
        result.push_back(root->val);
        inorderTraversal(root->right, result);
    }
    
    static void postorderTraversal(TreeNode* root, std::vector<int>& result) {
        if (!root) return;
        postorderTraversal(root->left, result);
        postorderTraversal(root->right, result);
        result.push_back(root->val);
    }
};