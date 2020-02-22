import java.util.*;
class Prim
{static double a[][],b[][];
public static void main(String[] args)
{Scanner sc=new Scanner(System.in);
int n,i,j;
n=sc.nextInt();
 a=new double[n][2];
i=0;
while(sc.hasNext())
{a[i][0]=sc.nextDouble();
a[i][1]=sc.nextDouble();
i++;
}
b=new double[n][n];
for(i=0;i<n;i++)
{for(j=0;j<n;j++)
{b[i][j]=Math.sqrt(Math.pow(a[i][0]-a[j][0],2)+Math.pow(a[i][1]-a[j][1],2));
}
}
Prim ob= new Prim();
ob.primMST(b,n);
}
 void printMST(int parent[], int n, double graph[][])
    {
        System.out.println("Edge   Weight");
        for (int i = 1; i < n; i++)
            System.out.println(parent[i]+" - "+ i+"    "+
                               graph[i][parent[i]]);
    }
 
int minKey(double key[], Boolean mstSet[], int n)
    {
        
        double min = Double.MAX_VALUE;
int min_index=-1;
 
        for (int v = 0; v < n; v++)
            if (mstSet[v] == false && key[v] < min)
            {
                min = key[v];
                min_index = v;
            }
 
        return min_index;
    }
    
    void primMST(double graph[][], int n)
    {
        
        int parent[] = new int[n];
 double key[] = new double [n];
 Boolean mstSet[] = new Boolean[n];
         for (int i = 0; i < n; i++)
        {
            key[i] = Double.MAX_VALUE;
            mstSet[i] = false;
        }
 
        key[0] = 0.0;   
        parent[0] = -1;
        
        for (int count = 0; count < n-1; count++)
        {
         int u = minKey(key, mstSet, n);
       mstSet[u] = true;
            for (int v = 0; v < n; v++)
                if (graph[u][v]!=0 && mstSet[v] == false &&
                    graph[u][v] <  key[v])
                {
                    parent[v]  = u;
                    key[v] = graph[u][v];
                }
        }
        printMST(parent, n, graph);
    }}

