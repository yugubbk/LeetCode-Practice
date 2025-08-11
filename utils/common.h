#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <climits>
#include <cmath>
#include <functional>
#include <numeric>
#include <sstream>

// Common type aliases
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using vi = std::vector<int>;
using vl = std::vector<long long>;
using vs = std::vector<std::string>;
using vvi = std::vector<std::vector<int>>;
using vvl = std::vector<std::vector<long long>>;
using vvc = std::vector<std::vector<char>>;

// Include common data structures
#include "ListNode.h"
#include "TreeNode.h"
#include "UnionFind.h"
#include "test_framework.h"

// Common constants
const int MOD = 1000000007;
const int INF = INT_MAX;
const long long LLINF = LLONG_MAX;

// Utility functions
namespace Utils {
    // Print vector
    template<typename T>
    void printVector(const std::vector<T>& v, const std::string& name = "") {
        if (!name.empty()) std::cout << name << ": ";
        std::cout << "[";
        for (size_t i = 0; i < v.size(); ++i) {
            std::cout << v[i];
            if (i < v.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
    
    // Print 2D vector
    template<typename T>
    void print2DVector(const std::vector<std::vector<T>>& v, const std::string& name = "") {
        if (!name.empty()) std::cout << name << ":" << std::endl;
        std::cout << "[" << std::endl;
        for (const auto& row : v) {
            std::cout << "  [";
            for (size_t i = 0; i < row.size(); ++i) {
                std::cout << row[i];
                if (i < row.size() - 1) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "]" << std::endl;
    }
    
    // String split
    std::vector<std::string> split(const std::string& s, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(s);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    
    // GCD and LCM
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
}