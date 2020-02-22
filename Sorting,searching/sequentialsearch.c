#include<stdio.h>
void main()
{
    int n,*ptr,a,i,b,number;

    ptr=(int*)malloc(n*sizeof(int));

    if(ptr==NULL)
    printf("memory allocated unsuccessful");

    FILE *f= fopen("100000000.txt","r");
 while((fscanf(f,"%d",&number)==1)&&i<n)
 {
     *(ptr+i)=number;
 i++;}

fclose(f);
printf("file read");


printf("enter the no to be search");
scanf("%d",&a);
for(i=0;i<=n-1;i++)
{
    if(a==*(ptr+i))
    b=1;
}
if(b==1)
    printf("no.is found",a);
else
    printf("no.is not found",a);
}


