/*
Implement the algorithm to compute x^n using the Divide and Conquer method.
*/

#include <iostream>
template <typename T>
T power(T x, int n) {
    if(n == 0) {
        return 1;  // Base case: x^0 is 1
    }
    if(n == 1) {
        return x;  // Base case: x^1 is x
    }

    // Divide the exponent into half
    T halfPower = power(x, n/2);

    // Combine the results based on whether n is even or odd
    if(n % 2 == 0) {
        return halfPower * halfPower;
    }
    else {
        return x * halfPower * halfPower;
    }
}

int main()
{
    double x = 2.5;
    int y = 5;
    int n = 3;
    std::cout << x << "^" << n << " = " << power(x, n) << '\n';
    std::cout << y << "^" << n << " = " << power(y, n) << '\n';
    return 0;
}