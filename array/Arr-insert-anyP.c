#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,6,7,8,9};
    int n=8,pos=4,num=5;


    for(int i=n;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=num;
    n++;

    printf("Array after insertion: ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}