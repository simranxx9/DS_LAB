#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *lptr;
lptr head;
void insert();
int delete();
void display_start();
void display_end();
void main()
{
    int n,i;
    head=(struct node*)malloc(sizeof(struct node));
    head->llink=head;
    head->rlink=head;
    while(1)
    {
        printf("...................ENTER................\n1:INSERT\n2:DELETE\n3:DISPLAY_START\n4:DISPLAY_END\n5:EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insert();
                break;
            case 2:printf("Deleted element is %d   ",delete());
                   printf("\n");
                   break;
            case 3:display_start();
                   break;
            case 4:display_end();
                   break;
            case 5:exit(0);
            default:printf("WRONG CHOICE\n");
        }
    }
}
void insert()
{
    int i;
       lptr temp=(lptr)malloc(sizeof(struct node));
       printf("Enter the element to be inserted:");
        scanf("%d",&i);
       temp->data=i;
       temp->llink=head;
       temp->rlink=head->rlink;
       head->rlink->llink=temp;
       head->rlink=temp;
}
int delete()
{
    int i;
    lptr temp;
    if(head->rlink==head)
        printf("NOT POSSIBlE\n");
    else
    {
        temp=head->rlink;
        i=temp->data;
        head->rlink=temp->rlink;
        head->rlink->llink=head;
        free(temp);
    }
    return i;
    
}
void display_start()
{
    lptr temp;
    if(head->rlink==head)
        printf("EMPTY LIST\n");
    else{
        temp=head->rlink;
        for(;temp->rlink!=head;temp=temp->rlink)
        {
            printf("%d  ",temp->data);
        }
        printf("%d\n",temp->data);
    }
}
void display_end()
{
    lptr temp;
            if(head->rlink==head)
                printf("List is empty\n");
        else{
        for(temp = head->llink;temp!=head;temp=temp->llink)
                printf("%d\t",temp->data);
        printf("\n");
        }
}