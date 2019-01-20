/**Heap SORT**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void heapify(int* ar,int n,int op);
void show(int* ar,int p);
void insert(int* ar,int* n,int val);
int max_rem(int* ar,int* n);
void in_heapify(int* ar,int child);

int main()
{
int* ar=(int*)malloc(10000*sizeof(int));
char num[10];
int m,p=0,sum,i;    /**p=pointer of last element in the array; m=multiplicative factor to each digit to get number from string; sum=number got after combining digits;j=for looping**/

printf("Enter numbers continuously.\nWrite \"done\" after inserting last number,to proceed further\n");
printf("--------------------------------------------------------------------------\n>>");

/** below input number are taken in the form of string and then integer number is calculated
by subtracting 48 from each character of string and further multiplying it with multiples of
10 according to its corresponding place and meanwhile they are added to be stored as a number
in variable named "sum"**/

while(1)
    {
    scanf("%s",num);
    if(strcmpi(num,"done")==0)
    {
        break;
    }
    else
        {
        m=1;
        sum=0;
    for(i=strlen(num)-1;i>=0;i--)
    {
        sum=sum+((num[i]-48)*m);
        m=m*10;
    }
    ar[p]=sum;
    p=p+1;
    }
    }
    choice(ar,p);
    printf("\n\n");
}


void show(int* ar,int p)
{
    int i;
    for(i=0;i<p;i++)
    {
        printf("%d ",ar[i]);
    }
}

/** Menu driven console **/

void choice(int* ar,int p)
{
    char op[5];
    int el;
  printf("\n\nEnter \"Max\" for Max-Heap.\nEnter \"Min\" for Min-Heap\nEnter \"Ins\" to insert a new element in heap.\nEnter \"del\" to remove max element of heap\n");
  printf("------------------------------------------------------\n\n>>");
    scanf("%s",op);
    if(strcmpi(op,"Max")==0)
    {
    heapify(ar,p,1);
      show(ar,p);
      printf("p is %d",p);
    }
    else if(strcmpi(op,"Min")==0)
    {
        heapify(ar,p,0);
          show(ar,p);
    }
    else if(strcmpi(op,"Ins")==0)
    {
        printf("Enter the new element\n>>");
        scanf("%d",&el);
        insert(ar,&p,el);
        printf(">>Successfully Inserted\n\n>>Modified Heap is:\n");
        show(ar,p);
        printf("p is %d",p);
    }
    else if(strcmpi(op,"del")==0)
    {
        el=max_rem(ar,&p);
        printf(">>Max Element is:     %d\n\n>>Modified Heap is:\n",el);
        show(ar,p);
        printf("p is %d",p);
    }
    else
    {
        printf("Invalid Input\n");
        choice(ar,p);
}
choice(ar,p);
}


/** reposition element according to heap property**/

void heapify(int* ar,int n,int op)
{
    int parent,i,child,temp;
    if(op==1)
    {

/**   max heap   **/


for(i=1;i<n;i++)
{
child=i;
while(child>0)
{
if(child%2==0)
{
parent=(child/2)-1;
}
else
{
parent=child/2;
}
if(ar[child]>ar[parent])
{
temp=ar[child];
ar[child]=ar[parent];
ar[parent]=temp;
child=parent;
}
else{
     break;
}
}
}
    }

/**min heap**/


    else{

for(i=1;i<n;i++)
{
child=i;
while(child>0)
{
if(child%2==0)
{
parent=(child/2)-1;
}
else
{
parent=child/2;
}
if(ar[child]<ar[parent])
{
temp=ar[child];
ar[child]=ar[parent];
ar[parent]=temp;
child=parent;
}
else{
     break;
}
}
}
    }
}


/** insert element in the heap **/

void insert(int* ar,int* n,int val)
{
    ar[*n]=val;
    int child=*n;
    in_heapify(ar,*n);
    *n=*n+1;
}


/**This is to move element at wrong position from down to up**/

void up_heapify(int* ar,int child)
{
    int parent,temp;
   while(child>0)
{
if(child%2==0)
{
parent=(child/2)-1;
}
else
{
parent=child/2;
}
if(ar[child]>ar[parent])
{
temp=ar[child];
ar[child]=ar[parent];
ar[parent]=temp;
child=parent;
}
else{
     break;
}
}
}

/** remove maximum element from heap **/

int max_rem(int* ar,int* n)
{
    int temp;
    temp=ar[0];
    ar[0]=ar[(*n)-1];
    printf("*n is %d",*n);
    *n=*n-1;
    printf("*n is %d",*n);
    down_heapify(ar,0,*n);
    return temp;
}


/** This is to move the element at the wrong position from top to bottom**/

void down_heapify(int* ar ,int parent,int n)
{
    int child,child1,child2,temp;
    while(parent<n)
    {
  child1=parent*2+1;
  child2=parent*2+2;
  if(ar[child1] >= ar[child2])
    child=child1;
  else
    child=child2;
  if(ar[parent]<ar[child])
  {
      temp=ar[parent];
      ar[parent]=ar[child];
      ar[child]=temp;
      parent=child;
  }
  else
  {
      break;
  }
    }
}




