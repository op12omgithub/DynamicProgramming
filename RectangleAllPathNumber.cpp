#include<iostream>
#include<vector>

using namespace std;
void recursCountNoOfPath(int x,int y,int &res/*vector<int>&res*/,int targetX,int targetY)
{
    if(x==targetX && y==targetY){
        //res.push_back(1);
        res++;
        return;
    }
    else
    {
        if(x<targetX)
            recursCountNoOfPath(x+1,y,res,targetX,targetY);
        if(y<targetY)
            recursCountNoOfPath(x,y+1,res,targetX,targetY);
    }
}
int NumOfPath(int l,int w)
{
    int total = l+w-2;//(l-1+w-1)
    int row = w-1;//(l-1) or (w-1)
    int res=1;
    int div = 1;
    cout<<"l is "<<l<<"  w "<<w<<endl;
    for(int i=1;i<=row;i++){
        res=res*(total-row+i)/i;
    }

    cout<<"res "<<res<<endl;
    return res;

}

int main()
{
    int x = 10;
    int y =7;
    int result=0;
    //vector<int>result;
    int res = NumOfPath(x,y);
    cout<<"result is "<<res<<endl;
    recursCountNoOfPath(0,0,result,x-1,y-1);
    cout<<"recursive result "<<result/*.size()*/<<endl;
}
