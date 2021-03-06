
/**SELECTION SORT**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    printf("\n\nSorted!\n");
    for(i=0;i<p;i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n\n");
}



void choice(int* ar,int p)
{
    char op[5];
  printf("\n\nEnter \"Asc\" for sorting in ascending order.\nEnter \"Desc\" for sorting in descending order\n");
  printf("------------------------------------------------------\n\n>>");
    scanf("%s",op);
    if(strcmpi(op,"Asc")==0)
    {
    sel_sort_asc(ar,p);
    }
    else if(strcmpi(op,"Desc")==0)
    {
        sel_sort_desc(ar,p);
    }
    else
    {
        printf("Invalid Input\n");
        choice(ar,p);
}
}



void sel_sort_asc(int* ar,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
        if(ar[i]>ar[j])
        {
            temp=ar[j];
            ar[j]=ar[i];
            ar[i]=temp;
        }
        }
    }
}



void sel_sort_desc(int* ar,int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
        if(ar[i]<ar[j])
        {
            temp=ar[j];
            ar[j]=ar[i];
            ar[i]=temp;
        }
        }
    }
}
