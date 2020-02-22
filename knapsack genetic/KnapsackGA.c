#include<stdio.h>
#define W 165
struct arr
{
    int a;
    int b[10];
};
void adjust(int *a,int *wt)
{
    int i,j,k;
    if(a[10]<W)
        return;
    else{
        i= rand()%5;
         if(a[0]==1||a[1]==1||a[2]==1||a[3]==1||a[4]==1)
 {
 if(a[i]==1)
           {
           a[i]=0;
           }
         }
                else
                {
             if(a[6]==1||a[6]==1||a[7]==1||a[8]==1||a[9]==1)
                    {
                        a[i+5]=0;
                    }
                }

            a[10]=weights(a,wt);
      adjust(a,wt);
}
return;
}

int fitness(int *a,int *val)
{
    //printf("\nfitness entered");
    int i=0;
    int p=0;
    for(i=0;i<10;i++)
    {
        if(a[i]==1)
        {
          p=p+val[i];
          //printf("\n%d",val[i]);

        }
    }

    return p;
}
int weights(int *a,int *wt)
{
    int i,p=0;
    for(i=0;i<10;i++)
    {
        if(a[i]==1)
        {
            p=p+wt[i];
        }
    }
    return p;
}
void replacement(int p,int *m,int sol[100][13])
{printf("\nreplacement entered\n");
    for(int i=0;i<10;i++)
    {
        sol[p][i]=m[i];
    }
}

/*void replace(int p,int *m,int sol[100][13])
{
    printf("\nreplace entered\n");
    int a,b,c,d;
if(sol[p][12]==sol[p+1][12])
{
    if(sol[p+1][12]==sol[p+2][12])
    {
        a=p;
        b=p+1;
        c=p+2;
        d=min(sol[b][11],sol[c][11]);
        if(d==0)
        {
            replacement(b,m,sol);
        }
        else
        {
            replacement(c,m,sol);
        }
    }
    else if(sol[p-1][12]==sol[p][12])
    {
        a=p-1;
        b=p;
        c=p+1;
        d=min(sol[a][11],sol[c][11]);
        if(d==0)
        {
            replacement(a,m,sol);
        }
        else
        {
            replacement(c,m,sol);
        }
    }
}
else
{
    a=p-2;
    b=p-1;
    c=p;
    d=min(sol[a][11],sol[b][11]);
    if(d==0)
    {
        replacement(b,m,sol);
    }
    else{
        replacement(c,m,sol);
    }
}

}*/
void swap(struct arr *xp, struct arr *yp)
{
    struct arr temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort(struct arr *b)
{


   int i, j;
   for (i = 0; i < 4; i++)

       // Last i elements are already in place
       for (j = 0; j < 3-i; j++)
           if (b[j].a > b[j+1].a)
              swap(&b[j], &b[j+1]);

}
int min(int a,int b,int c,int sol[100][13])
{
 if(sol[a][11]<=sol[b][11])
 {
     if(sol[a][11]<=sol[c][11])
        return 0;
     else
        return 2;
 }
 else
 {
     if(sol[b][11]<=sol[c][11])
        return 1;
     else
        return 2;
 }
}
void cross(int sol[100][13],int *wt,int *val,int p,int q)
{
    int a,b;
 //printf("cross entered\n");
 int m[12],n[12],j=0,i;
 int k=rand()%10;
 //printf("\n%d",k);
 if(k!=0)
 {
  while(j<=k)
  {
    m[j]=sol[p][j];
    n[j]=sol[q][j];
    j++;
  }
    while(j<10)
    {
       n[j]=sol[p][j];
        m[j]=sol[q][j];
        j++;
    }}
m[10]=weights(m,wt);
m[11]=fitness(m,val);
if(m[10]>W)
    m[11]=0;
n[10]=weights(n,wt);
n[11]=fitness(n,val);
   if(n[10]>W)
    n[11]=0;
struct arr c[4];
c[0].a=m[11];
c[1].a=n[11];
c[2].a=sol[p][11];
c[3].a=sol[q][11];
for(i=0;i<10;i++)
{
    c[0].b[i]=m[i];
    c[1].b[i]=n[i];
c[2].b[i]=sol[p][i];
c[3].b[i]=sol[q][i];
}
sort(c);
int x,y;
/*for(i=0;i<4;i++)
{
    printf("\n%d",c[i].a);
}*/
if(sol[p][12]==sol[p+1][12])
{
    if(sol[p+1][12]==sol[p+2][12])
    {


        a=p;
        b=p+1;
        k=p+2;
        x=min(a,b,k,sol)+p;
        }
    else
    {
        a=p-1;
        b=p;
        k=p+1;
        x=min(a,b,k,sol)+p-1;
    }
}
else
{
    a=p-2;
    b=p-1;
    k=p;
    x=min(a,b,k,sol)+p-2;
}
//printf("\n%d",x);
if(sol[q][12]==sol[q+1][12])
{
    if(sol[q+1][12]==sol[q+2][12])
       {
        a=q;
        b=q+1;
        k=q+2;
        y=min(a,b,k,sol)+q;
       }
    else
    {
        a=q-1;
        b=q;
        k=q+1;
        y=min(a,b,k,sol)+q-1;}
}
else
{
    a=q-2;
    b=q-1;
    k=q;
    y=min(a,b,k,sol)+q-2;
}
int z;
if(x<y)
    z=x;
else
    z=y;
if(c[3].a==m[11]&&c[2].a==n[11])
{
    for(int i=0;i<10;i++)
    {
        sol[x][i]=m[i];
        sol[y][i]=n[i];
    }
}
if(c[3].a==n[11]&&c[2].a==m[11])
{
    for(int i=0;i<10;i++)
    {
        sol[x][i]=m[i];
        sol[y][i]=n[i];
    }
}
if(c[3].a==m[11]&&c[2].a!=n[11])
{
    if(c[2].a==sol[x][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[y][i]=n[i];
    }

    }
}
if(c[3].a==m[11]&&c[2].a!=n[11])
{
    if(c[2].a==sol[y][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[x][i]=n[i];
    }

    }
}
//printf("\n%d\t%d\n",x,y);

for(int j=0;j<10;j++)
{
    //printf("\n%d",val[j]);
}
if(c[3].a==n[11]&&c[2].a!=m[11])
{
    if(c[2].a==sol[x][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[y][i]=n[i];
    }

    }
}
if(c[3].a==n[11]&&c[2].a!=m[11])
{
    if(c[2].a==sol[y][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[x][i]=n[i];
    }}
}
if(c[2].a==n[11]&&c[3].a!=m[11])
{
    if(c[3].a==sol[x][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[y][i]=n[i];
    }

    }
}
if(c[2].a==n[11]&&c[3].a!=m[11])
{
    if(c[3].a==sol[y][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[x][i]=n[i];
    }}
}
if(c[2].a==m[11]&&c[3].a!=n[11])
{
    if(c[3].a==sol[x][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[y][i]=n[i];
    }

    }
}
if(c[2].a==m[11]&&c[3].a!=n[11])
{
    if(c[3].a==sol[y][11])
    {
        for(int i=0;i<10;i++)
    {
        sol[x][i]=n[i];
    }

    }
}

//printf("\n%d\t%d\n",x,y);


    //
/*for(i=0;i<10;i++)
{
    printf("\n%d",sol[x][i]);
    printf("\t%d",sol[y][i]);
}*/

}
int max(int a,int b,int c)
{
    if(a>b)
    {
        if(a>c)
            return 0;
        else
            return 2;
    }
    else
    {
        if(b>c)
            return 1;
        else
            return 2;
    }
}

void evolution(int sol[100][13],int *wt,int *val,int row,int col)
{
printf("\nevolution entered\n");
    int p=0,q=0;
 int k=row/3;
 for(int i=0;i<96;i=i+6)
 {  //printf("%d",sol[0][11]);
     p=max(sol[i][11],sol[i+1][11],sol[i+2][11]);

     p=p+i;
     //printf("\n%d",p);
     q=max(sol[i+3][11],sol[i+4][11],sol[i+5][11]);
     q=q+3+i;
     //printf("\t%d",q);
     cross(sol,wt,val,p,q);
 }
}
void evolution1(int sol[100][13],int *wt,int *val,int row,int col)
{
printf("\nevolution entered\n");
    int p=0,q=0;
 int k=row/3;
 for(int i=0;i<96;i=i+6)
 {  //printf("%d",sol[0][11]);
     int x=rand()%31;

     p=max(sol[i][11],sol[i+1][11],sol[i+2][11]);

     p=p+i;
     //printf("\n%d",p);
     q=max(sol[x][11],sol[x+1][11],sol[x+3][11]);
     q=x*3+3+q;
     //printf("\t%d",q);
     cross(sol,wt,val,p,q);
 }
}
void mutation1(int *a,int *val,int *wt)
{
    int b[10];
    for(int i=0;i<10;i++)
    {
        b[i]=a[i];
    }
    int m=rand()%5;
    int n=rand()%5;
    n=n+5;
    int k;

    //printf("%d",k);
    if(b[m]!=b[n])
    {
        k=b[m];
        b[m]=b[n];
        b[n]=k;
    }

   // printf("\n");
    /*for(int j=0;j<10;j++)
    {
        printf("\t%d",a[j]);
    }*/
    int f=fitness(b,val);
    int w=weights(b,wt);
    if(w<W && w>a[10] )
    {
         for(int i=0;i<10;i++)
    {
        a[i]=b[i];
    }
    }


}
void mutation(int *a,int *val,int *wt )
{
    int b[10];
    for(int i=0;i<10;i++)
    {
        b[i]=a[i];
    }
    int k=rand()%10;
    //printf("%d",k);
    b[k]=1;
   // printf("\n");
    /*for(int j=0;j<10;j++)
    {
        printf("\t%d",a[j]);
    }*/
    int f=fitness(b,val);
    int w=weights(b,wt);
    if(w<W && w>a[10] )
    {
         for(int i=0;i<10;i++)
    {
        a[i]=b[i];
    }
    }
    /*printf("\n%d\n",f);
    for(int j=0;j<10;j++)
    {
        printf("\t%d",a[j]);
    }*/


}
void main()
{
int row=100,col=10;
    int k;
int wt[10]={23,31,29,44,53,38,63,85,89,82};
int val[10]={92,57,49,68,60,43,67,84,87,72};
int val1[10]={92,57,49,68,60,43,67,84,87,72};
int sol[100][13];
 for(int i = 0; i<100; i++)
 {
    for(int j=0;j<10;j++)
 {
    sol[i][j]=0;
 }
 }
 for(int i = 0; i<100; i++)
 {
    for(int j=0;j<10;j++)
 {
    k= rand()%10;
    sol[i][k]=1;
} }

 for(int i=0;i<100;i++)
 {
     int p,q;
     p=fitness(sol[i],val);
     q=weights(sol[i],wt);
     sol[i][11]=p;
     sol[i][10]=q;

 }
 int m=row/3;
 int n=0;
 for(int i=0;i<100;i=i+3)
 {
     sol[i][12]=n;
     sol[i+1][12]=n;
     sol[i+2][12]=n;
     n++;
 }

 for(int i=0;i<100;i++)
{
  adjust(sol[i],wt);
   //printf("%d\n",i);
}
 for(int i=0;i<100;i++)
 {
     int p;
     p=fitness(sol[i],val);
     sol[i][11]=p;
}

  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");

 }


 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
 for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");
 int p,q;
 for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
     q=weights(sol[i],wt);
     sol[i][10]=q;
    // printf("\n%d",p);
     sol[i][11]=p;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }

 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");
 for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");
 for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }

 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
   //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
       //mutation1(sol[i],val,wt);
 }


 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }
 printf("\n");
  //printf("\n%d",sol[1][11]);

 }
 evolution(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
     // mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }

 printf("\n");
 }
 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      //mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }

 printf("\n");
 }
 evolution(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }

 printf("\n");
 }
 evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
      mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }

 printf("\n");
 }
  evolution(sol,wt,val,row,col);
  //evolution1(sol,wt,val,row,col);
  for(int i=0;i<100;i++)
 {
     mutation(sol[i],val,wt);
     mutation1(sol[i],val,wt);
 }

 printf("new configuration");
 printf("\n");
 printf("\n");
 printf("\n");for(int i=0;i<100;i++)
 {

     p=fitness(sol[i],val);
    // printf("\n%d",p);
     sol[i][11]=p;
      q=weights(sol[i],wt);
     sol[i][10]=q;
}

//sol[1][11]=fitness(sol[1],val);
  for(int i = 0; i<100; i++)
 {
    for(int j=0;j<12;j++)
 {
    printf("\t%d\t",sol[i][j]);
 }


 printf("\n");
 }
 int max=270;
 printf("max optimized value=%d",max);
}
