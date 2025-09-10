#include <stdio.h>
#include <string.h>

void removeStars(char *s) {
    char stack[1000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '*') {
            if (top >= 0){
            top--;  
            }
        } else {
            stack[++top] = s[i];  
        }
    }
    stack[top + 1] = '\0';  
    printf("%s\n", stack);
}

int main() {
    char s1[] = "ab*c*d";
    removeStars(s1);

    char s2[] = "a*b*c*";
    removeStars(s2); 

    return 0;
}