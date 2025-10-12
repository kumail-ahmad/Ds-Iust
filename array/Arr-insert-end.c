#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,8};
    int n=7,num=9;
    arr[n]=num;
    n++;

    printf("Array after insertion at end");
    for(int i=0;i<n;i++)
    printf("%d",arr[i]);
}