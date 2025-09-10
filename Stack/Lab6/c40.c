#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void reverseSubstring(char* str, int pos) {
    int start = 0, end = pos - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int T;
    scanf("%d", &T); 
    while (T--) {
        int N;
        scanf("%d", &N);

        char S[1001];  
        scanf("%s", S);

        for (int i = 0; i < N; i++) {
            if (isVowel(S[i])) {
                reverseSubstring(S, i);
            }
        }

        printf("%s\n", S); 
    }

    return 0;
}