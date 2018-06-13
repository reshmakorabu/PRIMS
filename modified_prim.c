/*Roll No:2015BCS026
  Roll No:2015BIT026*/


/*C program to implement Prim's algorithm which generates a minimum spanning tree of a weighted connected */

#include<stdio.h>
#define max 9999
#define size 100/*Defines maximum number of vertices of the input graph*/
#define True 1
#define False 0
void main()
{
    int a[size][size],i,j,n,vs,min_weight;/*vs:root*/
    int prim(int[][j],int,int);
    printf("\nEnter the number of vertex : ");
    scanf("%d",&n);
    printf("\nEnter a weighted matrix as input : ");

    //assign zero to all nodes

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
            printf(" ");
        }
        printf("\n");
    }

    //inputing value at proper position in upper triangular matrix
    printf("\nRemember you are inputing Upper Triangular Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    //copy data of upper triangular matrix in lower triangular matrix

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            a[i][j]=a[j][i];

        }
        printf("\n");
    }

    //printing i.e.output overall final matrix of size n * n

    printf("\n------Here is our graph-----\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
            printf(" ");
        }
        printf("\n");
    }


    printf("\nEnter starting vertex: v");
    scanf("%d",&vs);/*Read the starting vertex from user*/
    if(vs<0||vs>n-1)/*Checking validity of the starting vertex given by the user*/
    {

        printf("\n----Invalid vertex(not present in given nodes)-----");
        return;
    }
    printf("\nnSelected order of edges : ");
    min_weight=prim(a,n,vs); //call the prim function
    printf("\n");
    printf("\nTotal Weight of Minimum Spanning Tree: %d",min_weight);/*The total weight of the minimal spanning tree is displayed in the output*/

    return;
}
/*The input graph,number of vertices and the starting vertex are passed as parameters*/
int prim(int a[size][size],int n,int vs)
{
    int visit[size],nv,i,j,x,y,cost=0,min;
    for(i=0;i<n;i++)
    {
        visit[i]=False;/*Initially no vertices are selected*/
    }
   // for(i=0;i<n;i++)
    /*{
        for(j=0;j<n;j++)
            tree[i][j]=0;/*Initially spanning tree is empty}*/

    visit[vs]=True;/*Starting vertex is selected at first*/
    nv=1;
    while(nv<n)/*Iteration will be considered until all the vertices are selected*/
    {

        min=max;/*min is initialized by a large value*/
        for(i=0;i<n;i++)
        {
            if(visit[i]==True)/*Iteration will be considered iff i th vertex is already selected*/
            {
                for(j=0;j<n;j++)
                {
                    if(visit[j]==False)/*Iteration will be considered iff j th vertex is not already selected*/
                    {
                        if(a[i][j]!=0)/*Iteration will be considered iff there is a path between i th and j th vertex*/
                        {
                            if(min>a[i][j])/*Search for an edge with minimum weight*/
                            {
                                min=a[i][j];
                                x=i;
                                y=j;
                            }
                        }
                    }
                }
            }
        }
        cost=cost+min;/*Updation of previous cost by adding it to cost of newly selected edge*/
       // tree[x][y]=min;/*The newly selected edge is included in the minimal spanning tree*/
        visit[y]=True;
        nv++;
        printf("\n---------------------------------------------------------");
        printf("\n\tSOURCE\t\tDESTINATION\t\tWEIGHT       ");
        printf("\n---------------------------------------------------------");
        printf("\n\tv%d\t\tv%d\t\t\t%d",x,y,a[x][y]);
    }
   /* printf("\nb bb ");
    printf("\nn");*/
    /*printf("\nnThe spanning tree is(with weights) : n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%dt",tree[i][j]);
        printf("\nn");
    }*/



    return cost;
}




























/*Disadvantages of Prim’s algorithm:
	1.List of edges has to be searched from beginning as new edge gets added.
	2.If there are more than one edges having same weight then all possible spanning trees are required to be found for final minimal tree*/

/*the complexity of Prim’s algorithm for a graph having n vertices = O(n^2).*/
