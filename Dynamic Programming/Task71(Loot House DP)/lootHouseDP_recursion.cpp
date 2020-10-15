#include <iostream>
using namespace std;
int getMaxMoney(int *money , int len,int *output)
{
    if(len <=0)
    {
        return 0;
    }
    //check weather we have solved for this len or not................. Avoid duplicate recursive calls
    if(output[len]!=0)
    {
        return output[len];
    }
    //for each house thief has two choice either he can loot them and run to next house which is greater then 2 distance from one
    //or leave house and go for looting just next house
    int lootFirstHouse=money[0]+getMaxMoney(money+2 , len-2 ,output);   //can not loot consecutive house
    int leftFirstHouse=getMaxMoney(money+1 , len-1 , output);    //if thief didn't loot the first house then he has no money from first house
    output[len]=  max(lootFirstHouse , leftFirstHouse) ;  //once solved then store it for future use
    return output[len];
}
int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int *output=new int[n+1]();
    cout << getMaxMoney(arr, n ,output)<<endl;
    delete output;
    cout<<"This is much better than previous; It took O(2*N) time and space O(N) using dynamic programming and implementation with recursion we can do it in O(N).. For this look next code"<<endl;
}

