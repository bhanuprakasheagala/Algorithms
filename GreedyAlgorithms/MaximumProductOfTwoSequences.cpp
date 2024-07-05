/*
Input: Two sequences of n positive integers: price1,...,pricen and clicks1,...,clicksn.
Output: The maximum value of price1 ·c1 +···+pricen ·cn, where c1,...,cn is a permutation of
clicks1,...,clicksn.

Examples:

Sample 1.
Input:
1
23
39
Output:
897
897=23·39. 

Sample 2.
Input:
3
2 3 9
7 4 2
Output:
79
79=7·9+2·2+3·4.

Constraints. 1 ≤ n ≤ 103; 0 ≤ pricei,clicksi ≤ 105 for all 1 ≤ i ≤ n.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxDotProduct(vector<int>& prices, vector<int>& clicks) {
    int n = prices.size();

    // Sort prices and clicks in non-decreasing order
    sort(prices.begin(), prices.end());
    sort(clicks.begin(), clicks.end());

    long long maxDot = 0;
    for (int i = 0; i < n; ++i) {
        maxDot += (long long)prices[i] * clicks[i];
    }

    return maxDot;
}

int main() {
    int n;
    cin >> n;

    // Input validation for n
    if (n < 1 || n > 1000) {
        //cout << "Invalid input for n" << endl;
        return 1;
    }

    vector<int> prices(n), clicks(n);

    // Input validation and reading prices
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
        if (prices[i] < 0 || prices[i] > 100000) {
            //cout << "Invalid input for prices" << endl;
            return 1;
        }
    }

    // Input validation and reading clicks
    for (int i = 0; i < n; ++i) {
        cin >> clicks[i];
        if (clicks[i] < 0 || clicks[i] > 100000) {
            //cout << "Invalid input for clicks" << endl;
            return 1;
        }
    }

    long long maxDot = maxDotProduct(prices, clicks);
    cout << /*"Maximum dot product: " << */maxDot << endl;

    return 0;
}