/*
  1 Collatz Conjecture

	If a number is odd, the next transform is 3*n+1
	If a number is even, the next transform is n/2
	The number is finally transformed into 1.
	The step is how many transforms needed for a number turned into 1.
	Given an integer n, output the max steps of transform number in [1, n] into 1.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, int> dp = {{1, 0}};
    int ans = 0;

    int dfs(int x) {
        if (dp.count(x)) return dp[x];
        if ((x & 1) == 0) return dp[x] = 1 + dfs(x / 2);
        else return dp[x] = 1 + dfs(x * 3 + 1);
    }

    int Collatz(int n) {
        dp[1] = 0;
        for (int i = n; i >= 1; i--) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};

int main() {
    Solution solution;
    assert(0 == solution.Collatz(1));
    assert(19 == solution.Collatz(10));
    assert(111 == solution.Collatz(37));
    assert(118 == solution.Collatz(101));
    return 0;
}
