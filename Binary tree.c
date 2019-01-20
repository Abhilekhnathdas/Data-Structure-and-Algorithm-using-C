#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memorylimit 5
typedef struct Tree_Node
{
    struct Tree_Node* left;
	int val;
	struct Tree_Node* right;
}node;
node* insert(node* top,int num);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int binsearch(node*,int);
void rem(node** top,int num);
int main()
{
	int num;
	char op[5];
	node* first;
	first=NULL;
	printf("\n  Type:\n\n");
	printf("\"Add\" to insert\n\"Del\" to delete any element\n\"Walk\" to see all elements of Binary Tree\n\"Find\" to Search any number\n\"Exit\" to terminate\n----------------------------------------------------------------------------------\n\n");
    while(1)
	     {
	     printf("\n\n>>Enter the name of operation\n");
		 scanf("%s",op);
		 if(strcmpi(op,"add")==0)
		    {
		    	printf(">>Enter the number\n");
		    	scanf("%d",&num);
		    	first=insert(first,num);
		    	printf(">>Inserted..\n%d");
				}
		 else if(strcmpi(op,"del")==0)
		       {
                printf(">>Enter the element want to remove\n");
		    	scanf("%d",&num);
                rem(&first,num);
		       	printf("\n>>Removed!\n");
		       }
		 else if(strcmpi(op,"walk")==0)
		       {
		       	inorder(first);
		       	printf("\n");
                preorder(first);
                printf("\n");
		       	postorder(first);
		       	printf("\n");
			   }
         else if(strcmpi(op,"find")==0)
         {
             printf("Enter number you are searching for\n");
             scanf("%d",&num);
             int result=binsearch(first,num);
             if(result==1)
                printf("Found!\n");
             else
                printf("Sorry! not present\n");
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
node* insert(node* top,int num)
{
node* cpy=top;
node* newnode=(node*)malloc(1*sizeof(node));
                newnode->val=num;
                newnode->left=NULL;
                newnode->right=NULL;
if(top==NULL)
{
top=newnode;
return top;
}
else if(num>top->val && top->right==NULL)
{
top->right=newnode;
}
else if(num<top->val && top->left==NULL)
{
top->left=newnode;
}
else if(num>top->val && top->right!=NULL)
{
insert(top->right,num);
}
else
{
insert(top->left,num);
}
return cpy;
}

void inorder(node* top)
{
if(top!=NULL)
{
inorder(top->left);
printf("%d ",top->val);
inorder(top->right);
}
}


void preorder(node* top)
{
if(top!=NULL)
{
printf("%d ",top->val);
preorder(top->left);
preorder(top->right);
}
}



void postorder(node* top)
{
     if(top!=NULL)
           {
             postorder(top->left);
             postorder(top->right);
             printf("%d ",top->val);
           }
}


int binsearch(node* top,int num)
{
    int result=0;
    if(top!=NULL)
    {
if(top->val==num)
{
    return 1;
}
else
{
    if(num>top->val)
    {
        result=binsearch(top->right,num);
    }
    else
    {
       result= binsearch(top->left,num);
    }
}
    }
return result;
}



void rem(node** top,int num)
{
    node* move;
if(*top!=NULL)
{
    if((*top)->val==num)
    {
        if((*top)->left!=NULL && (*top)->right!=NULL)
        {
            move=(*top)->right;
             while(move->left!=NULL)
             {
                 move=move->left;
             }
             move->left=(*top)->left;
             (*top)=(*top)->right;
        }
        else if((*top)->left!=NULL && (*top)->right==NULL)
        {
            (*top)=(*top)->left;
        }
        else if((*top)->left==NULL && (*top)->right!=NULL)
        {
           (*top)=(*top)->right;
        }
        else
        {
            (*top)=NULL;
        }
    }
    else if((*top)->left->val==num || (*top)->right->val==num)
    {
        printf("chalo");
    if((*top)->left->val==num)
    {
         if((*top)->left->left!=NULL && (*top)->left->right==NULL)
        {
        (*top)->left=(*top)->left->left;
        }
        else if((*top)->left->right!=NULL && (*top)->left->left==NULL)
         {
          (*top)->left=(*top)->left->right;
         }
         else if((*top)->left->right!=NULL && (*top)->left->left!=NULL)
         {
             move=(*top)->left->right;
             while(move->left!=NULL)
             {
                 move=move->left;
             }
             move->left=(*top)->left->left;
             (*top)->left=(*top)->left->right;
         }
         else
         {
             (*top)->left=NULL;
         }
    }
    else
    {
         if((*top)->right->left!=NULL && (*top)->right->right==NULL)
        {
        (*top)->right=(*top)->right->left;
        }
        else if((*top)->right->right!=NULL && (*top)->right->left==NULL)
         {
             printf("chalo2");
          (*top)->right=(*top)->right->right;
         }
         else if((*top)->right->right!=NULL && (*top)->right->left!=NULL)
         {
             move=(*top)->right->right;
             while(move->left!=NULL)
             {
                 move=move->left;
             }
             move->left=(*top)->right->left;
             (*top)->right=(*top)->right->right;
         }
         else
         {
             (*top)->right=NULL;
         }
    }

    }
    else
    {
        if((*top)->val<num)
        {
            rem(&((*top)->right),num);
        }
        else
            {
           rem(&((*top)->left),num);
            }
    }
}
}
