/*
Represent a positive integer as the sum of the maximum number of pairwise distinct positive integers.
Input: A positive integer n.
Output: The maximum k such that n can be represented as the sum a1 +···+ak of k distinct positive
integers.

Input format. An integer n.
Output format. In the first line, output the maximum number k such that n can be represented as
the sum of k pairwise distinct positive in- tegers. In the second line, output k pairwise distinct
positive integers that sum up to n (if there are multiple such representations, output any of them).

Constraints. 1 ≤ n ≤ 109.

Input
6

Output
3
1 2 3

*/

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    int sum = 0, k = 0;
    std::vector<int> numbers;

    // Greedily add numbers starting from 1 until sum exceeds n
    for(int i=1; sum+i <= n; ++i) {
        sum += i;
        numbers.push_back(i);
        k++;
    }

    // Add the difference between n and sum to the last number
    numbers[k - 1] += (n - sum);

    std::cout << k << '\n';

    for(int n : numbers)
        std::cout << n << " ";

    std::cout << '\n';

    return 0;
}