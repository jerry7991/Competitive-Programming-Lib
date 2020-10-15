#include<iostream>
using namespace std;
int  getMaxMoney(int * arr,int n)
{
    int loot=0,house=0;
    while(house<n)
    {
        if(arr[house]>arr[house+1])
        {
            loot    +=arr[house];
            house   +=2;
        }else
        {
            loot    +=arr[house+1];
            house   +=3;
        }
    }
    return loot;
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n)<<endl;
   // cout<<"But this will take O(N^2) due to number of duplicate called in getMaxMoney function"<<endl;
}
