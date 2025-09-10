#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
s[top]='(';
void push(char ch){
    if(top<max-1){
        top++;
        stack[top]=ch;
    }
}
int pop(){
    if(top>=0){
        return stack[top--];
    }
    return '\0';
}
int main(){
    char string[max];
    int i=0;
    printf("Enter a string=");
    fgets(string,max,stdin);
    push('c');
    while(string[i]!='\0' && string[i]!='c' ){
        if(string[i]==' '){
            printf("invalid string..");
            return 0;
        }
        push(string[i]);
        i++;
    }
    if(string[i]!='c'){
        printf("Inavalid string");
        return 0;
    }

    i++;

    while(top>=0 && stack[top]!='c'){
        char ch=pop();
        if(string[i]=='\0'||string[i]!=ch){
            printf("Invalid string");
            return 0;
        }
        i++;
    }
    if(string[i]=='\0'||string[i]==' '||string[i]=='\n'){
        printf("valid string");
    }else{
    printf("invalid string");
    }
  return 0;
}

