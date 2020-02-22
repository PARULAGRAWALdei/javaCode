#include<stdio.h>
#include<time.h>
void main()
{
 int *p;
 int n,i=0,number,j,temp;
 clock_t start,end;
 double cpu_time_used;
 printf("enter the size");
 scanf("%d",&n);
 p=(int*)malloc(sizeof(int)*n);
 FILE *f= fopen("1000000.txt","r");
 while(fscanf(f,"%d",&number)==1)
 {*(p+i)=number;
 i++;}

fclose(f);
printf("file read");
start=clock();
for(i=0;i<n;i++)
    for(j=0;j<n-i-1;j++)
if(*(p+j)>*(p+j+1)){
    temp=*(p+j);
    *(p+j)=*(p+j+1);
    *(p+j+1)=temp;

}

end=clock();
cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
printf("time=%f",cpu_time_used);



}
