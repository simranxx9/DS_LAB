#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
struct node{
    int value;
    struct node *link;
};
typedef struct node *stkptr;
stkptr top[MAX_SIZE];
void insert(int data,int index_value);
int delete(int index_value);
void display(int index_value);
void main()
{
    int i=0,n=0;
    for(i=0;i<MAX_SIZE;i++)
    {
        top[i]=NULL;
    }
    while(1)
    {
        printf("...................ENTER................\n1:INSERT\n2:DELETE\n3:DISPLAY:\n4:EXIT\n");
    scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the index and data\n");
                scanf("%d%d",&i,&n);
                insert(n,i);
                break;
            case 2:printf("Enter the index");
                scanf("%d",&i);
                printf("Deleted element is %d   ",delete(i));
                printf("\n");
                break;
            case 3:printf("Enter the index");
                scanf("%d",&i);
                display(i);
                break;
            case 4:exit(0);
            default:printf("WRONG CHOICE\n");
        }
    }
}
void insert(int data,int index_value)
{
    stkptr temp=(stkptr)malloc(sizeof(struct node));
    temp->value=data;
    temp->link=top[index_value];
    top[index_value]=temp;
}
int delete(int index_value)
{
    int i=0;
    if(top[index_value]==NULL)
        printf("STACK EMPTY\n");
    else
    {
        stkptr temp=top[index_value];
        i=temp->value;
        top[index_value]=temp->link;
        free(temp);
    }
    return i;
}
void display(int index_value)
{
    stkptr temp=top[index_value];
    if(!top[index_value])
        printf("Stack empty\n");
    else
    {
        while(temp)
        {
            printf("%d  ",temp->value);
            temp=temp->link;
        }
        printf("\n");
    }
}