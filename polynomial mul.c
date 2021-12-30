#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coefficient;
    int exponent;
    struct node* next;
}*newnode,*temp,*head1=NULL,*head2=NULL,*head3=NULL,*temp1,*temp2,*tail;
struct node* create(struct node *head)
{
    int x;
    int coeff;
    int expo;
    do{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter coefficient of node\n");
        scanf("%d",&coeff);
        printf("enter exponent of node\n");
        scanf("%d",&expo);
        newnode->coefficient=coeff;
        newnode->exponent=expo;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        printf("1-continue,2-exit\n");
        scanf("%d",&x);
    }while(x==1);
    return(head);
}
void display(struct node *head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("+%dx^%d",temp->coefficient,temp->exponent);
        temp=temp->next;
    }
    printf("\n");
}
void polynomialmultiplication()
{
    int value=0;
    temp1=head1;
    while(temp1!=NULL)
    {
        temp2=head2;
        while(temp2!=NULL)
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coefficient=temp1->coefficient*temp2->coefficient;
            newnode->exponent=temp1->exponent+temp2->exponent;
            newnode->next=NULL;
            if(head3==NULL)
            {
                head3=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    display(head3);
}
void main()
{
    printf("enter first polynomial\n");
    head1=create(head1);
    display(head1);
    printf("enter second polynomial\n");
    head2=create(head2);
    display(head2);
    polynomialmultiplication();
}
