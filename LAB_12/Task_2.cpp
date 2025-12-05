#include <iostream>
using namespace std;

void rabinKarp(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    int d = 256;
    int q = 101;
    int h = 1;
    int p = 0;
    int t = 0;

    for (int i=0;i<m-1;i++)
        h =(h*d)%q;

    for (int i=0;i<m;i++){
        p = (d*p+pattern[i])%q;
        t = (d*t+text[i])%q;
    }

    for (int i = 0; i<=n-m;i++){
        if (p == t) {
            for(int j=0; j<m;j++) {
                if(text[i + j] != pattern[j]){
                    break;
                }
            }
        }
        if (i<n-m){
            t = (d*(t-text[i] * h) + text[i + 1 + m - 1]) % q;
            if (t < 0)
                t+=q;
        }
    }
}
int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    rabinKarp(text, pattern);
    return 0;
}