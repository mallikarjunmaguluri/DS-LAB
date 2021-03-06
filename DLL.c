#include<stdio.h>
#include<stdlib.h>

struct dll
{
int data;
struct dll *right,*left;
};

typedef struct dll node;

node *create(node *first)
{
int x;
node *new,*prev;
printf("enter data(enter -1 to stop)\n");
scanf("%d",&x);
while(x!=-1)
{
new=(node *)malloc(sizeof(node));
new->data=x;
new->right=new->left=NULL;
if(first==NULL)
{
first=new;
prev=new;
}
else
{
prev->right=new;
new->left=prev;
prev=new;
}
printf("enter data(enter -1 to stop)\n");
scanf("%d",&x);
}
return first;
}

void display(node *first)
{
node *temp=first;
if(first==NULL)
{
printf("no elements to print\n");
}
else
{
printf("NULL");
while(temp!=NULL)
{
printf("<-|%d|->",temp->data);
temp=temp->right;
}
printf("NULL");
}
}

int count(node *first)
{
node *temp=first;
int c=0;
if(first==NULL)
{
printf("no elements in the list to count\n");
}
else
{
while(temp!=NULL)
{
c++;
temp=temp->right;
}
}
return c;
}

void search(node *first,int x)
{
node *temp=first;
int flag=0;
if(first==NULL)
{
printf("no elements in the list to search\n");
}
else
{
while(temp!=NULL)
{
if(temp->data==x)
{
printf("the element %d found\n");
flag=1;
break;
}
else
{
temp=temp->right;
}
}
if(flag==0)
{
printf("the element %d is not found in the list\n");
}
}
}

node *insert_at_begin(node *first,int x)
{
node *temp=first;
node *new=(node *)malloc(sizeof(node));
new->data=x;
new->right=new->left=NULL;
if(first==NULL)
{
first=new;
}
else
{
new->right=temp;
first=new;
}
return first;
}

node *insert_at_end(node *first,int x)
{
node *temp=first;
node *new=(node *)malloc(sizeof(node));
new->data=x;
new->right=new->left=NULL;
if(first==NULL)
{
first=new;
}
else
{
while(temp->right!=NULL)
{
temp=temp->right;
}
temp->right=new;
}
return first;
}

node *insert_at_pos(node *first,int pos,int x)
{
node *temp=first;
int i;
node *new=(node *)malloc(sizeof(node));
new->data=x;
new->right=new->left=NULL;
int n=count(first);
if(pos>0 && pos<n)
{
for(i=1;i<pos-1;i++)
{
temp=temp->right;
}
new->right=temp->right;
new->left=temp;
temp->right=new;
//new->right->left=new;
}
return first;
}

node *delete(node *first,int x)
{
node *temp=first,*temp1;
int flag=0;
if(first==NULL)
{
printf("no element to delete\n");
}
else
{
while(temp!=NULL)
{
if(temp->data==x)
{
flag=1;
break;
}
else
{
temp=temp->right;
}
}
if(flag)
{
if(temp->right==NULL)
{
temp->left->right=NULL;
free(temp);
}
else
{
temp->left->right=temp->right;
temp->right->left=temp->left->right;
free(temp);
}
}
else
{
printf("element not found\n");
}
}
return first;
}


int main()
{
int ch,x,c,pos;
node *head=NULL;
while(1)
{
printf("1:create\n2:display\n3:count\n4:search\n5:insert_at_begin\n6:insert_at_end\n");
printf("7:insert_at_pos\n8:delete\n9:sort\n10:reverse\n");
printf("enter ur choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:head=create(head);
break;
case 2:display(head);
break;
case 3:c=count(head);
printf("the no of elements in the linked list are:%d\n",c);
break;
case 4:printf("enter the element to be search\n");
scanf("%d",&x);
search(head,x);
break;
case 5:printf("enter the element to be insert at the beginning\n");
scanf("%d",&x);
head=insert_at_begin(head,x);
break;
case 6:printf("enter the element to be insert at the ending\n");
scanf("%d",&x);
head=insert_at_end(head,x);
break;
case 7:printf("enter the position of the element to be insert\n");
scanf("%d",&pos);
printf("enter the element to be insert at the given position\n");
scanf("%d",&x);
head=insert_at_pos(head,pos,x);
break;
case 8:printf("enter the element to delete\n");
scanf("%d",&x);
head=delete(head,x);
break;
/*case 9:sort(head);
break;*/
case 11:exit(0);
default:printf("enter valid choice\n");
}
}
}
