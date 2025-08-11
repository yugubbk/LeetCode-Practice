cmake_minimum_required(VERSION 3.16)
project(LeetCodePractice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(templates)
include_directories(utils)

# Compiler flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=address")
endif()

# Function to create executables for a category
function(add_category_problems CATEGORY_DIR)
    file(GLOB_RECURSE PROBLEM_FILES "${CATEGORY_DIR}/problems/*.cpp")
    foreach(PROBLEM_FILE ${PROBLEM_FILES})
        get_filename_component(PROBLEM_NAME ${PROBLEM_FILE} NAME_WE)
        get_filename_component(CATEGORY_NAME ${CATEGORY_DIR} NAME)
        set(TARGET_NAME "${CATEGORY_NAME}_${PROBLEM_NAME}")
        add_executable(${TARGET_NAME} ${PROBLEM_FILE})
    endforeach()
endfunction()

# Add all category problems
add_category_problems("01-sliding-window-two-pointers")
add_category_problems("02-binary-search")
add_category_problems("03-monotonic-stack")
add_category_problems("04-grid-graph")
add_category_problems("05-bit-manipulation")
add_category_problems("06-graph-algorithms")
add_category_problems("07-dynamic-programming")
add_category_problems("08-data-structures")
add_category_problems("09-math-algorithms")
add_category_problems("10-greedy-thinking")
add_category_problems("11-linkedlist-tree-backtrack")
add_category_problems("12-string-algorithms")

# Optional: Create a custom target to build all problems
add_custom_target(all_problems)
add_dependencies(all_problems 
    # Dependencies will be added automatically when .cpp files are created
)