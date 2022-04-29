//fibonacci dynamic storing the intermediate value of recursion tree
#include<stdio.h>
#include<stdlib.h>
static int count =0;
int fib(int n,int *memo);
int main()
{
    int n,i;
    int *a;
    printf("insert the position of Fibonacci Number you want to find \n");
    scanf("%d",&n);
    a=(int*)calloc(sizeof(int),n);
    printf("Initialize the memorization array as NULL(-1)\n");
    for(i=1;i<=n;i++)
        a[i]=-1;
    printf("\n");
    printf("Considering it's start with the 0 :\n");
    printf("%d\n",fib(n,a));
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("Count : %d\n",count);
    return 0;
}



int fib(int n,int *memo)
{
    int sum;
    
    if(memo[n]!=-1)
        return memo[n];
    count++;
    if(n<0)
        printf("Error\n");
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    sum=fib((n-1),memo)+fib((n-2),memo);
    memo[n]=sum;
    return sum;
}