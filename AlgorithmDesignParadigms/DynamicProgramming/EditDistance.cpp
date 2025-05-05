#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int editDistance(std::string& s1, std::string& s2) {
    int m = s1.length();
    int n = s2.length();

    // prev stores the result for (i-1)th row and curr stores the result for ith row
    std::vector<int> prev(n+1, 0);
    std::vector<int> curr(n+1, 0);

    // For 0-th row
    for(int j = 0; j <= n; ++j) {
        prev[j] = j;
    }

    // Rest of the rows
    for(int i = 1; i <= m; i++) {
        curr[0] = i; // j = 0;
        for(int j = 1; j <= n; ++j) {
            if(s1[i-1] == s2[j-1]) {
                curr[j] = prev[j-1];
            }
            else {
                curr[j] = 1 + std::min({curr[j-1], prev[j], prev[j-1]});
            }
        }
        prev = curr;
    }

    return prev[n];

}

int main() {
    std::string str1, str2;
    std::cin >> str1;
    std::cin >> str2;

    std::cout << editDistance(str1, str2);

    return 0;
}