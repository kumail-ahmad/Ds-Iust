#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,4,5,6};
    int n=7,pos=4;

    for(int i =pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

    printf("array after deletion:");
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }
}