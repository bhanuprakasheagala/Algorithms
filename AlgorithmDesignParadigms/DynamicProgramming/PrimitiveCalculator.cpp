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