# 7CompSort
This is a fun side project, it sorts 5 numbers in the optimal 7 comparisons. It uses a linked list structure to keep track of ordering.

The lower bound for sorting 5 numbers is log_2(5!) = 6.9...., which means at best, sorting 5 numbers is possible in 7 comparisons. This implementation
uses a linked list to keep track of the comparisons that have been made, and it suceeds in sorting all possible permutations of the array [1,2,3,4,5]
in 7 comparisons exactly.
