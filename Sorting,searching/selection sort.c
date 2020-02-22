
#include <stdio.h>
#include<time.h>
int main()
{
int *p;
 int n,i=0,number,min,temp,j;
 clock_t start,end;
 double cpu_time_used;
 printf("enter the size");
 scanf("%d",&n);
 p=(int*)malloc(sizeof(int)*n);
 FILE *f= fopen("1000000.txt","r");
 while(fscanf(f,"%d",&number)==1)
 {p[i]=number;
 i++;}

fclose(f);

    start=clock();

      for (i = 0; i < n-1; i++)
    {

        min = i;
        for (j = i+1; j < n; j++)
          if (*(p+j) < *(p+min))
            min = j;
          temp=*(p+i);
          *(p+i) =* (p+min);
          *(p+min)=temp;

    }




    end=clock();
cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
printf("time=%f",cpu_time_used);



    return 0;
}




