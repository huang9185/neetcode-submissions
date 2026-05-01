1. bruteforce
2. memoization: still using top-down approach but the recursive call stack is wasteful
3. should consider bottom up, more straight-forward and much simpler in code

*Understanding*
First two approaches are asking is [i...end] breakable.
Bottom-up should ask is [0...i] breakable

*Logic*
// dp[x] true when [0...x] breakable
for i 1 to n
    for j 0 to i
        if [0...j] breakable and [j...i] in dict, dp[i] true
