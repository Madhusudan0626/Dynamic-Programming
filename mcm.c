/********************************************************************************************************
 ********************************************************************************************************
 Name - Madhusdan chand
 Prog - Write a C program to implement parenthesization problem. (Matrix chain multiplication)
 Date - 15/06/2022
 ********************************************************************************************************
*********************************************************************************************************/
#include "mcmsoul.h"

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
            makematrix(a,b,n);
            int get=getminimumcost(b,1,n);
            printf("Minimum cost : %d\n",get);
            
            printf("\nCost Matrix\n");
            displaypro(n);
            printf("Parenthesized Matrix\n");
            displaymax(n);
        }
    }
    return 0;
}
/*
Enter the Number of Matrcies
6
Enter the dimension of the 1 matrix
30 35
Enter the dimension of the 2 matrix
35 15
Enter the dimension of the 3 matrix
15 5
Enter the dimension of the 4 matrix
5 10
Enter the dimension of the 5 matrix
10 20
Enter the dimension of the 6 matrix
20 25
Vlaue of K is 5
Cost from A5 x A6 is : 5000
Vlaue of K is 4
Cost from A4 x A6 is : 6250
Vlaue of K is 4
Cost from A4 x A5 is : 1000
Vlaue of K is 5
Cost from A4 x A6 is : 3500
Vlaue of K is 3
Cost from A3 x A6 is : 5375
Vlaue of K is 3
Cost from A3 x A4 is : 750
Vlaue of K is 3
Cost from A3 x A5 is : 2500
Vlaue of K is 2
Cost from A2 x A6 is : 18500
Vlaue of K is 2
Cost from A2 x A3 is : 2625
Vlaue of K is 3
Cost from A2 x A6 is : 10500
Vlaue of K is 2
Cost from A2 x A4 is : 6000
Vlaue of K is 3
Cost from A2 x A4 is : 4375
Vlaue of K is 2
Cost from A2 x A5 is : 13000
Vlaue of K is 3
Cost from A2 x A5 is : 7125
Vlaue of K is 1
Cost from A1 x A6 is : 36750
Vlaue of K is 1
Cost from A1 x A2 is : 15750
Vlaue of K is 2
Cost from A1 x A6 is : 32375
Vlaue of K is 1
Cost from A1 x A3 is : 7875
Vlaue of K is 3
Cost from A1 x A6 is : 15125
Vlaue of K is 1
Cost from A1 x A4 is : 14875
Vlaue of K is 3
Cost from A1 x A4 is : 9375
Vlaue of K is 1
Cost from A1 x A5 is : 28125
Vlaue of K is 2
Cost from A1 x A5 is : 27250
Vlaue of K is 3
Cost from A1 x A5 is : 11875
Minimum cost : 15125

Cost Matrix
 15750    7875    9375   11875   15125  
  2625    4375    7125   10500  
   750    2500    5375  
  1000    3500  
  5000  

Parenthesized Matrix
     1       1       3       3       3  
     2       3       3       3  
     3       3       3  
     4       5  
     5  
  
*/
