include <stdio.h>
#include<time.h>
int main()
{
int *p;
 int n,i=0,number,min,temp,j,k;
 clock_t start,end;
 double cpu_time_used;
 printf("enter the size");
 scanf("%d",&n);
 p=(int*)malloc(sizeof(int)*n);
 FILE *f= fopen("100000.txt","r");
 while(fscanf(f,"%d",&number)==1)
 {p[i]=number;
 i++;}

fclose(f);

    start=clock();

      for (j=1;j< n;j++)
       {k=p[j];

       i=j-1;
  while(i>=0&&(p[i]>=k))
  {
      p[i+1]=p[i];
      i--;
      }
p[i+1]=k;
}




    end=clock();
cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
printf("time=%f",cpu_time_used);



    return 0;
}





