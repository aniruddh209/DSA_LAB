#include<stdio.h>
#define max 4
    int top=-1;
    int s[max];
    void push(int x){
        if(top>=max-1){
            printf("stack overflow");
            return;
        }
        top++;
        s[top]=x;
    }
    void pop(){
        if(top<=0){
            printf("Stack underflow");
            return;
        }
        top--;
        printf("%d",s[top+1]);
    }
    void peep(int i){
        if(top-i+1<0){
            printf("stack underflow");
            return;
        }
        printf("%d",s[top-i+1]);
    }
    void change(int x,int i){
        if(top-i+1<0){
            printf("stack underflow");
        }
        s[top-i+1]=x;
    }
    void display(){
        for(int i=0;i<max;i++){
        printf("%d\n",s[i]);
        }
    }
    int main(){
    push(10);
    push(20);
    push(30); 
    push(40); 
    display();
    change(11,4);
    printf("After change\n");
    display();

    }


