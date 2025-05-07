#include <iostream>
#include <vector>
#include <algorithm>

void longestCommonSubsequenceOf3Sequences(const std::vector<int>& A, int a, const std::vector<int>& B, int b, const std::vector<int>& C, int c) {
    // Initialize the 3D DP table with dimensions (a+1) x (b+1) x (c+1)
    std::vector<std::vector<std::vector<int>>> table3D(a + 1, std::vector<std::vector<int>>(b + 1, std::vector<int>(c + 1, 0)));

    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            for(int k = 1; k <= c; ++k) {
                if(A[i-1] == B[j-1] && B[j-1] == C[k-1]) {
                    table3D[i][j][k] = table3D[i-1][j-1][k-1] + 1;
                } else {
                    table3D[i][j][k] = std::max({table3D[i][j-1][k], table3D[i-1][j][k], table3D[i][j][k-1]});
                }
            }
        }
    }
    std::cout << table3D[a][b][c] << std::endl; // Output the length of LCS
}

int main() {
    int p, q, r;
    std::cin >> p;
    std::vector<int> seq1(p);
    for(int i=0; i<p; ++i) {
        std::cin >> seq1[i];
    }

    std::cin >> q;
    std::vector<int> seq2(q);
    for(int i=0; i<q; ++i) {
        std::cin >> seq2[i];
    }

    std::cin >> r;
    std::vector<int> seq3(r);
    for(int i=0; i<r; ++i) {
        std::cin >> seq3[i];
    }

    longestCommonSubsequenceOf3Sequences(seq1, p, seq2, q, seq3, r);

    return 0;
}