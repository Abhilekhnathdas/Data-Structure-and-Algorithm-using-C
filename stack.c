#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memorylimit 5
typedef struct stack
{
	int* ar;
	int loc;
}stack;
void push(stack*,int);
int pop(stack*);
int peek(stack*);
int main()
{
	int num;
	char op[5];
	stack* stk=(stack*)malloc(1*sizeof(stack));
	stk->ar=(int*)malloc(10*sizeof(int));
	stk->loc=-1;
	printf("\"push\" to insert \n\"pop\" to remove \n\"peek\" to see the last element \n\"Exit\" to terminate\n----------------------------------------------------------------------------------\n\n\n");
    while(1)
	     {
	     printf("\n\n>>Enter the name of operation\n");
		 scanf("%s",op);
		 if(strcmpi(op,"push")==0)
		    {
		    	printf(">>Enter the number\n");
		    	scanf("%d",&num);
		    	push(stk,num);
		    	printf(">>Inserted..\n");
				}
		 else if(strcmpi(op,"pop")==0)
		       {
		       	num=pop(stk);
		       	if(num==-9999999)
                    continue;
                else
		       	printf("\n>>Removed data is :%d\n",num);
			   }
		 else if(strcmpi(op,"peek")==0)
		       {
		       	num=peek(stk);
		       	printf("\n>>Peeked data is :%d\n",num);
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


void push(stack* stk,int num)
{
if(stk->loc==memorylimit)
     {
     	printf("\a>>Stack memory full\n");
		 }
else
    {
    	stk->loc=stk->loc+1;
    	stk->ar[stk->loc]=num;
	}
}


int pop(stack* stk)
{
    int val;
	if(stk->loc==-1)
	{
		printf("\a>>No data available right now\n");
		return -9999999;
	}
	else
	{
	    val=stk->ar[stk->loc];
	    stk->loc=stk->loc-1;
		return val;
	}
}

int peek(stack* stk)
{
	if(stk->loc==-1)
	{
		printf("\a>>No data available right now\n");
	}
	else
	{
		return stk->ar[stk->loc];
	}
}
