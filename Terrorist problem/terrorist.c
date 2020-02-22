#include<stdio.h>
#include<stdbool.h>
#define row 7
#define col 7

int issafe(int visited[row][col],int a[row][col],int i,int j){

return ((i<row)&&(j<col)&&a[i][j]&&!visited[i][j]);
}
void dfs(int visited[row][col],int a[row][col],int i,int j)
{

   int k;
   static int rowNbr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
   static int colNbr[] = {-1,  0,  1, -1, 1, -1, 0, 1};
   visited[i][j]=1;

   for(k=0;k<8;k++)
   {
       if(i+rowNbr[k]>=0 && j+colNbr[k]>=0)
   {
       if(issafe(visited,a,i+rowNbr[k],j+colNbr[k]))
           dfs(visited,a,i+rowNbr[k],j+colNbr[k]);
   }
   }

}
int countar(int a[row][col])
{

  int visited[row][col];
   int i,j,i1,j1,count=0;

  for(i=0;i<row;i++)
  {
      for(j=0;j<col;j++)
      {
       visited[i][j]=0;
      }
   }

    for(i=0;i<row;i++)
   {
       for(j=0;j<col;j++)
       {
           if( !visited[i][j] && a[i][j])
           {

               dfs(visited,a,i,j);

               count++;
           }
       }
   }
   return count;
}
void main()
{
   int i,j;
int a[row][col]={{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,0,0,1},{1,0,0,0,1,0,1},{1,1,0,0,0,1,1},{1,0,0,0,0,0,1}};
int count=countar(a);

  for(i=0;i<row;i++)
  {
      for(j=0;j<col;j++)
      {
       printf("%d\t",a[i][j]);
      }
      printf("\n");
   }

printf("%d",count);
}