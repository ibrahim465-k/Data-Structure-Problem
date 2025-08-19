//Author : Md. Ibrahim Khan//

#include<stdio.h>
int main(){
    int n;
    printf("give the size of array1\n");
    scanf("%d",&n);
    int arr1[n];
    printf("give the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr1[i]);
    }

    int m;
    printf("give the size of array\n");
    scanf("%d",&m);
    int arr2[m];
    printf("give the elements of array2\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&arr2[i]);
    }

    int merge_array[m+n];
    for (int i = 0; i < n; i++)
    {
        merge_array[i]=arr1[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        merge_array[n+i]=arr2[i];
    }
    
    for (int i = 0; i < m+n; i++)
    {
        printf("%d ",merge_array[i]);
    }
    


    return 0;
}