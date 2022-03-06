//#include "mainwindow.h"
#include<stdio.h>
#include<math.h>
#define NO_OF_VILL 5
#define INF 65635


void distVillToVill(int villConn[NO_OF_VILL][NO_OF_VILL],int startVill)
{

    int dist_matrix[NO_OF_VILL][NO_OF_VILL],distance[NO_OF_VILL],pred[NO_OF_VILL];
    int visited[NO_OF_VILL],count,mindist,nextVill,i,j;

    for(i=0;i<NO_OF_VILL;i++)
        for(j=0;j<NO_OF_VILL;j++)
            if(villConn[i][j]==0)
                dist_matrix[i][j]=INF;
            else
                dist_matrix[i][j]=villConn[i][j];
    //initialize pred[],distance[] and visited[]
    for(i=0;i<NO_OF_VILL;i++)
    {
        distance[i]=dist_matrix[startVill][i];
        pred[i]=startVill;
        visited[i]=0;
    }
    distance[startVill]=0;
    visited[startVill]=1;
    count=1;
    while(count<NO_OF_VILL-1)
    {
        mindist=INF;
        //nextVill villConnives the node at minimum distance
        for(i=0;i<NO_OF_VILL;i++)
            if(distance[i]<mindist&&!visited[i])
            {
                mindist=distance[i];
                nextVill=i;
            }
        //check if a better path exists throuvillConnh nextVill
        visited[nextVill]=1;
        for(i=0;i<NO_OF_VILL;i++)
            if(!visited[i])
                if(mindist+dist_matrix[nextVill][i]<distance[i])
                {
                    distance[i]=mindist+dist_matrix[nextVill][i];
                    pred[i]=nextVill;
                }
        count++;
    }

    //print the path and distance of each village
    for(i=0;i<NO_OF_VILL;i++)
        if(i!=startVill)
        {
            printf("\nDistance from source village%d to Village%d=%d",startVill,i,distance[i]);
            printf("\nPath=%d",i);
            j=i;
            do
            {
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startVill);
        }
}


int main(int argc, char *argv[])
{
    printf("print no. of village %d\n",NO_OF_VILL);
    int villConnect[NO_OF_VILL][NO_OF_VILL]={{0,35,40,INF,INF},
                                             {35,0,25,10,INF},
                                             {40,25,0,20,15},
                                             {INF,10,20,0,30},
                                             {INF,INF,15,30,0}
                                            };
                                
       printf("input matrix is::\n");            
       for(int i=0;i<NO_OF_VILL;i++)
       {
         for(int j=0;j<NO_OF_VILL;j++)
         {
         if(villConnect[i][j]==INF)
         printf("%f\t",INFINITY);
         else
         printf("%d\t",villConnect[i][j]);
         }
         printf("\n");
       }
    distVillToVill(villConnect,0); //0 is the source village
    printf("\n");

    return 0;
}
