
/**MERGE SORT**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mergesort(int* ar,int lower,int upper);
void merge(int* ar,int lower,int upper,int mid);

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
    mergesort(ar,0,p-1);
    printf("\n\nSorted!\n");
    for(i=0;i<p;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n\n");
}

void mergesort(int* ar,int lower,int upper)
{
    int midpoint;
    if(lower<upper)
    {
    midpoint=(lower+upper)/2;
    mergesort(ar,lower,midpoint);
    mergesort(ar,midpoint+1,upper);
    merge(ar,lower,upper,midpoint);
}
}

void merge(int* ar,int lower,int upper,int mid)
{
    int i,c;
int size1=mid-lower+1;
int size2=upper-mid;
int ar1[size1];
int ar2[size2];
int p=lower,q=mid+1;
printf("%d %d %d\n",lower,mid,upper);
for(i=0;i<size1;i++)
     {
     ar1[i]=ar[p];
     p++;
     }
for(i=0;i<size2;i++)
     {
     ar2[i]=ar[q];
     q++;
     }
c=lower;
p=0;q=0;
while(p<size1 && q<size2)
{
if(ar1[p]<=ar2[q])
{
ar[c]=ar1[p];
p++;
}
else
{
ar[c]=ar2[q];
q++;
}
c++;
}
while(p<size1)
{
ar[c]=ar1[p];
p++;
c++;
}
while(q<size2)
{
ar[c]=ar2[q];
q++;
c++;
}
/**for(i=lower;i<=upper;i++)
     {
         printf("%d ",ar[i]);
     }
      printf("\n");**/
}





