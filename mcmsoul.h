/********************************************************************************************************
 ********************************************************************************************************
 Name - Madhusdan chand
 Prog - Write a C program to implement parenthesization problem. (Matrix chain multiplication)
 Date - 15/06/2022
 ********************************************************************************************************
*********************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int ar[20][20]={0};
int br[20][20]={0};

void makematrix(int *a,int *b,int n);
int getminimumcost(int *a,int i,int j);
void displaypro(int n);


void displaypro(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ar[i][j]!=0)
                printf("%6d  ",ar[i][j]);
        }
        printf("\n");
    }
}

void displaymax(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(br[i][j]!=0)
                printf("%6d  ",br[i][j]);
        }
        printf("\n");
    }
}


void makematrix(int *a,int *b,int n)
{
    int i=0,j=0,c;

    while(2*n>0)
    {
        printf("Enter the dimension of the %d matrix\n",++i);
        scanf("%d%d",&a[j],&a[j+1]);
        j++;
        n--;
    }
    b[0]=a[0];

    for(i=1,c=1;i<=j;i++)
    {
        //printf("%d\n",a[i]);
        b[c++]=a[i];
    }
}

int getminimumcost(int *a,int i,int j)
{
    if(ar[i][j]!=0)
        return ar[i][j];
    if(i>=j)
        return 0;
    int min = INT_MAX;

    for(int k=i;k<=j-1;k++)
    {
        int temp=getminimumcost(a,i,k)+getminimumcost(a,k+1,j)+a[i-1]*a[k]*a[j];
        
        
        

        if(temp<min)
        {
            
            br[i][j]=k;
            printf("Vlaue of K is %d\n",k);
            min=temp; 
            ar[i][j]=min;
            printf("Cost from A%d x A%d is : %d\n",i,j,min);
            
        }    
    }
    
    return min;
}