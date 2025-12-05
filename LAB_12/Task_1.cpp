#include <iostream>
using namespace std;

int BruteForce(string text, string pattern){
    int n = text.length();
    int m = pattern.length();
    int comp = 0;
    int firstApp=-1;

    for (int i = 0;i <=n-m;i++){
        int j = 0;

        while(j<m){
            comp++;

            if(text[i + j]!=pattern[j]){
                break;     
            }
            j++;                    
        }

        if(j==m){         
            if (firstApp == -1)
                firstApp = i;
        }
    }

    cout << "first Appearance on index " << firstApp << endl;
    return comp;
}

int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int total = BruteForce(text, pattern);
    cout << "Total comparison " << total;
}