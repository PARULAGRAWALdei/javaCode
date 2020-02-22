
#include<stdio.h>
void knapSack(float W, float wt[], float val[], int n)
{
    float Val;
    int i,j;

 Val=0;
 int Wgt=W;
 i=0;
 while(wt[i]<=Wgt){
    Val = Val+ val[i];
         Wgt = Wgt- wt[i];
      i++;}





   printf("\nMaximum profit is:- %f", Val);



}



void main()
{

    int i,n,j;
    float W;
    float val[] = {92,57,49,68,43,60,67,84,87,72};
    float wt[] =  {23,31,29,44,38,54,63,85,89,82};
      W = 165;
     n =  sizeof(val)/sizeof(val[0]);
    float a[n];
    for(i=0;i<n;i++){
         a[i]=(val[i]/wt[i]);
    }
    float temp;

for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(a[i]<a[j]){
temp=a[j];
a[j]=a[i];
a[i]=temp;

temp=wt[j];
wt[j]=wt[i];
wt[i]=temp;

temp=val[j];
val[j]=val[i];
val[i]=temp;

}}}

 knapSack(W,wt,val,n);

}






