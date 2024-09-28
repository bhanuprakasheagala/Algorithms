/*
Compute the minimum number of coins needed to change the given value into coins with denominations
1, 5, and 10.
Input. An integer money.
Output. The minimum number of coins with denomina- tions 1, 5, and 10 that changes money.

*/

#include <iostream>

int main()
{
    int money;
    std::cin >> money;
    int numCoins = 0;
    
    while(money > 0) {
        if(money >= 10) {
            money -= 10;
        }
        else if(money >= 5) {
            money -= 5;
        }
        else {
            money -= 1;
        }
        numCoins += 1;
    }

    std::cout << numCoins << '\n';

    /*
    One Line Solution:
    std::cout << floor(money/10) + floor((money%10)/5) + money%5 << '\n';
    */
    return 0;
}