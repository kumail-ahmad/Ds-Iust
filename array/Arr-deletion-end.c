#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4};
    int n=4;

    n--;

    printf("Array after deletion at end ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}