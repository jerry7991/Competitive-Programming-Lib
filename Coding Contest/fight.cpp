#include <bits/stdc++.h>
using namespace std;
int answer(int **ans,int **arr,int i,int j,int r,int c)
{
    int number=0;
    if((i+1)>(r-1))
    {
         number=ans[i][j+1]-arr[i][j];
    }
    else if((j+1)>(c-1))
    {
        number=ans[i+1][j]-arr[i][j];
    }
    else
        number= min(ans[i+1][j]-arr[i][j],ans[i][j+1]-arr[i][j]);
    if(number<=1)
    {
        return 1;
    }
    else
    {
        return number;
    }
}
int main()
{
    int t;
    cin>>t;
    int r=0,c=0;
    while(t--)
    {
        cin>>r>>c;
        int **arr;
        arr = new int *[r];
        
        for(int i = 0; i <r; i++)
        {
            arr[i] = new int[c];
        }
      
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>arr[i][j];
                
            }
        }
         int** ans=new int*[r+1];
        for(int i=0;i<=r;i++)//yhn bhi
            ans[i]=new int[c+1];
        for(int i = 0 ; i <= r ; i++){
            for(int j = 0 ; j <= c ; j++){
                ans[i][j] = INT_MAX;
            }
        }//output aap r+1 * c+1 tk ka 
        ans[r][c-1]=1;
        ans[r-1][c]=1;
        
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(ans[i][j]==INT_MAX)
                {
                    ans[i][j]=answer(ans,arr,i,j,r,c);
                }
            }
    }
        cout<<ans[0][0]<<endl;
    }
    return 0;
}