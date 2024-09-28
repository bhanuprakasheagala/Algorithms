/*
Compute the minimum number of coins needed to change the given value into coins with denominations
1, 5, and 10.
Input. An integer money.
Output. The minimum number of coins with denomina- tions 1, 5, and 10 that changes money.
*/

#include <iostream>

int moneyChange(int money) {
    // Initialize coin denominations
    int denominations[] = {10, 5, 1};

    // Initialize count for each denomination
    int count[] = {0, 0, 0};

    // Iterate through each denomination
    for(int i=0; i<3; ++i) {
        // Count how many coins of this denomination we can take
        count[i] = money/denominations[i];

        // Update the remaining money after taking coins of this denomination
        money %= denominations[i];
    }

    // Sum up the counts of all denominations
    int minimumCoins = count[0] + count[1] + count[2];

    return minimumCoins;
}

int main()
{
    int money;
    std::cin >> money;

    std::cout << "Minimum number of coins needed: " << moneyChange(money) << '\n';   
    return 0;
}