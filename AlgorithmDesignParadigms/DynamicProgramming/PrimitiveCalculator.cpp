/*
Find the minimum number of operations needed to get a positive integer nfrom 1 by using only three operations: add 1, multiply by 2, and multiply by 3.
Input: An integer n.
Output: The minimum number of operations “+1”, “×2”, and “×3” needed to get n from 1.


Input format. An integer n.
Output format. In the first line, output the minimum number kof operations needed to get nfrom 1. In the second line,
output a sequence of intermediate numbers. That is, the second line should contain positive integers a0,a1,...,ak such that
a0 = 1, ak = n and for all 1≤i≤k,
ai is equal to either ai−1 + 1, 2ai−1, or 3ai−1. If there are many such sequences, output any one of them.

Constraints: 1≤n≤106

Sample 1.
Input:
1
Output:
0
1


Sample 2.
Input:
96234
Output:
14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234

Another valid output in this case is “1 3 9 10 11 33 99 297 891 2673
8019 16038 16039 48117 96234”
*/


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void printSequence(int n, const std::vector<int>& prev) {
    std::vector<int> sequence;
    int current = n;

    while(current != -1) {
        sequence.push_back(current);
        current = prev[current];
    }

    // Since we've backtracked from n to 1, we need to reverse the sequence
    reverse(sequence.begin(), sequence.end());

    for(int num : sequence) {
        std::cout << num << " ";
    }
}

void minNumberOfOperationsFrom1ton(int n) {
    std::vector<int> minOperations(n+1, INT_MAX); // To store the minimum number of operations to reach i
    std::vector<int> previous(n+1, -1);        // To store the previous number before i in the optimal sequence 
    minOperations[1] = 0;           // Base case : 0 opeations to reach 1 as we start from 1

    for(int i = 2; i <= n; ++i) {
        minOperations[i] = minOperations[i-1] + 1; // Add 1 to i-1
        previous[i] = i-1; // Record the previous number that led to i

        if(i%2 == 0 && minOperations[i] > minOperations[i/2] + 1) {
            minOperations[i] = minOperations[i/2] + 1;
            previous[i] =  i/2;
        }

        if(i%3 == 0 && minOperations[i] > minOperations[i/3] + 1) {
            minOperations[i] = minOperations[i/3] + 1;
            previous[i] = i/3;
        }
    }
    std::cout <<  minOperations[n] << '\n';
    printSequence(n, previous);

}

int main() {

    int n;
    std::cin >> n;

    minNumberOfOperationsFrom1ton(n);

    return 0;
}
