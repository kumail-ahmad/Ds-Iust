#include<stdio.h>
int main(){
    int arr[10] ={2,3,4,5};
    int n=4,i,num=1;


    for(i=n;i>0;i--){
        arr[i]=arr[i-1];
    }
        arr[0]=num;
        n++;
    
    printf("array after insertion at beginning");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
