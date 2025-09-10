#include <stdio.h>
#include <string.h>
#define MAX 100

int main() {
    char str[MAX];
    int i, count_a = 0, count_b = 0, valid = 1;

    printf("Enter the string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            if (count_b > 0) {
                valid = 0; 
                break;
            }
            count_a++;
        } else if (str[i] == 'b') {
            count_b++;
        } else {
            valid = 0;
            break;
        }
    }

    if (valid && count_a == count_b && count_a >= 1) {
        printf("The string is of the form a^i b^i where i >= 1.\n");
    } else {
        printf("The string is NOT of the form a^i b^i where i >= 1.\n");
    }
    return 0;
}