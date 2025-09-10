#include<stdio.h>
#include<stdlib.h>
 int main(){

    int *iptr=(int *)malloc(sizeof(int));
    char *cptr=(char *)malloc(sizeof(char));
    float *fptr=(float *)malloc(sizeof(float));
    
    if(iptr==NULL||cptr==NULL||fptr==NULL){
        printf("FAILED TO ALLOCATE");
    }
    *iptr=4;
    *cptr='A';
    *fptr=3.4f;

    printf("Print integer= %d\n",*iptr);
    printf("Print character=%c\n",*cptr);
    printf("Print float=%f\n",*fptr);

    free(iptr);
    free(cptr);
    free(fptr);


}