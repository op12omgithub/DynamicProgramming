#include<iostream>
#include<vector>
#include<math.h>

using namespace std;
void permuteNum(int indx,int size,vector<int>&set,vector<vector<int>>&res,int *a)
{
  if(indx==size)
  {
    res.push_back(set);
    return;
  }
  else{
      set.push_back(a[indx]);
      permuteNum(indx+1,size,set,res,a);
      set.pop_back();
      permuteNum(indx+1,size,set,res,a);
  }

}
void BitwisePermute(int size,int* arr)
{
    int totalSize = 1<<size;
    int numOfBits = log2(totalSize);
    int count=0;
    //cout<<"number of bits "<<numOfBits<<endl;
    for(int i=1;i<=totalSize;i++){
        for(int k=0;k<numOfBits;k++){
            if(i&(1<<k)){
                cout<<arr[k]<<" ";
            }
        }
        count++;
        cout<<endl;
    }
}

int main()
{
    int arr[]={1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>set;
    vector<vector<int>>result;
    permuteNum(0,size,set,result,arr);
    int resSize = result.size();
    for(int i=0;i<resSize;i++){
        for(auto it:result[i]){
                cout<<it<<" ";

        }
        cout<<endl;
    }

    cout<<"Print using Bitwise operator"<<endl;
    BitwisePermute(size,arr);
    return 0;
}
