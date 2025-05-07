#include <iostream>
#include <vector>
#include <algorithm>

void longestCommonSubsequence(const std::vector<int>& A, const std::vector<int>& B) {
    int m = A.size();
    int n = B.size();
    std::vector<std::vector<int>> table2D(m+1, std::vector<int>(n+1, 0));

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(A[i-1] == B[j-1]) {
                table2D[i][j] = table2D[i-1][j-1] + 1;
            }
            else {
                table2D[i][j] = std::max(table2D[i-1][j], table2D[i][j-1]);
            }
        }
    }
    
    std::cout << table2D[m][n];
}

int main() {

    int n, m;
    std::cin >> m;
    std::vector<int> seq1(m);
    for(int i=0; i<m; ++i) {
        std::cin >> seq1[i];
    }

    std::cin >> n;
    std::vector<int> seq2(n);
    for(int i=0; i<n; ++i) {
        std::cin >> seq2[i];
    }

    longestCommonSubsequence(seq1, seq2);

    return 0;
}