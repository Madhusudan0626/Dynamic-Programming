//Matrix chain Multiplication
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void makematrix(int *a,int *b,int n);
void display(int *a,int n);
int getminimumcost(int *a,int i,int j);

int ar[3][3];

int main()
{
    int n,i;
    int *a,*b;
    printf("Enter the Number of Matrcies\n");
    scanf("%d",&n);

    a=(int*)malloc(sizeof(int));
    if(a==NULL)
        printf("Insufficient Memory\n");
    else
    {
        b=(int*)malloc(sizeof(int));
        if(b==NULL)
            printf("Insufficient Memory\n");
        else
        {
            //makematrix(a,b,n);
            int m[]={4,5,6,9};
            display(m,n);

            int get=getminimumcost(m,1,n);
            printf("Minimum cost : %d\n",get);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    printf("%6d  ",ar[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}

void makematrix(int *a,int *b,int n)
{
    int i=0,j=0,c;

    while(n>0)
    {
        printf("Enter the dimension of the %d matrix\n",++i);
        scanf("%d%d",&a[j],&a[j+1]);
        j+=2;
        n--;
    }
    b[0]=a[0];

    for(i=1,c=1;i<=j;i++)
    {
        if(i%2!=0)
            b[c++]=a[i];
    }
}

void display(int *a,int n)
{
    int i;
    for(i=0;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int getminimumcost(int *a,int i,int j)
{
    if(i>=j)
        return 0;
    int min = INT_MAX;

    for(int k=i;k<=j-1;k++)
    {
        int temp=getminimumcost(a,i,k)+getminimumcost(a,k+1,j)+a[i-1]*a[k]*a[j];
        
        ar[i][j]=temp;

        if(temp<min)
        {
            printf("Min for %d is %d value of i is %d and j is %d\n",k,temp,i,j);
            min=temp; 
            
        }    
    }
    
    return min;
}