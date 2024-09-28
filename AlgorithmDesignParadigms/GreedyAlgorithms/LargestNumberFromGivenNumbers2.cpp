#include <iostream>
#include <vector>
#include <algorithm>

bool customCompare(int a, int b) {
    // Covert both numbers to strings
    std::string n1 = std::to_string(a);
    std::string n2 = std::to_string(b);

    // Concatenate n1 and n2 in two different orders
    std::string order1 = n1 + n2;
    std::string order2 = n2 + n1;

    // Compare order1 and order2 digit by digit
    return order1 > order2;
}

std::string LargestConcatenate(std::vector<int>& Numbers) {
    // Sort the numbers using custom comparision
    std::sort(Numbers.begin(), Numbers.end(), customCompare);

    // Concatenate the sorted numbers
    std::string res = "";
    for(int n : Numbers)
        res += std::to_string(n);

    return res;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> Numbers(n);
    for(int i=0; i<n; ++i) {
        std::cin >> Numbers[i];
    }
    std::string largestConcatenatedNumber = LargestConcatenate(Numbers);
    std::cout << largestConcatenatedNumber << '\n';

    return 0;
}