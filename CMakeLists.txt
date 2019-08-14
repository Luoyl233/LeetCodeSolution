cmake_minimum_required(VERSION 2.8)

project(leetcode)

aux_source_directory(. DIR_SRCS)

add_executable(${PROJECT_NAME} ${DIR_SRCS}
#    "common.h"
#    #"main.cpp"
#    "findmediansortedarrays.cpp"
#    #"searchinsert.cpp"
#    #"removeelement.cpp"
#    #"ispalindrome.cpp"
#    #"removeduplicatesfromsortedarray.cpp"
#    #"merge_two_sorted_lists.cpp"
#    "valid_parentheses.cpp"
#    "4sum.cpp"
#    "clone_graph.cpp"
#    "course_schedule.cpp"
#    "mergeklists.cpp"
#    "combinationsum.cpp"
#    "inorder_traversal.cpp"
#    "postorder_traversal.cpp"
#    "is_valid_bst.cpp"
#    "max_path_sum.cpp"
#    "find_median_from_data_stream.cpp"
#    "length_of_longest_substring.cpp"
#    "longest_palindrome.cpp"
#    #"zigzag_conversion.cpp"
#    #"atoi.cpp"

    )
