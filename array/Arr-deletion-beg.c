#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9};
    int n=9;

    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;


    printf("Array after deletion");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}