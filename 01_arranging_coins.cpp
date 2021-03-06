/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/


// O(n) solution
class Solution {
public:
    int arrangeCoins(int n) {
        int coin = 0;
        long long sum = 0;
        while(sum <= n) {
            ++coin;
            sum += coin;
        }
        return coin-1;
    }
};

// O(logn) solution
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n;
        while (l <= r) {
            long long k = l + (r-l)/2;
            if (k*(k+1)/2 == n) return k;
            else if (k*(k+1)/2 < n) l = k + 1;
            else r = k - 1;
        }
        return r;
    }
};