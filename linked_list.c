#include<stdio.h>
#include<stdlib.h>
struct list1
{
    int data;
    struct list1 *next;
};
typedef struct list1 node;
node* create(node *first)
{
    node *new,*prev;
    int x;
    printf("Enter the data value(enter -1 to stop)\n");
    scanf("%d",&x);
    while(x!=-1)
    {
        new=(node *)malloc(sizeof(node));
        new->data=x;
        new->next=NULL;
        if(first==NULL)
        {
            first=new;
        }
        else{
            prev->next=new;
        }
        prev=new;
        // printf("enter data (enter -1 to stop)\t");
        scanf("%d",&x);
    }
    return first;
}
void display(node *first)
{
    node *temp=first;
    if(first==NULL)
    {
        printf("No list to print");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("|%d|->",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}
int count(node *first)
{
    node *temp=first;
    int c=0;
    if (first==NULL)
    {
        return c;
    }
    else{
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    }
    return c;
}
void search(node *first,int ele)
{
    int flag=0;
    node * temp=first;
    while(temp!=NULL)
    {
        if(temp->data==ele)
        {
            printf("the %d element is found",ele);
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if (flag==0)
    {
        printf("the %d element is not found",ele);
    }
}
node * insertatbeg(node* first,int x)
{
    node* new=(node *)malloc(sizeof(node));
    new->data=x;
    new->next=first;
    return new;
}
node * insertatend(node* first,int x)
{
    node *new=(node *)malloc(sizeof(node)),*temp;
    temp=first;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    new->data=x;
    new->next=NULL;
    temp->next=new;
    return first;
}
node * insertatpos(node* first,int pos,int x)
{
    int n;
    node *new=(node *)malloc(sizeof(node)),*temp;
    temp=first;
    new->data=x;
    new->next=NULL;
    n=count(first);
    if(pos>0 && pos<n)
    {
        while(pos-2)
        {
            temp=temp->next;
            pos--;
        }
        new->next=temp->next;
        temp->next=new;
    }
    else
    {
        printf("ther is not possible to insert the element at that position");
    }

    return first;
}
node *delete(node *first,int x)
{
    node *temp,*temp1;
    temp=first;
    int flag=0;
    if(first->data==x)
    {
        first=first->next;
        free(temp);
    }
    else
    {
        temp1=first;
        temp=temp->next;
        if(flag==1)
        {
            temp1->next=temp->next;
            free(temp);
        }
        else
        {
            printf("element %d is not found",x);
        }
    }
    return first;
}
void sort(node *first)
{
    node *temp1,*temp2,*new;
    new=(node*)malloc(sizeof(node));
    new->data=0;
    new->next=NULL;
    for(temp1=first;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=first;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->data > temp2->data)
            {
                new->data = temp1->data;
                temp1->data = temp2->data;
                temp2->data=new->data;
            }
        }
    }
}
node *reverse(node*first)
{
    node *prev=NULL,*present=first,*save;
    while(present!=NULL)
    {
        save=present->next;
        present->next=prev;
        prev=present;
        present=save;
    }
    return prev;
}
void main()
{
    int x,ch;
    int pos,c;
    node *head=NULL;
    while(1)
    {
        printf("\nenter your choice");
        printf("\n1.create\n2.display \n3.count \n4.search\n5.insert at beginning \n");
        printf("6.insertion at ending\n7.insertion at given position\n8.delete\n9.sort\n10.reverse\n11.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=create(head);
                    break;
            case 2: display(head);
                    break;
            case 3: c=count(head);
                    printf("there is %d elements present in the singly linked list",c);
                    break;
            case 4: printf("enter a value to search\n");
                    scanf("%d",&x);
                    search(head,x);
                    break;
            case 5: printf("enter a value to insertatbeg\n");
                    scanf("%d",&x);
                    head=insertatbeg(head,x);
                    break;
            case 6: printf("enter a value to insertatend\n");
                    scanf("%d",&x);
                    head=insertatend(head,x);
                    break;
            case 7: printf("enter the element and the position \n");
                    scanf("%d%d",&pos,&x);
                    head=insertatpos(head,pos,x);
                    break;
            case 8: printf("enter thre element to be deleted\n");
                    scanf("%d",&x);
                    head=delete(head,x);
                    break;
            case 9: sort(head);
                    break;
            case 10:head=reverse(head);
                    break;
            case 11:exit(0);
                    break;
            default:printf("please check your given choice");
                    break;
        }
    }
}