#include <iostream>

using namespace std;

int fibonacci_sum_of_squares_last_digit(long long n) {
    if (n <= 0)
        return 0;

    n = n % 60; // Pisano period of 10 is 60

    int previous = 0;
    int current = 1;
    int sum_of_squares = 0; // Initialize sum

    for (int i = 1; i <= n; ++i) {
        int square = (current * current) % 10; // Compute square modulo 10
        sum_of_squares = (sum_of_squares + square) % 10; // Add square to sum
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    return sum_of_squares;
}

int main() {
    long long n;
    cin >> n;
    int result = fibonacci_sum_of_squares_last_digit(n);
    cout << result << endl;
    return 0;
}