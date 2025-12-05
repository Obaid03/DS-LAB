#include <iostream>
using namespace std;

void computeLPS(string pattern, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMP(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int* lps = new int[m];
    computeLPS(pattern, m, lps);

    for (int i = 0; i < m; i++) {
        cout << lps[i];
        if (i <m-1) cout << ", ";
    }
    bool first = true;
    int i = 0;
    int j = 0;

    while (i<n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if (j==m){
            if (!first) cout << ", ";
            cout << (i - j);
            first = false;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    delete[] lps;
}

int main() {
    string text = "ababababc";
    string pattern = "abab";

    KMP(text, pattern);

    return 0;
}