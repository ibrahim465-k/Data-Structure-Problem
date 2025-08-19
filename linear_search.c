//Author : Md. Ibrahim Khan//

#include<stdio.h>
int main(){
    int n;
    printf("give the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("give the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int target;
    printf("give the target value\n");
    scanf("%d",&target);
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==target){
            printf("target value is found in %d index",i);
            return 0;
        }
    }
    printf("Not found");
    


    return 0;
}