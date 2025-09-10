//WAP to check whether the string is Palindrome or not using Pointer.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str) {
    char *start = str;
    char *end = str + strlen(str) - 1;
    
    while (start < end) {
        while (!isalnum(*start) && start < end) {
            start++;
        }
        while (!isalnum(*end) && start < end) {
            end--;
        }
        
        if (tolower(*start) != tolower(*end)) {
            return 0; 
        }
        
        start++;
        end--;
    }
    return 1;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    if (isPalindrome(str)) {
        printf("'%s' is a palindrome.\n", str);
    } else {
        printf("'%s' is not a palindrome.\n", str);
    }
    
    return 0;
}