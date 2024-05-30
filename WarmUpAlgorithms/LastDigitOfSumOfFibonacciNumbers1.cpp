#include <iostream>
#include <vector>

using namespace std;

int fibonacci_sum_last_digit(long long n) {
    if (n <= 1)
        return n;

    vector<int> fib(n + 1);
    fib[0] = 0;
    fib[1] = 1;

    // Compute Fibonacci numbers and store their last digits
    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
    }

    // Compute the sum of Fibonacci numbers' last digits
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum = (sum + fib[i]) % 10;
    }

    return sum;
}

int main() {
    long long n;
    cin >> n;
    int result = fibonacci_sum_last_digit(n);
    cout << result << endl;
    return 0;
}