//Author : Md. Ibrahim Khan//

#include<stdio.h>
#include<string.h>
struct  student
{
    char name[100];
    int age;
    long long id;
};

int main(){
    struct student student1;
    scanf("%d",&student1.age);
    scanf("%lld",&student1.id);
    getchar();
    gets(student1.name);
    // strcpy(student1.name,"Ibrahim Khan");
    // student1.age=21;
    // student1.id=161106;
    printf("%s %d %lld",student1.name,student1.age,student1.id);


    return 0;
}