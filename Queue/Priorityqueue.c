#include<stdio.h>
#include<limits.h>
    struct item{
        int value;
        int priority;
    };

    struct item pr[1000];
    int size=-1;

void enqueue(int value,int priority){
   if(size==MAX){
    printf("Queue overflow");
   }else{
    
   }
    }
int main(){
    enqueue(1);
    enqueue(3);
    enqueue(12);
    enqueue(5);
    enqueue(8);
    enqueue(10);

}