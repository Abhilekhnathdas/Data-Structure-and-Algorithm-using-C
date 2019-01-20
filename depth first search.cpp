#include<iostream>
#include<cstdlib>
typedef struct vertex{
	int v;
	struct vertex* next;
}vertex;
void takerel(vertex** al);
void traversal(vertex** al,int n);
int dfs(vertex** al,int v1,int v2);
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
	for(i=0;i<n;i++)
		{
		d[i]=0;
		}
	z=dfs(al,v1,v2);
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
	int dfs(vertex** al,int v1,int v2)
	{
		int k=0;
		if(v1==v2)
		{
		return 1;
	}
		else
		{
		vertex* top=al[v1-1]->next;
		d[v1-1]=1;
     while(top!=NULL)
	 {
	 	if(d[(top->v)-1]==0)
	 	{
	 	k= dfs(al,top->v,v2);
	 	top=top->next;
	 }
	 	else
	 	{
	 	top=top->next;
	 	continue;
		 }
	}
}
return k;
	}
	
	
