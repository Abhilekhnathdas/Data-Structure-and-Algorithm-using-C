#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memorylimit 5
typedef struct queue
{
	int* ar;
	int front;
	int rear;
}queue;
void enq(queue*,int);
int deq(queue*);
int main()
{
	int num;
	char op[5];
	queue* q=(queue*)malloc(1*sizeof(queue));
	q->ar=(int*)malloc(10*sizeof(int));
	q->front=-1;
	q->rear=-1;
	printf("\"push\" to insert \n\"pop\" to remove \n\"Exit\" to terminate\n----------------------------------------------------------------------------------\n\n\n");
    while(1)
	     {
	     printf("\n\n>>Enter the name of operation\n");
		 scanf("%s",op);
		 if(strcmpi(op,"push")==0)
		    {
		    	printf(">>Enter the number\n");
		    	scanf("%d",&num);
		    	enq(q,num);
		    	printf(">>Inserted..\n");
				}
		 else if(strcmpi(op,"pop")==0)
		       {
		       	num=deq(q);
		       	if(num==-9999999)
                    continue;
                else
		       	printf("\n>>Removed data is :%d\n",num);
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


void enq(queue* q,int num)
{
if(q->rear==memorylimit)
     {
     	printf("\a>>queue memory full\n");
		 }
else if(q->front==-1 && q->rear==-1)
    {
    	q->front=0;
    	q->rear=0;
    	q->ar[q->rear]=num;
	}
else
    {
        q->rear=q->rear+1;
        q->ar[q->rear]=num;
    }
}


int deq(queue* q)
{
    int val;
	if(q->front==-1 || q->front>q->rear)
	{
		printf("\a>>No data available right now\n");
		return -9999999;
	}
	else
	{
	    val=q->ar[q->front];
	    q->front=q->front+1;
		return val;
	}
}
