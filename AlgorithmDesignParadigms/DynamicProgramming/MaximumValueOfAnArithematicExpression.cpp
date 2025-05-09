#include <iostream>
#include <vector>
#include <string>
#include <limits>

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}

int main() {
    std::string s;
    std::cin >> s;

    int n = (s.length() + 1) / 2; // Number of digits
    std::vector<int> nums(n);
    std::vector<char> ops(n - 1);

    // Parse the input string
    for (int i = 0; i < n; ++i) {
        nums[i] = s[2 * i] - '0'; // Convert char to int
    }
    for (int i = 0; i < n - 1; ++i) {
        ops[i] = s[2 * i + 1]; // Operators are at odd positions
    }

    // Initialize DP tables
    std::vector<std::vector<int>> maxValue(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> minValue(n, std::vector<int>(n, 0));

    // Base case: single numbers
    for (int i = 0; i < n; ++i) {
        maxValue[i][i] = nums[i];
        minValue[i][i] = nums[i];
    }

    // Fill the DP tables
    for (int len = 2; len <= n; ++len) { // length of the sub-expression
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // end index of sub-expression
            maxValue[i][j] = std::numeric_limits<int>::min();
            minValue[i][j] = std::numeric_limits<int>::max();

            // Check all possible partitions
            for (int k = i; k < j; ++k) {
                char op = ops[k]; // Operator between sub-expressions
                int a = applyOperation(maxValue[i][k], maxValue[k + 1][j], op);
                int b = applyOperation(maxValue[i][k], minValue[k + 1][j], op);
                int c = applyOperation(minValue[i][k], maxValue[k + 1][j], op);
                int d = applyOperation(minValue[i][k], minValue[k + 1][j], op);

                maxValue[i][j] = std::max(maxValue[i][j], std::max(a, std::max(b, std::max(c, d))));
                minValue[i][j] = std::min(minValue[i][j], std::min(a, std::min(b, std::min(c, d))));
            }
        }
    }

    // The maximum value of the entire expression
    std::cout << maxValue[0][n - 1] << '\n';

    return 0;
}