#include<stdio.h>
#include<stdlib.h>

int a;

struct node
{
int key;
int data;
struct node* next;
struct node* mainnext;
}*newnode,*head=NULL,*tail,*temp;

void create()
{
int i,x,value,hash_val;
for(i=0;i<=a;i++)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=0;
newnode->next=NULL;
newnode->mainnext=NULL;
newnode->key=i;
if(head==NULL)
{
head=newnode;
tail=newnode;
}
else
{
tail->mainnext=newnode;
tail=newnode;
}
}
do
{
printf("Enter number :");
scanf("%d",&value);
hash_val=value%a;
temp=head;
while(temp->key < hash_val)
temp=temp->mainnext;
if(temp->data==0)
{
temp->data=value;
}
else
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->next=NULL;
newnode->mainnext=NULL;
if(temp->next==NULL)
{
temp->next=newnode;
}
else
{
while(temp->next!=NULL)
temp=temp->next;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=value;
newnode->mainnext=NULL;
newnode->next=NULL;
temp->next=newnode;
}
}
printf("Enter 1 to continue, 2 to exit :");
scanf("%d",&x);
}while(x==1);
}

void search()
{
int num,k,pos=0;
printf("Enter number to be searched :");
scanf("%d",&num);
k=num%a;
temp=head;
while(temp->key < k)
temp=temp->mainnext;
if(temp->data==num)
{
printf("Given number is in main chain of key %d position 0\n",k);
}
else if(temp->next!=NULL)
{
while(temp->next!=NULL)
{
pos = pos+1;
if(temp->next->data==num)
{
printf("Given number is in main chain of position %d, sub chain position %d\n",k,pos);
}
temp=temp->next;
}
}
else
{
printf("Given number is not in given data\n");
}
}

void delete()
{
int number,ke;
printf("Enter number to be deleted :");
scanf("%d",&number);
ke=number%a;
temp=head;
while(temp->key < ke)
temp=temp->mainnext;
if(temp->data==number)
{
temp->data=0;
}
else if(temp->next!=NULL)
{
while(temp->next!=NULL)
{
if(temp->next->data==number)
{
temp->next=temp->next->next;
}
temp=temp->next;
}
}
else
{
printf("Given number is not in given data\n");
}
}

void display()
{
temp=head;
struct node *temp1;
while(temp->key < a)
{
printf("%d\n",temp->data);
temp1=temp;
while(temp1->next!=NULL)
{
temp1=temp1->next;
printf("%d\n",temp1->data);
}
temp=temp->mainnext;
}
}

int main()
{
printf("Enter table size :");
scanf("%d",&a);
create();
search();
delete();
display();
}
//50, 700, 76, 85, 92, 73, 101.



