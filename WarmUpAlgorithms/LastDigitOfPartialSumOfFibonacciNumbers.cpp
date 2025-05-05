#include <iostream>

long getFibonacciPartialSumFast(long m, long n) {
    long sum = 0;

    int m1 = static_cast<int>(m%60);
    int n1 = static_cast<int>(n%60);

    if(n1 < m1) {
        n1 += 60;
    }

    long current = 0;
    long next = 1;

    for(int i = 0; i <= n1; ++i) {
        if(i >= m1) {
            sum += current;
        }

        long newCurrent = next;
        next += current;
        current = newCurrent;
    }

    return (sum%10);
}

int main() {

    long m,n;
    std::cin >> m >> n;

    long res = getFibonacciPartialSumFast(m, n);
    std::cout << res << '\n';

    return 0;
}