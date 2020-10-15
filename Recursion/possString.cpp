#include <bits/stdc++.h>
using namespace std;

int helper(int *arry,int k,int n,int x,int position){
    if(position==2*n){
        
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arry[k];
        for(int i=0;i<k;i++){
            cin>>arry[i];
        }
        cout<<helper(arry,k,n,0,1)<<endl;
    }
    return 0;
}
