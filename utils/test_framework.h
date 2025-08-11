#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <functional>

#define ASSERT_EQ(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            std::cout << "ASSERTION FAILED: " << __FILE__ << ":" << __LINE__ << std::endl; \
            std::cout << "Expected: " << (expected) << ", Actual: " << (actual) << std::endl; \
            return false; \
        } \
    } while(0)

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            std::cout << "ASSERTION FAILED: " << __FILE__ << ":" << __LINE__ << std::endl; \
            std::cout << "Expected true, but got false" << std::endl; \
            return false; \
        } \
    } while(0)

#define ASSERT_FALSE(condition) \
    do { \
        if (condition) { \
            std::cout << "ASSERTION FAILED: " << __FILE__ << ":" << __LINE__ << std::endl; \
            std::cout << "Expected false, but got true" << std::endl; \
            return false; \
        } \
    } while(0)

class TestRunner {
private:
    static int total_tests;
    static int passed_tests;
    
public:
    static void runTest(const std::string& testName, std::function<bool()> test) {
        total_tests++;
        std::cout << "Running " << testName << "... ";
        
        if (test()) {
            std::cout << "PASSED" << std::endl;
            passed_tests++;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
    
    static void printSummary() {
        std::cout << "\n=== Test Summary ===" << std::endl;
        std::cout << "Total tests: " << total_tests << std::endl;
        std::cout << "Passed: " << passed_tests << std::endl;
        std::cout << "Failed: " << (total_tests - passed_tests) << std::endl;
        
        if (passed_tests == total_tests) {
            std::cout << "All tests passed! ✅" << std::endl;
        } else {
            std::cout << "Some tests failed! ❌" << std::endl;
        }
    }
    
    static void reset() {
        total_tests = 0;
        passed_tests = 0;
    }
};

// Template for comparing vectors
template<typename T>
bool vectorsEqual(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// Template for printing vectors
template<typename T>
std::string vectorToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << v[i];
        if (i < v.size() - 1) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Initialize static members
int TestRunner::total_tests = 0;
int TestRunner::passed_tests = 0;