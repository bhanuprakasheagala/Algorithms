/*
Compute the minimum number of gas tank refills to get from one city to another.
Input: Integers d and m, as well as a sequence of integers stop1 < stop2 < ··· < stopn.
Output: The minimum number of refills to get from one city to another if a car can travel
at most m miles on a full tank. The distance between the cities is d miles and there are gas
stations at distances stop1,stop2,...,stopn along the way. We assume that a car starts with a full tank.

Input format:
The first line contains an integer d. The second line contains an integer m.
The third line specifies an integer n. Finally, the last line contains integers stop1,stop2,...,stopn.
Output format:
The minimum number of refills needed. If it is not possi- ble to reach the destination, output −1.
Constraints. 1≤d≤105. 1≤m≤400. 1≤n≤300. 0<stop1 <stop2 < ···<stopn <d.
*/
#include <iostream>
#include <vector>

int minRefills(int d, int m, int n, std::vector<int>& stops) {

    int numRefills = 0; // Number of Refills needed to reach the next destination
    int currentRefills = 0; // Keeps track of the current gas station the car is at
    int lastRefills = 0;    // Stores the last gas station where the car has refilled

    while(currentRefills <= n) {
        lastRefills = currentRefills;

        // Move to the farthest stop possible
        while(currentRefills <= n && (stops[currentRefills+1]-stops[lastRefills] <= m)) {
            currentRefills++;
        }
        // If unable to reach the next station
        if(currentRefills == lastRefills) {
            return -1;
        }

        if(currentRefills <= n) {
            numRefills++;
        }
    }
    return numRefills;
}

int main()
{
    int d, m, n;
    // Input distance b/w cities(d), the maximum distance a car can travel with full tank(m),
    // The number of gas stations(n)
    std::cin >> d >> m >> n;

    // Distances of the gas stations from the starting point
    std::vector<int> stops(n+2); // Includes start and end
    stops[0] = 0; // Start position
    stops[n+1] = d; // End position

    for(int i=1; i<=n; ++i) {
        std::cin >> stops[i];
    }

    int minRefillsNeeded = minRefills(d, m, n, stops);
    std::cout << minRefillsNeeded << '\n';

    return 0;
}