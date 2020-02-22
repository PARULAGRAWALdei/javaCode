#include <stdio.h>
#include<stdbool.h>

static int b;
void backtracking();
bool back();
int main() {

int i,j,n=4;
int a[n][n];
bool result;
for(i=0;i<n;i++)
{
   for(j=0;j<n;j++)
  {
      a[i][j]=0;
  }
}
b=n;
backtracking(a,n);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
 {
  printf("%d\t",a[i][j]);
  }
 printf("\n");
}
printf("%d",b);
}
bool back(int **a,int i,int n)
{
   int x,j;
   for(j=0;j<b;j++)
   {
  if(a[i][n]==0||a[i][n]!=2)
  {
           a[i][n]=1;
           for(x=0;x<b;x++)
           {
            a[i][x]=2;
            a[x][n]=2;
            a[i][n]=1;
           }
   return true;
  }
  }
  return false;
}
void backtracking(int **a,int n)
{
int i;
if(n==0)
{
return;
}
else if(n!=0)
{
for(i=0;i<b;i++)
{
if(back(a,i,n)==true)
break;
}
}
backtracking(a,n-1);
}