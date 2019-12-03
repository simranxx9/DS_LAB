#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *treeptr;
treeptr root=NULL;
void insert(treeptr *root,int key);
int search(treeptr root,int key);
void display(treeptr root);
void main()
{
    int k,n;
    while(1)
    {
        printf("....................ENTER.....................\n1:INSERT\n2:SEARCH\n3:DISPLAY_INORDER\n4:EXIT\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("Enter the element to be inserted\n");
                   scanf("%d",&k);
                   insert(&root,k);
                   break;
            case 2:printf("Enter key to be searched\n");
                   scanf("%d",&k);
                   if(search(root,k))
                   printf("Element found\n");
                   else
                   {
                       printf("NOT found\n");
                   }
                   break;
            case 3:display(root);
                   break;
            case 4:exit(0);
            default:printf("WRONG CHOICE\n");
        }
    }
}
void insert(treeptr *root,int key)
{
    if((*root)==NULL)
    {
        (*root)=(treeptr)malloc(sizeof(struct node));
        (*root)->data=key;
        (*root)->llink=NULL;
        (*root)->rlink=NULL;
    }
    else if((*root)->data>key)
        insert(&(*root)->llink,key);
    else
    {
        insert(&(*root)->rlink,key);
    }
    
}
int search(treeptr root,int k)
{
    if(root==NULL)
        return 0;
    else if(root->data==k)
        return 1;
    else if(root->data>k)
        return search(root->llink,k);
    else
    {
        return search(root->rlink,k);
    }
    
}
void display(treeptr root)
{
    if(root)
    {
        display(root->llink);
        printf("%d  ",root->data);
        display(root->rlink);
    }
    
}