/*
Compile the largest integer by concatenating the given integers.
Input: A sequence of positive in- tegers.
Output: The largest integer that can be obtained by concatenating the given integers in some order.

Input format. The first line of the input contains an integer n. The second
line contains integers a1,...,an.
Output format. The largest number that can be composed out of a1,...,an.
Constraints. 1≤n≤100;1≤ai ≤103 forall1≤i≤n.

*/
#include <iostream>
#include <vector>
#include <algorithm>


std::string LargestConcatenate(std::vector<int>& Numbers) {
    std::string res = "";
    while(!Numbers.empty()) {
        auto maxNumberPtr = std::max_element(Numbers.begin(), Numbers.end());
        int maxNumber = *maxNumberPtr;

        res += std::to_string(maxNumber);

        Numbers.erase(maxNumberPtr);
    }

    return res;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> Numbers;
    for(int i=0; i<n; ++i){
        int num;
        std::cin >> num;
        Numbers.push_back(num);
    }
    std::string largestConcatenatedNumber = LargestConcatenate(Numbers);
    std::cout << largestConcatenatedNumber << '\n';
    
    return 0;
}