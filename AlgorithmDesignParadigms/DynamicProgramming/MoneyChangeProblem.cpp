/*
Compute the minimum number of coins needed to change the given value into coins with given denominations.

Input format: Integer money.

Output format: The minimum number of coins with denominations 1, 3, and 4 that changes money.

Constraints: 1 ≤money ≤103

Sample:
Input:
34
Output:
9
34 = 3 + 3 + 4 + 4 + 4 + 4 + 4 + 4 + 4.
*/

#include <iostream>
#include <vector>
#include <climits>

int minNumberOfCoins(int t, std::vector<int>& coins){
    std::vector<int> dp(t+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= t; ++i) {
        for(int c : coins) {
            if(i-c >= 0) {
                dp[i] = std::min(dp[i], dp[i-c] + 1);
            }
        }
    }

    return dp[t] == INT_MAX ? -1 : dp[t];
}

// Driver Code
int main()
{
    int t;
    std::cin >> t;
	std::vector<int> coins = { 1, 3, 4 };
	std::cout << minNumberOfCoins(t, coins);
}

