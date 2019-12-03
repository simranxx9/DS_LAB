#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (x>y)?1:(x<y)?-1:0
struct node {
    int coef;
    int expo;
    struct node *link;
};
typedef struct node *polyptr;
polyptr heada,headb;
polyptr poly_add(polyptr a,polyptr b);
void attach(int sum,int exp,polyptr *lc);
void main()
{
    int d,n=0,e,i=0,j=0,g,h;
    heada=(struct node*)malloc(sizeof(struct node));
    headb=(struct node*)malloc(sizeof(struct node));
    heada->expo=-1;
    headb->expo=-1;
    polyptr a=heada;
    polyptr b=headb;
    printf("Enter the number of terms of 1st polynomial\n");
    scanf("%d",&n);
    for(e=0;e<n;e++)
    {
        printf("Enter the coef and expo of %d term\n",(i+1));
        scanf("%d%d",&g,&h);
        attach(g,h,&a);
        i++;
    }
    printf("Enter the number of terms of 2nd polynomial\n");
    scanf("%d",&d);
    for(e=0;e<d;e++)
    {
        printf("Enter the coef and expo of %d term\n",(j+1));
        scanf("%d%d",&g,&h);
        attach(g,h,&b);
        j++;
    }
    a->link=heada;
    b->link=headb;
    polyptr c=poly_add(heada,headb);
    polyptr temp=c;
    c=c->link;
    for(;c->link!=temp;c=c->link)
    {
        printf("%d*x^%d+",c->coef,c->expo);
    }
    printf("%d*x^%d\n",c->coef,c->expo);
}
polyptr poly_add(polyptr a,polyptr b)
{
    polyptr sa,c,lc;
    c=(polyptr)malloc(sizeof(struct node));
    c->expo=-1;
    sa=a;
    a=a->link;
    b=b->link;
    lc=c;
    int stop=0,sum=0;
    do{
        switch(COMPARE(a->expo,b->expo))
        {
            case 1:attach(a->coef,a->expo,&lc);
                   a=a->link;
                   break;
            case -1:attach(b->coef,b->expo,&lc);
                    b=b->link;
                    break;
            case 0:if(sa==a)
                        stop=1;
                   else{
                       sum=a->coef+b->coef;
                       if(sum)
                       {
                           attach(sum,a->expo,&lc);
                       }
                        a=a->link;
                        b=b->link;                                    
                   }  
        }
      }while(!stop);
      lc->link=c;
      return c;
}
void attach(int sum,int exp,polyptr *lc)
{
    polyptr temp=(polyptr)malloc(sizeof(struct node));
    temp->coef=sum;
    temp->expo=exp;
    temp->link=NULL;
    (*lc)->link=temp;
    (*lc)=temp;
}