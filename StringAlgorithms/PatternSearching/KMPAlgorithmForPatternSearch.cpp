#include <iostream>
#include <vector>
#include <string>

std::vector<int> buildLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

void KMPSearch(const std::string& text, const std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int flag = 0;

    std::vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;

    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            std::cout << "Pattern found at: " << i - j << '\n';
            j = lps[j-1]; // Look for the next match
            flag = 1;
        }
        else if(i < n && text[i] != pattern[j]) {
            if(j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    if(flag == 0) {
        std::cout << "Pattern not found\n";
    }

}

int main()
{
    std::string text1 = "ABABDABACDABABCABAB";
    std::string pattern1 = "ABABCABAB";

    std::cout << "Search 1: \n";
    KMPSearch(text1, pattern1);

    std::string text2 = "AAAAABAAABA";
    std::string pattern2 = "AABBB";

    std::cout << "Search 2: \n";
    KMPSearch(text2, pattern2);

    std::string text3 = "ababcababacaaaaababaca";
    std::string pattern3 = "ababaca";

    std::cout << "Search 3: \n";
    KMPSearch(text3, pattern3);


    return 0;
} 