//Author : Md. Ibrahim Khan//

#include<stdio.h>
int main(){
    //ascending order
    int n;
    printf("give the size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("give the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        
    }

    //print sort array
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    



    return 0;
}