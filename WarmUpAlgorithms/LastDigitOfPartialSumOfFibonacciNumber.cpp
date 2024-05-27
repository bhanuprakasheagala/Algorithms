#include <iostream>

using namespace std;

int fibonacci_partial_sum_last_digit(long long m, long long n) {
    if (n <= 1)
        return n;

    m = (m + 1) % 60; // Adjust m to get the next Fibonacci number
    n = (n + 2) % 60; // Adjust n to get the next Fibonacci number

    int previous = 0;
    int current = 1;

    // Compute the nth Fibonacci number modulo 10
    for (long long i = 2; i <= n; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    // Compute the mth Fibonacci number modulo 10
    for (long long i = 2; i < m; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    // Compute the partial sum modulo 10
    int sum = current;
    if (sum == 0)
        return 9;
    else
        return (sum - 1);
}

int main() {
    long long m, n;
    cin >> m >> n;
    int result = fibonacci_partial_sum_last_digit(m, n);
    cout << result << endl;
    return 0;
}