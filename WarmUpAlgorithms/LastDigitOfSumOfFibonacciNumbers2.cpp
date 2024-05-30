#include <iostream>

using namespace std;

int fibonacci_sum_last_digit(long long n) {
    if (n <= 1)
        return n;

    n = (n + 2) % 60; // Pisano period of 10 is 60

    int previous = 0;
    int current = 1;

    for (long long i = 2; i <= n; ++i) {
        int temp = (previous + current) % 10;
        previous = current;
        current = temp;
    }

    if (current == 0)
        return 9;
    else
        return (current - 1);
}

int main() {
    long long n;
    cin >> n;
    int result = fibonacci_sum_last_digit(n);
    cout << result << endl;
    return 0;
}