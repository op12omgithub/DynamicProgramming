//#include "mainwindow.h"
#include<math.h>
#include<stdio.h>
#define NO_OF_VILL 6

//Floyd warshall algoritham is used
void distVillToVill(double villConnect[NO_OF_VILL][NO_OF_VILL])
{
    for(int k=0;k<NO_OF_VILL;k++)
        for(int i=0;i<NO_OF_VILL;i++)
            for(int j=0;j<NO_OF_VILL;j++)
            {
                if(villConnect[i][j]>(villConnect[i][k]+villConnect[k][j]))
                    villConnect[i][j] = villConnect[i][k]+villConnect[k][j];
            }

}
int main(int argc, char *argv[])
{
    printf("print no. of village %d\n",NO_OF_VILL);
    double villConnect[NO_OF_VILL][NO_OF_VILL]={{0,1.0,INFINITY,INFINITY,INFINITY,1.0},
                                                {1.0,0,1.0,1.0,INFINITY,1.0},
                                                {INFINITY,1.0,0,1.0,INFINITY,INFINITY},
                                                {INFINITY,1.0,1.0,0,1.0,INFINITY},
                                                {INFINITY,INFINITY,INFINITY,1.0,0,1.0},
                                                {1.0,1.0,INFINITY,INFINITY,1.0,0}
                                               };
    distVillToVill(villConnect);
    for(int i=0;i<NO_OF_VILL;i++){
        for(int j=0;j<NO_OF_VILL;j++)
        {
            printf("%.1f\t",villConnect[i][j]);
        }
        printf("\n");
    }


    return 0;//a.exec();
}
