#include <iostream>
#include <cassert>

int naive_fibonacci(int n) {
    if(n <= 1)
        return n;
    return naive_fibonacci(n-1) + naive_fibonacci(n-2);
}

long long fast_fibonacci(int n) {
    if(n <= 1)
        return n;
    long long a = 0;
    long long b = 1;
    long long fib = 0;

    for(int i=2; i<=n; ++i) {
        fib = a+b;
        a = b;
        b = fib;
    }

    return fib;
}

void test_solution() {
    assert(fast_fibonacci(3) == 2);
    assert(fast_fibonacci(10) == 55);
    /*for(int k=0; k<50; ++k) {
        assert(fast_fibonacci(k) == naive_fibonacci(k));
    }*/
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << fast_fibonacci(n) << '\n';

    test_solution();

    return 0;
}