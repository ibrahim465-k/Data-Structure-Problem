//Author : Md. Ibrahim Khan//

#include<stdio.h>
int main(){
    int n;
    printf("Give the size of array\n");
    scanf("%d",&n);
    printf("give the element of array index\n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int target;
    printf("give the target value you want to search\n");
    scanf("%d",&target);
    int low=0,high=n-1;
    while (low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==target){
            printf("Yes the value is in %d index",mid);
            return 0;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else low=mid+1;
    }
    printf("Not found");

    return 0;
}