#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef struct{
    int key;
}element;
int n=0;
element heap[MAX_SIZE];
void push(element data);
element pop();
void display();
void main()
{
    int n;
    element k;
    while(1)
    {
        printf("....................ENTER.....................\n1:PUSH\n2:POP\n3:DISPLAY\n4:EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the element to be inserted\n");
                   scanf("%d",&k.key);
                   push(k);
                   break;
            case 2:k=pop();
                   printf("Deleted element is %d  ",k.key);
                   printf("\n");
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
            default:printf("WRONG CHOICE\n");
        }
    }

}
void push(element data)
{
    int i;
    i=++n;
    while(i!=1&&(data.key>heap[i/2].key))
    {
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=data;
}
element pop()
{
    int parent=1,child=2;
    element temp,item;
    if(n==0)
    {
        printf("NO HEAP\n");
    }
    item=heap[1];
    temp=heap[n--];
    while(child<=n)
    {
        if(child<n&&(heap[child].key<heap[child+1].key))
        {
            child++;
        }
        if(temp.key>=heap[child].key)
            break;
        heap[parent]=heap[child];
        parent=child;
        child*=2;
    }
    heap[parent]=temp;
    return item;
}
void display()
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d  ",heap[i].key);
    }
    printf("\n");
}