#include <iostream>
#include <vector>

int get_fibonacci_last_digit(long long n) {
    std::vector<int> fibonacci(n+1);
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for(int i=2; i<=n; ++i) {
        fibonacci[i] = (fibonacci[i-1]+fibonacci[i-2])%10;
    }

    return fibonacci[n];
}

int main()
{
    long long n;
    std::cout << "Enter the positive integer: ";
    std::cin >> n;

    int last_digit = get_fibonacci_last_digit(n);
    std::cout << "last digit of fibonacci(" << n << ") is: " << last_digit << '\n';

    return 0;
}