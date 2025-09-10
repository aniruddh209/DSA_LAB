#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        top++;
        stack[top] = ch;
    }
}
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int main() {
    char string[MAX];
    int i = 0;

    printf("Enter the string (end with space): ");
    fgets(string, MAX, stdin);  

    push('c');

    while (string[i] != '\0' && string[i] != 'c') {
        if (string[i] == ' ') {
            printf("INVALID STRING\n");
            return 0;
        }
        push(string[i]);
        i++;
    }

    if (string[i] != 'c') {
        printf("INVALID STRING\n");
        return 0;
    }

    i++; 

    while (top >= 0 && stack[top] != 'c') {
        char ch = pop();
        if (string[i] == '\0' || string[i] != ch) {
            printf("INVALID STRING\n");
            return 0;
        }
        i++;
    }

    if (string[i] == ' ' || string[i] == '\n' || string[i] == '\0') {
        printf("VALID STRING\n");
    } else {
        printf("INVALID STRING\n");
    }

    return 0;
}