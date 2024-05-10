#include <iostream>

using namespace std;

int *ComputePrefixFunction(string prefix) {
    int m = prefix.length();
    int *pi = new int[m];
    pi[1] = 0;
    int k = 0;
    for (int q = 2; q < m; q++) {
        while (k > 0 && prefix[k + 1] != prefix[q]) {
            k = pi[k];
        }
        if (prefix[k + 1] == prefix[q]) {
            k += 1;
        }
        pi[q] = k;
    }
    return pi;
}


void KMPMatcher(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    int *pi = ComputePrefixFunction(pattern);
    int q = 0;

    for (int i = 1; i < n; i++) {
        while (q > 0 && pattern[q + 1] != text[i]) {
            q=pi[q];
        }

        if(pattern[q+1]==text[i]){
            q++;
        }

        if (q == m) {
            printf("Pattern occurs\n");
            int q = pi[q];
        }
    }

}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
