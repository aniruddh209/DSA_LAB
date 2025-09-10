#include<stdio.h>
int binarysearch(){
    int key,n;
    printf("Enter a size of an array=");
    scanf("%d",&n);
    int a[n];
    printf("Enter a array=");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
    printf("Array was=");
    for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
}
    printf("enter a key=");
    scanf("%d",&key);

    int left=0;
    int right=n-1;
    while(left<=right){
        int middle=(left+right)/2;
        if (a[middle]==key){
            return middle;
        }
        else if(key<middle){
            right=middle-1;
        }
        else{
            left=middle+1;
        }
    }
    return -1;
}
int main(){
   int result=binarysearch();
   if(result==-1){
    printf("Key not found");
   }
   else{
    printf("key found at index %d",result);
   }

}