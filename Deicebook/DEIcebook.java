import java.util.*;

import java.io.*;


public class DEIcebook{
	public static void main (String []args)throws IOException
{
File f=new File ("3.txt");
Scanner sc=new Scanner (f);
int x=sc.nextInt();
int a []=new int [x];
for(int i=0;i<x;i++)
a[i]=i;
while (sc.hasNext ())
{int b=sc.nextInt ();
int c=sc.nextInt ();
if (a[b]==b &&a[c]==c)
{for (int j=0;j<x;j++)
 {if (a[j]==a[b])
a[j]=a[c];}}
else if (a[b]==b&& a[c]!=c)
//a[b]=c;
{for (int j=0;j<x;j++)
 {if (a[j]==a[b])
a[j]=a[c];}}
else if (a[b]!=b&& a[c]==c)
//a[c]=b;
{for (int j=0;j<x;j++)
 {if (a[j]==a[b])
a[j]=a[c];}}
else if (a[b]!=b&& a[c]!=c&&b!=c)
{for (int j=0;j<x;j++)
 {if (a[j]==a[b])
a[j]=a[c];}}
}
int b=15;
int c=16;
if (a[b]==a[c])
System.out.println ("yes");
else 
System.out.println ("No");
}
}
