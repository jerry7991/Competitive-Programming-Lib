#include <iostream>
using namespace std;
int getMaxMoney(int *money , int len)
{
    if(len <=0)
    {
        return 0;
    }
    //for each house thief has two choice either he can loot them and run to next house which is greater then 2 distance from one
    //or leave house and go for looting just next house
    int lootFirstHouse=money[0]+getMaxMoney(money+2 , len-2);   //can not loot consecutive house
    int leftFirstHouse=getMaxMoney(money+1 , len-1);    //if thief didn't loot the first house then he has no money from first house
    return (   max(lootFirstHouse , leftFirstHouse) );  //return which is has  max money
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
    cout<<"But this will take O(N^2) due to number of duplicate called in getMaxMoney function"<<endl;
}

