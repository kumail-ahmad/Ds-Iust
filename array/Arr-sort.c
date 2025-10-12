#include<stdio.h>
int main(){
    int arr[5]={2,3,5,4,1},n=5,temp;
    for(int i =0;i<n-1;i++){
        for(int j =i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j] = temp;

            }
        }
    }

    printf("Array after sorting");
    for(int i = 0;i<n;i++){
        printf("%d",arr[i]);
    }
}