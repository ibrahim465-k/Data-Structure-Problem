//Author : Md. Ibrahim Khan//

#include<stdio.h>
int main(){
     int arr[100];
    printf("give the size of array\n");
    int size;
    scanf("%d",&size);
    printf("give the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("give the position where you want to delete the  value\n");
    int pos;
    scanf("%d",&pos);
   //left shift
   for (int i = pos; i < size; i++)
   {
    arr[i]=arr[i+1];
   }
   size--;
   for (int i = 0; i < size; i++)
   {
    printf("%d ",arr[i]);
   }
   
   



    return 0;
}