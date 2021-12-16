#include <stdio.h>
#include<stdlib.h>
void main()
{
    int i,a;
    struct node
    {
        int data;
        struct node*next;
    }*newnode,*temp;
    struct node* head=NULL;
    struct node* tail=NULL;
    void create()
    {
        int c;
        int value;
        do{
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter value of a node\n");
            scanf("%d",&value);
            newnode->data=value;
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
            scanf("%d",&c);
        }while(c==1);
    }
    
    void display()
    {
        temp=head;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    void insert_beg()
    {
        int value;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value");
        scanf("%d",&value);
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }
    void insert_end()
    {
        int value;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value");
        scanf("%d",&value);
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
    void specific_insert()
    {
        int pos,value;
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter value");
        scanf("%d",&value);
        printf("enter position");
        scanf("%d",&pos);
        for(i=0; i<pos-1; i++)
        {
            temp=temp->next;
        }
        newnode->data=value;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    void delete_beg()
    {
        temp=head;
        head=head->next;
        temp->next=NULL;
    }
    void delete_end()
    {
        temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
    }
    void delete_pos()
    {
        temp=head;
        int pos,i;
        printf("enter position");
        scanf("%d",&pos);
        for(i=0; i<pos-1; i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    create();
    printf("enter your choice 1:insertion at begining\n 2:insertion at ending\n 3:insertion at specific position\n 4:deletion at begining\n 5:deletion at ending\n 6:deletion at specific position\n");
    printf("7:display\n ");
    scanf("%d",&a);
    switch(a)
    {
        case 1: insert_beg();
                display();
                break;
        case 2: insert_end();
                display();
                break;
        case 3: specific_insert();
                display();
                break;
        case 4: delete_beg();
                display();
                break;
        case 5: delete_end();
                display();
                break;
        case 6: delete_pos();
                display();
                break;
        case 7: display();
                break;
        default: printf("enter the correct choice\n");
    }    
}
