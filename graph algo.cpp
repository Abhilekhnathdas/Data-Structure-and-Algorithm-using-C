#include<iostream>
#include<cstdlib>
typedef struct vertex{
	int v;
	struct vertex* next;
}vertex;
void takerel(vertex** al);
void traversal(vertex** al,int n);
int bfs(vertex** al,int v2);
void enq(int val);
int deq();
void show();
int* q=(int*)malloc(100*sizeof(int));
int rear=-1;
int front=-1;
int* d=(int*)malloc(100*sizeof(int));
int main()
{
	int n,i,v1,v2,z;
	vertex* ve;
	printf("Enter total number of vertex\n");
	scanf("%d",&n);
	vertex* al[n];
	for(i=0;i<n;i++)
	{
	ve=(vertex*)malloc(sizeof(vertex));
	ve->v=i+1;
	ve->next=NULL;
		al[i]=ve;
	}
		/***/
	takerel(al);
	traversal(al,n);
	printf("Enter v1 and v2 to check whether they are realted or not\n");
	scanf("%d %d",&v1,&v2);
	enq(v1);
	for(i=0;i<n;i++)
		{
		d[i]=0;
		}
	d[v1-1]=1;
	z=bfs(al,v2);
	if(z==1)
	printf("Found\n");
	else
	printf("Not Found");
	
}
	void takerel(vertex** al)
	{
	
		int c,v1,v2;
		vertex* ve;
		vertex* sublist;
	/**	for(c=0;c<5;c++)
		{
			printf("                   %d ",al[c]);
		}**/
		printf("Enter total number of relation\n");
		scanf("%d",&c);
		printf("Enter the edge vertices v1 and v2\n");
	while(c>0)
		{
			scanf("%d %d",&v1,&v2);
			ve=(vertex*)malloc(sizeof(vertex));
			ve->v=v2;
			ve->next=NULL;
			sublist=al[v1-1];
			/**printf("%d",sublist);**/
			while(sublist->next!=NULL)
			{
				sublist=sublist->next;
			}
			sublist->next=ve;
			c--;
		}
		printf("done");
	}
	void traversal(vertex** al,int n)
	{
		vertex* top;
		int i;
		for(i=0;i<n;i++)
		{
			top=al[i];
			while(top!=NULL)
			{
				printf("%d ",top->v);
				top=top->next;
			}
			printf("\n");
		}
	}
	int bfs(vertex** al,int v2)
	{
	int y=deq();
	printf("poped %d\n",y);
	if(y==v2)
	{
	return 1;
	}
	else if(y==-1)
	{
		return 0;
	}
	else
	{
	vertex* x=al[y-1]->next;	
		while(x!=NULL)
		{
			if(d[(x->v)-1]!=1)
			enq(x->v);
			d[(x->v)-1]=1;
			x=x->next;
			show();
		}
		return bfs(al,v2);
	}
}
	void enq(int val)
	{
		if(rear==-1 && front==-1)
		{
			rear=rear+1;
			front=front+1;
			q[rear]=val;
			rear++;
		}
		else
		{
			q[rear]=val;
			rear++;
		}
	}
	int deq()
	{
		if(rear==-1 && front==-1)
		{
			return -1;
		}
		else if(front<rear)
		{
		int l=q[front];
		front++;
		return l;
		}
		else
		{
			return -1;
		}
	}
	void show()
	{
		int i;
		for(i=0;i<5;i++)
		{
			printf("%d",d[i]);
		}
		printf("\n");
		for(i=front;i<rear;i++)
		printf("%d",q[i]);
		printf("\n");
	}
	
	
	
	
	
	
