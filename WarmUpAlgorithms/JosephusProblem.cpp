/*
Find the position of the survivor in the vicious series of killings described by Flavius Josephus,
the first-century historian and head of Jewish forces in Galilee.

Input: 
Natural numbers n and k. They represent n rebels standing in a circle.
Rebels are being eliminated in such a way that every k-th still alive rebel around the circle
is killed until only one rebel left. Rebels are killed clockwise
starting from rebel 0, i.e., rebel k-1 is killed first.

Output: 
The position of the survivor, denoted Josephus(n,k).
*/

#include <iostream>

int josephus(int n, int k) {
    if(n == 1)
        return 0;
    else
        return (josephus(n-1, k) + k) % n;
}

int main() {

    int n,k;
    std::cin >> n >> k;
    std::cout << josephus(n, k) << '\n';
    return 0;
}