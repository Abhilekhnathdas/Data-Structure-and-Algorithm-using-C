#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memorylimit 5
typedef struct Linked_List_Node
{
	int val;
	struct Linked_List_Node* next;
}node;
void insert(node**,int);
int rem(node**);
void traverse(node*);
int main()
{
	int num;
	char op[5];
	node* first;
	first=NULL;
	printf("\n  Type:\n\n");
	printf("\"Push\" to insert \n\"Pop\" to remove \n\"Walk\" to see all elements of Linked List \n\"Exit\" to terminate\n----------------------------------------------------------------------------------\n\n");
    while(1)
	     {
	     printf("\n\n>>Enter the name of operation\n");
		 scanf("%s",op);
		 if(strcmpi(op,"push")==0)
		    {
		    	printf(">>Enter the number\n");
		    	scanf("%d",&num);
		    	insert(&first,num);
		    	printf(">>Inserted..\n%d",first->val);
				}
		 else if(strcmpi(op,"pop")==0)
		       {
		       	num=rem(&first);
		       	if(num==-9999999)
                {
                    printf(">>No data is avaliable\n");
                    continue;
                }
                else
                {
		       	printf("\n>>Removed data is :%d\n",num);
			   }
		       }
		 else if(strcmpi(op,"walk")==0)
		       {
		       	traverse(first);
			   }
		 else if(strcmpi(op,"exit")==0)
		       {
		       	break;
			   }
		 else
		     {
		 	printf(">>Invalid option! Try again\n");
		      }
			 }
			 return 0;
}
void insert(node** top,int num)
{
if(*top==NULL)
{
node* newnode=(node*)malloc(1*sizeof(node));
newnode->val=num;
newnode->next=NULL;
*top=newnode;
}
else if((*top)->next==NULL)
{
node* newnode=(node*)malloc(1*sizeof(node));
newnode->val=num;
newnode->next=NULL;
(*top)->next=newnode;
}
else
{
insert(&((*top)->next),num);
}
}



int rem(node** top)
{
int value;
if(*top==NULL)
{
return -9999999;
}
else if((*top)->next==NULL)
{
value=(*top)->val;
(*top)=NULL;
return value;
}
else if((*top)->next->next==NULL)
{
value=(*top)->next->val;
(*top)->next=NULL;
return value;
}
else
{
rem(&((*top)->next));
}
}


void traverse(node* top)
{
while(top!=NULL)
{
printf("%d ",top->val);
top=top->next;
}
}









