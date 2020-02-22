#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int *arr,n,i,num;
void buildheap();
void sort();
void main()
{
  int number;
  clock_t start ;
srand(time(NULL));
  printf("\n Enter the number of elements\n");

   scanf("%d",&n);
arr=(int*)malloc(n*sizeof(int));
FILE *f= fopen("1000000000.txt","r");
 while((fscanf(f,"%d",&number)==1)&&i<n)
 {
     *(arr+i)=number;
 i++;}

fclose(f);
printf("file read");

    start=clock();
  buildheap();
 sort();
  //printf("\n Sorted elements are:\n");
  //for(i=1;i<=n;++i)
  //printf("%d\n",arr[i]);

  clock_t stop = clock();
    double elapsed = (double)(stop - start)  / CLOCKS_PER_SEC;
    printf("Time elapsed s: %f", elapsed);
    return 0;

}
void buildheap()

{

  int j,k,*temp;

  for(k=2;k<n;++k)

  {

    i=k;

    temp=arr[k];

    j=i/2;

    while((i>1)&&(temp>arr[j]))

    {

      arr[i]=arr[j];

      i=j;

      j=i/2;

      if(j<1)j=1;

    }

    arr[i]=temp;

  }

}



void sort()

{

  int *temp,*value,j,k;

   for(k=n;k>=2;--k)

       {

            temp=arr[1];

            arr[1]=arr[k];

            arr[k]=temp;

            i=1;

            value=arr[1];

            j=2;

            if ((j+1)<k)

            if(arr[j+1]>arr[j])

            j++;

           while((j<=(k-1))&&(arr[j]>value))

           {

             arr[i]=arr[j];

             i=j;

             j=2*i;

             if ((j+1)<k)

             if(arr[j+1]>arr[j])

             j++;

             else

               if(j>n)

               j=n;

               arr[i]=value;

           }

       }
}
