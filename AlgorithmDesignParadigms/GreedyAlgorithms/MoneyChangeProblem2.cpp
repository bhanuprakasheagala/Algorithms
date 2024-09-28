/*
Compute the minimum number of coins needed to change the given value into coins with denominations
1, 5, and 10.
Input. An integer money.
Output. The minimum number of coins with denomina- tions 1, 5, and 10 that changes money.
*/

#include <iostream>
#include <vector>

int moneyChange(int money, std::vector<int>& denominations) {
    int numCoins = 0;
    int index = 0;
    while(money > 0) {
        // Find the largest denomination that does not exceed the remaining money
        while(index < denominations.size() && denominations[index] > money) {
            index++;
        }
        if(index < denominations.size()) {
            int maxCoin = denominations[index];
            money -= maxCoin;
            numCoins++;
        }
        else {
            break;
        }
    }

    return numCoins;
}

int main()
{
    int money;
    std::cin >> money;
    std::vector<int> denominations = {10, 5, 1};
    std::cout << "Minimum number of coins needed: " << moneyChange(money, denominations) << '\n';
    return 0;
}