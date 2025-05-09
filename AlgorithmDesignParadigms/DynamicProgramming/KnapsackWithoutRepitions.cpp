#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int W, n; // Maximum weight and number of gold bars
    std::cin >> W >> n;
    
    std::vector<int> weights(n);
    
    // Read the weights of the gold bars
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    // Create a DP array to store the maximum weight that can be achieved with each capacity
    std::vector<int> dp(W + 1, 0);

    // Fill the DP table
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = std::max(dp[w], dp[w - weights[i]] + weights[i]);
        }
    }

    // The maximum weight that can be carried in the backpack
    std::cout << dp[W] << '\n';

    return 0;
}